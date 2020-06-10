/*
 * 2 strings are given. Compare both pattern and store the offsets in an array
 * Example: pattern1:asytrstrnstrs pattern2:str
 * Returns [5,9]
 */
#include <stdlib.h>
#include <stdio.h>

int *CompareString(char Str[], char Substr[], int *size)
{
	int StrSize = 0;
	int i = 0, j = 0;
	int SubStrSize = 0;
	int *OffsetArray = NULL;
	int temp;
	int OffsetArrayItr = 0;

	while(Str[i] != '\0') {
		++StrSize;
		++i;
	}

	i=0;

	while (Substr[i] != '\0') {
		++SubStrSize;
		++i;
	}

	if (SubStrSize > StrSize) {
		return NULL;
	}

	printf("String size:%d\tSubstr Size:%d\n", StrSize, SubStrSize);
	OffsetArray = (int *)malloc(sizeof(int)*StrSize);

	for(i=0; i<StrSize - SubStrSize + 1; ++i) {
		temp = i;
		for(j=0; j<SubStrSize; ++j) {
			if (Substr[j] != Str[temp])
				break;
			++temp;
		}
		if (j == SubStrSize) {
			OffsetArray[OffsetArrayItr] = i;
			*size = *size + 1;
			OffsetArrayItr++;
		}
	}

	return OffsetArray;
}

void Print(int *OffsetArray, int size)
{
	printf("Size: %d\n", size);
	printf("Array:\t");
	for(int i=0; i<size; ++i)
		printf("%d\t", OffsetArray[i]);
	printf("\n");
}

int main(void)
{
	char A[] = "asytrstrnstrs";
	char B[] = "str";
	int size = 0;
	int *OffsetArray = CompareString(A,B, &size);
	Print(OffsetArray, size);
	free(OffsetArray);
	OffsetArray = NULL;
	return 0;
}
