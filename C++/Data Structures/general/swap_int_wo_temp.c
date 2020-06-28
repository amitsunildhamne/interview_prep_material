#include <stdio.h>

void Swap(float *a, float *b)
{
	*a = *a + *b;
	*b = (*a - *b) - *b;
	*b = (*a + *b)/2.0;
	*a = *a - *b;
}

int main()
{
	float a = 1000.6;
	float b = 1500.4;
	printf("Original: a=%f b=%f\n", a, b);
	Swap(&a,&b);
	printf("New: a=%f b=%f\n", a, b);
	return 0;
}
