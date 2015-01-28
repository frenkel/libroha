#include <stdio.h>

#include "adler-32.h"

int main()
{
	adler_32_state state;
	int i = 0;
	uint8_t *string = "Adler-32";

	adler_32_init(&state);

	for (i = 0; i < 8; i++)
		adler_32(&state, string[i]);

	printf("%d\n", state.checksum);

	return 0;
}
