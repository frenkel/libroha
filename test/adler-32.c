#include <assert.h>
#include "../src/adler-32.h"

int main()
{
	assert(adler_32("a", 1) == 6422626);

	return 0;
}
