#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int FindUnique(char const *str)
{
	uint8_t Map[26] = {0};
	int len = strlen(str);
	int i=0;
	int ret=0;

	for (i=0; i<len; ++i) {
		Map[str[i]-'a']++;
	}

	for (i=0; i<26; ++i) {
//		printf("Map[%c]: %d\n", i+'a', Map[i]);
	}

	for (i=0; i<len; ++i) {
		printf("%c\t Count:%d\n", str[i], Map[str[i]-'a']);
		if (1==Map[str[i]-'a']) {
			ret = i;
			goto done;
		}
	}

	printf("\n");

done:
	return ret;
}

int main(void)
{
	char str1[] = "leetcode";
	char str2[] = "loveleetcode";

	printf("String:%s Uniq:%d\n", str1, FindUnique(str1));
	printf("String:%s Uniq:%d\n", str2, FindUnique(str2));

	return 0;
}
