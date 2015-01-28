#include <stdint.h>

#ifndef ADLER_32
#define ADLER_32

typedef struct {
	uint32_t a;
	uint32_t b;
	uint32_t checksum;
	uint8_t last;
} adler_32_state;

void adler_32_init(adler_32_state *);
uint32_t adler_32(adler_32_state *, uint8_t);

#endif
