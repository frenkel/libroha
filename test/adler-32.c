#include <assert.h>
#include "../src/adler-32.h"

int main()
{
	assert(adler_32((uint8_t *) "a", 1) == 6422626);

	assert(adler_32((uint8_t *) "Adler-32", 8) == 0x0c34027b);

	uint8_t *modulo = "pretty long Adler-32 modulo testing string";

	assert(adler_32(modulo, 42) == 0x4bc00f98);

	return 0;
}
