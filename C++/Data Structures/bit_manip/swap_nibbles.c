#include <stdio.h>
#include <stdint.h>

uint8_t swap_nibbles(uint8_t i)
{
	return i<<4 | i>>4;
}

uint32_t SwapNibbles(uint32_t x)
{
	return ((x & 0xffff0000)>>16) | ((x & 0xffff) << 16);
}

int main()
{
	uint8_t i = 0x12;
	uint32_t x = 0x12345678;
	printf("%x\n",swap_nibbles(i));
	printf("0x%x\n", SwapNibbles(x));
	return 0;
}

// 0 1 2 3
// FF000000 >> 
