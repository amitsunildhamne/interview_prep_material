#include <stdio.h>
#include <stdint.h>

uint32_t Reverse(uint32_t x)
{
	uint32_t y = 0;
	while(x>0) {
		y <<= 1;
		y |= x&1;
		x>>=1;
	}
	return y;
}

int main()
{
	uint32_t x = 6;
	printf("%u\n",Reverse(x));
	return 0;
}
