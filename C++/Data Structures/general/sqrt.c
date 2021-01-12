#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t my_sqrt(const int a)
{
	uint32_t ret = 0;
	int hi = a;
	int lo = 0;
	int mid = 0;
	uint64_t sqr = 0;

	if (a <= 0) {
		goto done;
	}

	while(hi >= lo) {
		mid = (hi + lo)/2;
		sqr = mid*mid;
		if(a == sqr) {
			goto done;
		} else if (a < sqr) {
			hi = mid-1;
		} else {
			lo = mid+1;
		}
	}

	mid = hi;
done:
	return mid;
}

int main(void)
{
	printf("a:%u\tsqrt(%u):%u\n", 4, 4, my_sqrt(4));
	printf("a:%u\tsqrt(%u):%u\n", 5, 5, my_sqrt(5));
	printf("a:%u\tsqrt(%u):%u\n", 8, 8, my_sqrt(8));
	printf("a:%u\tsqrt(%u):%u\n", 16, 16, my_sqrt(16));
	printf("a:%u\tsqrt(%u):%u\n", 0, 0, my_sqrt(0));
	printf("a:%u\tsqrt(%u):%u\n", -16, -16, my_sqrt(-16));

	return 0;
}
