#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Reverse(char *str, int hi, int lo)
{
	int len = hi - lo + 1;
	char temp;

//	printf("length:%d\n", len);
	for(int i=0; i<len/2; ++i) {
		temp = str[i+lo];
//		printf("str[%d]:%c str[%d]:%c\n", i, temp, lo+len-1-i, str[lo+len-1-i] );
		str[i+lo] = str[hi-i];
		str[hi-i] = temp;
	}
}

void ReverseWords(char *str)
{
	int lo=0, hi=0;
	char *ch = str;
	while(*ch != '\0') {
//		printf("%c", *ch);
		if (*ch != ' ') {
			++hi;
			++ch;
			continue;
		}
		printf("lo:%d hi:%d ch:%c\n", lo, hi, *ch);
		Reverse(str, hi-1, lo);
		printf("%s\n", str);
		lo = hi+1;
		hi = hi+1;
		++ch;
	}
	printf("lo:%d hi:%d ch:%c\n", lo, hi, *ch);
	Reverse(str, hi-1, lo);
}

int main(void)
{
	char str[] = "Amit  is a bad cat";
	printf("%s\n", str);
	Reverse(str, strlen(str)-1, 0);
	printf("%s\n", str);
	ReverseWords(str);
	printf("%s\n", str);
	return 0;
}

