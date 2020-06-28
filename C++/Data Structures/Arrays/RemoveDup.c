#include <stdio.h>
#include <stdlib.h>

int Map[10] = {0};

void Print(int *arr, int size)
{
	for (int i=0; i<size; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

int FindNextUnique(int *arr, int size, int start_pos)
{
	int ret_val = -1;
	for(int i=start_pos+1; i<size; ++i) {
		if (Map[arr[i]] == 0) {
			ret_val = i;
			goto done;
		}
	}

done:
	return ret_val;
}

static inline void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int RemoveDup(int *arr, int size)
{
	int i=0, j=0;
	for(;i<size;) {
		if (Map[arr[i]] == 1) {
			j = FindNextUnique(arr, size, i);
			if (j == -1) {
				break;
			}
			swap(arr, i, j);
			continue;
		}
		Map[arr[i]] = 1;
		++i;
	}

	return i;
}

int main()
{
	int i=0, size=25;
	int arr[25] = {0};
	srand(0);
	for (i=0; i<size; ++i)
		arr[i] = rand()%10;
	Print(arr, 25);
	size = RemoveDup(arr, 25);
	Print(arr, size);
	return 0;
}
