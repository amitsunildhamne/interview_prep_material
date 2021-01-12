#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void PrintArr(int *arr, int arr_len);
void PrintArrX(uint8_t *arr, int arr_len);

void FindElementAndMark(const int val, int *arr, uint8_t *visited, int len, int *res_len)
{
	int i;

	for (i=0; i<len; ++i) {
		if ((val==arr[i]) && ((uint8_t)0==visited[i])) {
			visited[i]=(uint8_t)1;
			++(*res_len);
			break;
		}
	}
}

int *ArrayIntersection(int *nums1, int nums1_len, int *nums2, int nums2_len, int *res_len)
{

	uint8_t *visited;
	int i;
	int res_itr = 0;
	int lower_sz;
	int *lower_arr;
	int greater_sz;
	int *greater_arr;
	int *res_arr;

	if (nums1_len > nums2_len) {
		lower_sz = nums2_len;
		greater_sz = nums1_len;
		lower_arr = nums2;
		greater_arr = nums1;
	} else {
		lower_sz = nums1_len;
		greater_sz = nums2_len;
		lower_arr = nums1;
		greater_arr = nums2;
	}

	printf("Lower Array:\t");
	PrintArr(lower_arr, lower_sz);
	printf("Larger Array:\t");
	PrintArr(greater_arr, greater_sz);

	visited = (uint8_t *)malloc(sizeof(uint8_t)*greater_sz);
	memset(visited, 0, greater_sz);
	printf("Visited Init Array:\t");
	PrintArrX(visited, greater_sz);

	for (i=0; i<lower_sz; ++i) {
		FindElementAndMark(lower_arr[i], greater_arr, visited, greater_sz, res_len);
	}

	printf("Visited Array:\t");
	PrintArrX(visited, greater_sz);

	res_arr = (int *)malloc(sizeof(int)*(*res_len));
	memset(res_arr, 0, *res_len);
	
	for (i=0; (i<greater_sz) && (res_itr<*res_len); ++i) {
		if (1==visited[i]) {
			res_arr[res_itr] = greater_arr[i];
			++res_itr;
		}
	}

	free(visited);
	return res_arr;
}

void PrintArr(int *arr, int arr_len)
{
	for (int i=0; i<arr_len; ++i) {
		printf("arr[%d]:%d\t", i, arr[i]);
	}
	printf("\n");
}

void PrintArrX(uint8_t *arr, int arr_len)
{
	for (int i=0; i<arr_len; ++i) {
		printf("arr[%d]:%d\t", i, arr[i]);
	}
	printf("\n");
}

int main(void)
{
	int nums1[] = {1, 2, 2, 1};
	int nums2[] = {2,2};
	int res_len=0;

	int *res = ArrayIntersection(nums1, sizeof(nums1)/sizeof(nums1[0]), nums2, sizeof(nums2)/sizeof(nums2[0]), &res_len);
	PrintArr(res, res_len);

	free(res);
	return 0;
}
