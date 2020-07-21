#include <stdio.h>

void check_endian(int a)
{
	char *x = (char *) &a;
	for(int i = 0; i < sizeof(int)/sizeof(char); ++i)
	{
		printf("%x\n", *(x+i));
	}
}

int main()
{
	unsigned int a = 0x01234567;
	check_endian(a);
	return 0;
}
