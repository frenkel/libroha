#include <stdint.h>

#include "adler-32.h"

#define ADLER_CONSTANT 65521

void adler_32_init(adler_32_state *state)
{
	state->a = 1;
	state->b = 0;
}

uint32_t adler_32(adler_32_state *state, uint8_t data)
{
	state->a += data;

	if (state->a > ADLER_CONSTANT)
		state->a -= ADLER_CONSTANT;

	state->b += state->a;

	if (state->b > ADLER_CONSTANT)
		state->b -= ADLER_CONSTANT;

	return (state->b << 16) | state->a;
}
