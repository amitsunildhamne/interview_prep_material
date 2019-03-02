#include <stdio.h>
#include <stdint.h>
int8_t swap_nibbles(uint8_t i)
{
	return i<<4 | i>>4;
}

int main()
{
	uint8_t i = 0x12;
	printf("%x\n",swap_nibbles(i));
	return 0;
}

// 0 1 2 3
// FF000000 >> 