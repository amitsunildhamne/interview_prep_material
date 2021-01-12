#include <stdio.h>
#include <string.h>

char *my_strstr(char *str, char *substr)
{
	int str_len = strlen(str);
	int substr_len = strlen(substr);
	int temp;
	int i;
	int j;
	printf("Length: str:%d substr:%d\n", str_len, substr_len);

	for (i=0; i<str_len; ++i) {
		temp = i;
		for (j=0; j<substr_len; ++j, ++temp) {
			if (substr[j] != str[temp])
				break;
		}
		if(j==substr_len)
			break;
	}
	return str + i;
}

int main(void)
{
	char str[] = "TutorialsPoint";
	char substr1[] = "Point";
	char substr2[] = "Pot";

	printf("%s\n", my_strstr(str, substr1));
	printf("%s\n", my_strstr(str, substr2));
	return 0;
}
