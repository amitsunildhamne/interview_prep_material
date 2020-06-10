#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t MaskGenerator(uint32_t high, uint32_t low)
{
	uint32_t ret_val = 0;
	for(uint32_t i = low; i <= high; ++i) {
		ret_val <<= 1;
		ret_val |= 0x1;
	}

	return ret_val<<low;
}

uint32_t CreatePattern(uint32_t number, uint32_t pattern, uint32_t high, uint32_t low)
{
	uint32_t ret_val = 0;
	uint32_t mask = MaskGenerator(high, low);
	printf("Mask: 0x%x\n", mask);
	return ((number & ~mask) | (pattern & mask));
}

int main(void)
{
	uint32_t pattern = 0x23;
	uint32_t number = 0x12675;
	uint32_t high = 7, low = 4;

	printf("Original no.:0x%x. pattern: 0x%x, high=%u, low=%u, Result0x%x\n",
			number, pattern, high, low, CreatePattern(number, pattern,high, low ));
	return 0;
}
