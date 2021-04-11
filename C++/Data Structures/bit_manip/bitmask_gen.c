#include <stdio.h>
#include <stdint.h>

#define BITMASK(n)			((uint32_t)(1U<<n) - 1U)
#define BITNMASK(offset, width)			(BITMASK(width)<<(offset))

int main(void)
{

	uint32_t n = 5;
	uint32_t offset = 6;

	printf("BITMASK: 1<<%u = 0x%x\n", n, BITMASK(n));
	printf("BITNMASK(%d, %d): 0x%x\n", n, offset, BITNMASK(offset,n));
	return 0;
}
