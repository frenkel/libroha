#include <assert.h>
#include "../src/adler-32.h"

void test_single_char()
{
	adler_32_state state;
	adler_32_init(&state);
	assert(adler_32(&state, (uint8_t) 'a') == 6422626);
}

void test_simple_word()
{
	adler_32_state state;
	uint8_t *input = (uint8_t *) "Adler-32";
	int i = 0;
	uint32_t checksum = 0;

	adler_32_init(&state);

	for (i = 0; i < 8; i++)
		checksum = adler_32(&state, input[i]);

	assert(checksum == 0x0c34027b);
}

void test_modulo()
{
	adler_32_state state;
	uint8_t *input = (uint8_t *)
		 "pretty long Adler-32 modulo testing string";
	int i = 0;
	uint32_t checksum = 0;

	adler_32_init(&state);

	for (i = 0; i < 42; i++)
		checksum = adler_32(&state, input[i]);

	assert(checksum == 0x4bc00f98);
}

int main()
{
	test_single_char();

	test_simple_word();

	test_modulo();

	return 0;
}
