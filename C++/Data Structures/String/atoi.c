#include <stdio.h>
#include <string.h>

void my_atoi(char *str)
{
	int res = 0;
	int fact = 1;
	int sign = 1;
	int error = 0;
	for(int i=strlen(str)-1; i>=0; --i) {
		if (str[i] == '-') {
			sign = -1;
			break;
		} else if (str[i] == '+') {
			break;
		} else if ((str[i] < '0') || (str[i]>'9')) {
			error = 1;
		}
		res += fact*(str[i]-'0');
		fact *=10;
	}

	if (error == 0) {
		printf("%d\n", sign*res);
	} else {
		printf("Error occured\n");
	}
}

int main()
{
	char *str = "1290";
	my_atoi(str);
	str = "-100";
	my_atoi(str);
	return 0;
}
