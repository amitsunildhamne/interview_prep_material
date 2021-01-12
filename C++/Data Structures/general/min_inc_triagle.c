#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define SIDES				3

int FindMaxIdxVal(uint32_t *Arr, int Size)
{
	int i;
	uint32_t MaxVal = 0;
	int ret_val;

	for (i=0; i<Size; ++i) {
		if (MaxVal < Arr[i]) {
			MaxVal = Arr[i];
			ret_val = i;
		}
	}

	return i;
}

uint32_t AdjustSidesTri(uint32_t *Arr)
{
	int MaxIdx = -1;
	int Ret = 0;
	int twoSum = 0;
	int i;

	MaxIdx = FindMaxValIdx(Arr, SIDES);

	for (i=0; i<SIDES; ++i) {
		if (MaxIdx == i) {
			continue;
		}
		twoSum += Arr[i];
	}

	while (twoSum < Arr[MaxIdx]) {
		twoSum += 2;
	}
}

int main(void)
{
	uint32_t a[SIDES] = {0};
	int i;
	int increment = 0;

	printf("Enter 3 numbers:\n");

	for (i=0; i<SIDES; ++i) {
		scanf("%u\n", a[i]);
	}

	increment = AdjustSidesTri(a);

}
