#include <stdio.h>
#include <stdlib.h>

#define row			1
#define col			5

int **Transpose(int **p, int Row, int Col)
{
	int i;
	int j;

	int **ret_val = (int **)malloc(Col*sizeof(int **));

	for (i=0; i<col; ++i) {
		ret_val[i] = (int *)malloc(Row*sizeof(int *));
	}

	for (i=0; i<Row; ++i) {
		for (j=0; j<Col; ++j) {
			ret_val[j][i] = p[i][j];
		}
	}

	return ret_val;
}


void PrintArr(int **p, int Row, int Col)
{
	int i;
	int j;

	for (i=0; i<Row; ++i) {
		for (j=0; j<Col; ++j) {
			printf("p[%d][%d]=%d\t",i ,j, p[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	int i=0;
	int j=0;
	int a[row][col] = {0};
	int *p[row] = {NULL};
	int **ret = NULL;

	for (i=0; i<row; ++i) {
		p[i] = &a[i][0];
	}

	for (i=0; i<row; ++i) {
		for (j=0; j<col; ++j) {
			p[i][j] = i*(row-1)+j;
		}
	}

	PrintArr(p, row, col);
	ret = Transpose(p, row, col);
	PrintArr(ret, col, row);

	return 0;
}
