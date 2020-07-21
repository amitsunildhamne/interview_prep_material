#include <stdio.h>

int main()
{
	long long int a[10]={0};
	printf("%d\n", (char *)(a+1) - (char *)(a));
}