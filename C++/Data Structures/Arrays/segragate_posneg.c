#include <stdio.h>
#include <string.h>

int *Shuffle(int *arr, int size)
{
	int j=0;
	for(int i=0; i<size; ++i) {
		if (arr[i]>0) {
			continue;
		}
		j = i-1;
		int temp = arr[i];
		while(j>=0 && arr[j]>0) {
			arr[j+1] = arr[j];
			--j;
		}
		arr[j+1]=temp;
	}
	return arr;
}

void Print(char *str, int *arr, int size)
{
	printf("%s\t", str);
	for(int i=0; i<size; ++i)
		printf("%d\t", arr[i]);
	printf("\n");
}

int main(void)
{
	int arr[] = {8, 2, -1, 3, 4, -8};
	Print("Original", arr, sizeof(arr)/sizeof(arr[0]));
	Print("New", Shuffle(arr, sizeof(arr)/sizeof(arr[0])), sizeof(arr)/sizeof(arr[0]));

	int arr1[] = {-8, -2, -1, -3, -4, -8};
	Print("Original", arr1, sizeof(arr1)/sizeof(arr1[0]));
	Print("New", Shuffle(arr1, sizeof(arr1)/sizeof(arr1[0])), sizeof(arr1)/sizeof(arr1[0]));

	int arr2[] = {8, 2, 1, 3, 4, 8};
	Print("Original", arr2, sizeof(arr2)/sizeof(arr2[0]));
	Print("New", Shuffle(arr2, sizeof(arr2)/sizeof(arr2[0])), sizeof(arr2)/sizeof(arr2[0]));

	return 0;
}
