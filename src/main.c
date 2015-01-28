#include <stdio.h>

#include "adler-32.h"

int main()
{
	printf("%d\n", adler_32("Adler-32", 8));
	return 0;
}
