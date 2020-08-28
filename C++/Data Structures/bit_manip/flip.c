/**
 * C program to count flip all bits of a binary number using bitwise operator
 */
#include <stdio.h>

int main()
{
	unsigned int x = 0xffff0000, y = 0x0;
	int i = 31;

	while (i >= 0) {
		y <<=1;
		y += (x >> i) & 1;
		++i;
	}
	printf("Original no.: 0x%x. New no.: 0x%x\n", x, y);
    return 0;
}
