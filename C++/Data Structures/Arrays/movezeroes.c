#include <stdio.h>
#include <stdlib.h>

static inline void swap(int *arr, int ptr_z, int ptr_nz)
{
	int temp = arr[ptr_z];
	arr[ptr_z] = arr[ptr_nz];
	arr[ptr_nz] = temp;
}

int* MoveZeroes(int *const arr, const int len)
{
	int ptr_nz;
	int ptr_z;

	for (ptr_nz=0, ptr_z=0; (ptr_z<len) && (ptr_nz<len);) {
		if (0 != arr[ptr_z]) {
			++ptr_z;
		}
		if ((0==arr[ptr_z]) && (ptr_nz<=ptr_z)) {
			ptr_nz = ptr_z + 1;
		}
		if ((0==arr[ptr_z]) && (0!=arr[ptr_nz])) {
			swap(arr, ptr_z, ptr_nz);
		}
		++ptr_nz;
	}
}

void PrintArr(int *const arr_orig, const int len)
{
	int i;

	for (i=0; i<len; ++i) {
		printf("%d\t", arr_orig[i]);
	}
	printf("\n");

}

int main(void)
{
	int arr1[] = {2, 0, 0, 6, 7, 0, 9};
	int arr2[] = {0, 0, 0, 0};
	int arr3[] = {1, 20, 30, 40};
	int arr4[] = {0, 10, 0, 0};
	int arr5[] = {};

	PrintArr(arr1, sizeof(arr1)/sizeof(arr1[0]));
	MoveZeroes(arr1, sizeof(arr1)/sizeof(arr1[0]));
	PrintArr(arr1, sizeof(arr1)/sizeof(arr1[0]));

	PrintArr(arr2, sizeof(arr2)/sizeof(arr2[0]));
	MoveZeroes(arr2, sizeof(arr2)/sizeof(arr2[0]));
	PrintArr(arr2, sizeof(arr2)/sizeof(arr2[0]));

	PrintArr(arr3, sizeof(arr3)/sizeof(arr3[0]));
	MoveZeroes(arr3, sizeof(arr3)/sizeof(arr3[0]));
	PrintArr(arr3, sizeof(arr3)/sizeof(arr3[0]));

	PrintArr(arr4, sizeof(arr4)/sizeof(arr4[0]));
	MoveZeroes(arr4, sizeof(arr4)/sizeof(arr4[0]));
	PrintArr(arr4, sizeof(arr4)/sizeof(arr4[0]));

	PrintArr(arr5, sizeof(arr5)/sizeof(arr5[0]));
	MoveZeroes(arr5, sizeof(arr5)/sizeof(arr5[0]));
	PrintArr(arr5, sizeof(arr5)/sizeof(arr5[0]));


//	PrintArr(arr2, MoveZeroes(arr2, sizeof(arr2)/sizeof(arr2[0])), sizeof(arr2)/sizeof(arr2[0]));
//	PrintArr(arr3, MoveZeroes(arr3, sizeof(arr3)/sizeof(arr3[0])), sizeof(arr3)/sizeof(arr3[0]));
//	PrintArr(arr4, MoveZeroes(arr4, sizeof(arr4)/sizeof(arr4[0])), sizeof(arr4)/sizeof(arr4[0]));
//	PrintArr(arr5, MoveZeroes(arr5, sizeof(arr5)/sizeof(arr5[0])), sizeof(arr5)/sizeof(arr5[0]));

	return 0;
}
