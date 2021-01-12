#include <stdio.h>
#include <stdlib.h>

int my_atoi(char *str)
{
	int len = 0;
	int ret_val = 0;
	int i;
	char *temp = str;

	while (*temp != '\0') {
		++len;
		++temp;
	}

	if (len == 0)
		goto done;

	for (i=0; i<len; ++i) {
		if (str[i]=='-') {
			continue;
		}
		if ((str[i]<'0') || (str[i]>'9') ) {
			break;
		}
		ret_val *= 10;
		ret_val += (int)str[i]-'0';
	}

	if (str[0]=='-') {
		ret_val *= -1;
	}

done:
	return ret_val;
}

int main()
{
	char a[] = "1615";
	char b[] = "-234";
	char c[] = "0";
	char d[] = "";
	int num;
	num = my_atoi(a);
	printf("%d\n", num);
	num = my_atoi(b);
	printf("%d\n", num);
	num = my_atoi(c);
	printf("%d\n", num);
	num = my_atoi(d);
	printf("%d\n", num);
	return 0;
}
