#include <stdint.h>

#define ADLER_CONSTANT 65521

uint32_t adler_32(uint8_t *data, int len)
{
	int a = 1;
	int b = 0;

	while(len--) {
		a = (a + *(data++)) % ADLER_CONSTANT;
		b = (b + a) % ADLER_CONSTANT;
	}

	return (b << 16) | a;
}
