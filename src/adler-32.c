#include <stdint.h>

#include "adler-32.h"

#define ADLER_CONSTANT 65521

void adler_32_init(adler_32_state *state)
{
	state->a = 1;
	state->b = 0;
	state->checksum = 0;
	state->last = 0;
}

uint32_t adler_32(adler_32_state *state, uint8_t data)
{
	state->a = (state->a + data) % ADLER_CONSTANT;
	state->b = (state->b + state->a) % ADLER_CONSTANT;

	state->checksum = (state->b << 16) | state->a;
	state->last = data;

	return state->checksum;
}
