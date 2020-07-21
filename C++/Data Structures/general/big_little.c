/* Code to check Big or Little Endian Big Endian:2 Little Endian:1*/

#include <stdio.h>
#include <stdint.h>

int CheckEndian(uint32_t val)
{
	char *ptr =(char *)&val;
	if(*ptr = 0x1)
		return 1;
	else
		return 2;
}

int main(void)
{
	uint32_t val = 0x1;
	printf("Endian: 0x%d\n", CheckEndian(val));
	return 0;
}
