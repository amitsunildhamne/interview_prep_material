#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

/* atoi */
int myatoi(char *str)
{
	int len = strlen(str);
	bool isNegative = false;
	int output = 0;
	int i;

	if (str[0] == '-') {
		isNegative = true;
	}

	i = isNegative==true?1:0;

	for (; i < len; ++i) {
		output *= 10;
		output += (str[i] - '0');
	}

	output = isNegative==true ? output*-1:output;
	return output;
}

char *myitoa(int x)
{
	bool isNegative = false;
	char *result;
	int i = 0;
	int len = 0;
	int temp = x;

	if (0 == x) {
		return "0";
	}

	if (0 > x) {
		isNegative = true;
		++len;
		temp *= -1;
		x *= -1;
	}

	while (temp > 0) {
		temp /= 10;
		++len;
	}

	result = (char *)malloc((len+1)*sizeof(char));

	for (i = len-1; i >= 0; --i) {
		result[i] = x%10 + '0';
		x /= 10;
	}

	result[0] = true==isNegative?'-':result[0];
	result[len] = '\0';

	return result;
}

int main(void)
{
	int i;
	char eg[][10] = {"-1234", "0", "154", "-0"};
	int int_res[4] = {0};
	char *str[4];

	printf("Start atoi\n");
	for (i = 0; i < sizeof(eg)/sizeof(eg[0]); ++i) {
		int_res[i] = myatoi(eg[i]);
		printf("%s: %d\n", eg[i], int_res[i]);
	}
	printf("\nStart itoa\n");

	for (i = 0; i < sizeof(eg)/sizeof(eg[0]); ++i) {
		str[i] = myitoa(int_res[i]);
		printf("%d: %s\n", int_res[i], str[i]);
	}
	printf("\n");

	return 0;
}
