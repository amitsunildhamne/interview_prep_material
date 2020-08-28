/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int **ret_val = NULL;
    *returnSize = 1<<numsSize;
    *returnColumnSizes = (int *)malloc(*returnSize * sizeof(int));
    ret_val = (int **)malloc(sizeof(int *) * (*returnSize));
    printf("NumsSize:%d RowSize:%d\n", numsSize, *returnSize);
    
    for (int i=0; i<*returnSize; ++i) {
        int temp = i;
        int ctr =0;
        while(temp>0) {
            if (temp&1) {
                ++ctr;
            }
            temp>>=1;
        }
        (*returnColumnSizes)[i] = ctr;
        printf("ColumSize[%d]:%d\n",i,ctr);
        ret_val[i] = (int *)malloc(sizeof(int) * ctr);
    }
    
    for(int i=0; i<*returnSize; ++i) {
        int temp = i;
        int ctr = 0, j=0;
        while (temp>0) {
            if(temp&1) {
                ret_val[i][ctr] = nums[j];
                ++ctr;
            }
            temp>>=1;
            ++j;
        }
    }
    
    return ret_val;
}

int main()
{
	int arr = {0,1,2};
	int arrSize = sizeof(arr)/sizeof(arr[0]);
	int **ResultArr
	return 0;
}
