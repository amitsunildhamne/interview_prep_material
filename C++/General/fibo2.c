#include <stdio.h>

long long int fib(int n)
{
	if ( n == 0 || n == 1)
	{
		return n;
	}
	return fib(n-1) + fib(n-2);
}

int main()
{
	int n = 50 ;
	printf("%lld\t", fib(n));
	printf("\n");
	return 0;
}