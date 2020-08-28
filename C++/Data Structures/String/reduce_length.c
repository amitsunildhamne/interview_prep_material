/* Reduce Length to have uniques */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ReduceLen(char *str)
{
	int len = strlen(str);
	int ret_val = 0, i=1;

	for(; i<len; ++i) {
		str[i]i!=str[i-1]?++ret_val:0;
	}

done:
	return ret_val;
}

int main(void)
{
	char *str = "abccderccwq";
	printf("Original: %s\tNew: %s\n",str, ReduceLen(str));
	return 0;
}
