/* Swap bits indicated by bit positions */
#include <stdio.h>
#include <stdint.h>

uint32_t swap_bits(uint8_t pos1, uint8_t pos2, uint32_t val)
{
	uint32_t ret_val=0;
	uint32_t mask1 = 0;
	uint32_t mask2 = 0;
	uint32_t v1=0, v2=0;

	if (pos1>31) {
		ret_val = val;
		goto done;
	}

	mask1 = 1<<pos1;
	mask2 = 1<<pos2;
	v1 = (val & mask1)>>pos1;
	v2 = (val & mask2)>>pos2;
	val = (val & ~mask1 & ~mask2);
	val |= v1<<pos2 | v2<<pos1;
	ret_val = val;
done:
	return ret_val;
}

int main(void)
{
	uint8_t pos1 = 12;
	uint8_t pos2 = 16;
	uint32_t val = 0x12345678;

	printf("val:0x%x  new_val:0x%x\n", val, swap_bits(pos1, pos2, val));
	return 0;
}
