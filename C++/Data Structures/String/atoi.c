/* atoi */

#include <stdio.h>
#include <limits.h>
#include <string.h>

int my_atoi(char *s)
{
	int size = 0, i=0;
	int ret_val = 0, Sign=0, prev =0;
	char *temp = s;

	if (temp==NULL) {
		ret_val = INT_MIN;
		goto done;
	}

	while(*temp != '\0'){
		++size;
		++temp;
	}

	if (s[0] > '9' || s[0] < '0') {
		if (s[0] == '-') {
			Sign = 1;
			i = 1;
		} else if (s[0] == '+') {
			i = 1;
		} else {
			ret_val = INT_MIN;
			goto done;
		}
	}

	for (; i<size; ++i) {
		if ((s[i] >'9') || s[i]<'0') {
			ret_val = INT_MIN;
			break;
		}
		prev = ret_val;
		ret_val *=10;
		if (ret_val<prev) {
			printf("Overflow detected\n");
			ret_val = INT_MIN;
			goto done;
		}
		ret_val += s[i]-'0';
	}

	ret_val = Sign==1?ret_val*-1:ret_val;

done:
	return ret_val;

}

int main(void)
{
	char *s = "10";
	printf("%d\n", my_atoi(s));
	s = "-10";
	printf("%d\n", my_atoi(s));
	s = "+10";
	printf("%d\n", my_atoi(s));
	s = "0-10";
	printf("%d\n", my_atoi(s));
	s = "1000000000000";
	printf("%d\n", my_atoi(s));

	return 0;
}
