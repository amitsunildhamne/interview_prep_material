/* Find first occurence of substring */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findFirstOcc(char *str, char *substr)
{
	int ret_val = -1;
	int i=0, j=0;
	int substrLen = strlen(substr);
	while((str[i]!='\0') && (substr[j]!='\0')) {
		if (str[i] == substr[j]) {
			++j;
		} else {
			j=0;
		}
		if ( j== substrLen) {
			ret_val = i - j +1;
			goto done;
		}
		++i;
	}
done:
	return ret_val;
}

int main()
{
	char *str = "String1  subString1 Strinstrnd subStr ing1subString";
	char *substr = "subString";
	printf("First occurence of substring at:%d\n", findFirstOcc(str, substr));
	return 0;
}
