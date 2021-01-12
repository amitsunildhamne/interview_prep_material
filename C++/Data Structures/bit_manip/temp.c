#include <stdio.h>
#include <stdint.h>

uint32_t InsertPattern(uint32_t val, uint32_t lo, uint32_t hi, uint32_t pattern)
{
	uint32_t  limit = hi - lo + 1;
	uint32_t mask = ((1<<limit) - 1)<<lo;
	printf("limit:%u 0x%x\n",limit,  mask);
	if ((hi>31) || (lo>31)) {
		return val;
	}

	return (val & ~mask) | (pattern<<lo & mask);
}

uint32_t ReverseBits(uint32_t val)
{
	uint32_t ret_val=0;
	
	while(val != 0) {
		ret_val <<= 1;
		ret_val |= val & 0x1;
		val >>= 1;
	}

	return ret_val;
}

int main(void)
{
	uint32_t val = 0xff00;
	uint32_t ret_val;

	ret_val = ReverseBits(val);
	printf("Val:0x%x RetVal:0x%x\n", val, ret_val);

	val = 0x12345;
	printf("Val:0x%x RetVal:0x%x\n", val, InsertPattern(val, 4, 7, 0xf));
	return 0;
}
