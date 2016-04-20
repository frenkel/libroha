#include <stdint.h>
#include <string.h>

#include "adler-32.h"

#define ADLER_CONSTANT 65521

void adler_32_init(adler_32_state *state, uint32_t blocksize)
{
	state->a = 1;
	state->b = 0;
	state->blocksize = blocksize;
	state->buffer = malloc(blocksize);
	memset(state->buffer, 0, blocksize);
}

void adler_32_deinit(adler_32_state *state)
{
	if(state->buffer != NULL)
		free(state->buffer);
}

static uint8_t unshift_append(adler_32_state *state, uint8_t appended)
{
	uint8_t unshifted = state->buffer[0];
	int i;

	for(i = 0; i < state->blocksize - 1; i++)
		state->buffer[i] = state->buffer[i + 1];

	state->buffer[state->blocksize] = appended;

	return unshifted;
}

uint32_t adler_32(adler_32_state *state, uint8_t data)
{
	uint8_t prev = unshift_append(state, data);

	state->a += data;

	if (state->a > ADLER_CONSTANT)
		state->a -= ADLER_CONSTANT;

	state->b += state->a;

	if (state->b > ADLER_CONSTANT)
		state->b -= ADLER_CONSTANT;

	return (state->b << 16) | state->a;
}
