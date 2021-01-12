#include <stdio.h>

int add(int a, int b)
{
	int c = 2;
	c += a + b;
	printf("Crel\n");
	return c;
}

int main(void)
{
	int i;

	for (i = 0; i < 5; ++i) {
		volatile int x = 0;
		volatile long long yy = 100;
		volatile long long z = 10000;
		printf("Hello World %d %d\n", add(x, i), yy+z );
	}

	return 0;
}
