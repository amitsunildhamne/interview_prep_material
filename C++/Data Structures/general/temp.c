/* My Sizeof */
#include <stdio.h>
#include <stdint.h>

int main(void)
{
	int x = 0;
	printf("val:%d\n",(int)((char *)(&x+1)- (char *)&x));
	return 0;
}
