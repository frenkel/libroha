#include <stdint.h>

uint32_t adler_32(uint8_t *data, int len)
{
	int a = 1;
	int b = 0;

	while(len--) {
		a += *(data++);
		b = b + a;
	}

	return (b << 16) | a;
}
