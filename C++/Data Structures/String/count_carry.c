#include <stdio.h>
#include <string.h>
#include <stdint.h>

uint32_t count_carry(char *str1, char *str2)
{
	uint32_t ret_val = 0;
	int str1_len = strlen(str1);
	int str2_len = strlen(str2);
	int x=0, y=0, carry = 0, i=str1_len-1, j=str2_len-1;

	while ((i>=0) && (j>=0)) {
		x = (int)(str1[i] - '0');
		y = (int)(str2[j] - '0');
		ret_val += (uint32_t)((x+y+carry)/10);
		carry = (x+y+carry)/10;
		--i; --j;
	}
	if (i>=0) {
		x = (int)(str1[i]-'0');
		ret_val += (x+carry)/10;
	} else if (j>=0) {
		y = (int)(str2[j]-'0');
		ret_val += (y+carry)/10;
	} 
	
	return ret_val;
}
int main()
{
	char *str1 = "9555";
	char *str2 = "555";
	printf("%u\n", count_carry(str2, str1));
	return 0;
}
