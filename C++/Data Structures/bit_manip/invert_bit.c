#include <stdio.h>
#include <stdint.h>

uint32_t InvertBits(uint32_t val, uint32_t lo, uint32_t hi)
{
	uint32_t len = hi - lo + 1;
	uint32_t mask = (1<<len) - 1;
	return val^(mask<<lo);
}

int main(void)
{
	uint32_t val = 0x12345;
	uint32_t lo = 4;
	uint32_t hi = 7;
	uint32_t ret;

	ret = InvertBits(val, lo, hi);
	printf("val:0x%x ret:0x%x\n", val, ret);
	return 0;
}
