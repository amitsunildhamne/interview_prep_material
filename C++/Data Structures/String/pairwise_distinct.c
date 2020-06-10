/*
 * Given a string, return a string that is pairwise distinct. If it's
 * not possible return IMPOSSIBLE
 * Example(1): xxxxyyyy should return abcdefxy
 * Example(2): thisanswerisnotpossibletoget should return IMPOSSIBLE
 */

#include <stdio.h>
#include <string.h>

#define SIZE_OF_MAP			26

int findMin(int *arr)
{
	for(int i=0; i<SIZE_OF_MAP; ++i)
		if (arr[i]==0)
			return i;
}

char *Distinct(char *str, char *res)
{
	int Map[SIZE_OF_MAP] = {0};
	int i = 0, j = 0;

	while(str[i]!='\0') {
		++Map[(int)(str[i]-'a')];
		++i;
	}

	if (i>SIZE_OF_MAP-1)
		return "IMPOSSIBLE";
	
	for(i=0; i<SIZE_OF_MAP; ++i) {
		while(Map[i]>1) {
			--Map[i];
			j = findMin(Map);
			if (j>=0)
				++Map[j];
		}
	}

	for(i=0; i<SIZE_OF_MAP; ++i)
		printf("%c:%d\t",'a'+i, Map[i]);
	printf("\n");

	for(i=0,j=0;i<SIZE_OF_MAP;++i) {
		if (Map[i] == 1) {
			res[j] = (char)('a'+i);
			++j;
		} else if ((Map[i]>1) || (Map[i]<0)) {
			return "ERROR";
		}
	}
	return res;
}

int main(void)
{
	char *str1 = "xxxxyyyy";
	char *str2 = "thisanswerisnotpossibletoget";
	char str[SIZE_OF_MAP];
	printf("Original: %s\tNew: %s\n",str1, Distinct(str1, str));
	printf("Original: %s\tNew: %s\n",str2, Distinct(str2, str));
	return 0;
}
