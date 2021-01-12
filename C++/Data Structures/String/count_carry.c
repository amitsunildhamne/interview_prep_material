#include <stdio.h>
#include <string.h>
#include <string.h>

int count_carry(char *a , char *b)
{
	int ret_val = 0;
	int a_len = strlen(a), b_len = strlen(b);
	int i = a_len-1, j = b_len-1;
	int num1 = 0, num2 = 0;
	int carry = 0;

	for(;(i>=0)||(j>=0);) {
		num1 = 0;
		num2 = 0;
		if (i>=0) {
			num1 = (int)(a[i]-'0');
			--i;
		}
		if (j>=0) {
			num2 =(int)(b[j]-'0');
			--j;
		}
		carry = (num1+num2+carry)/10;
		ret_val += carry;
	}
	return ret_val;
}

int main(void)
{
	printf("%d\n", count_carry("9555", "5"));
	return 0;
}
