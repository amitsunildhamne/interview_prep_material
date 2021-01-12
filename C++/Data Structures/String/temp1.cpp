#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int my_atoi(char *str)
{
	if (str == "0")
		return 0;
	int str_len=0;
	int ret_val=0;
	char *temp_str = str;
	while(*temp_str != '\0') {
		++str_len;
		++temp_str;
	}
	printf("Str:%s Size:%d\n",str ,str_len);
	
	for(int i= str[0]=='-'?1:0; i<str_len; ++i) {
		ret_val *= 10;
		ret_val += str[i]-'0';
	}

	return ret_val=str[0]=='-'?ret_val*-1:ret_val;
}

char *my_itoa(int num)
{
	int temp_num = abs(num);
	int str_len=0;
	char *ret_val;

	while(temp_num > 0) {
		++str_len;
		temp_num/=10;
	}

	str_len = num<=0?str_len+1:str_len;
	printf("num:%d size:%d\n", num, str_len);
	ret_val = (char *)malloc(sizeof(char)*str_len);
	temp_num = abs(num);

	for(int i=str_len-1; i>=0; --i) {
		ret_val[i] = temp_num%10 + '0';
		temp_num = temp_num/10;
	}

	ret_val[0] = num<0?'-':ret_val[0];
	return ret_val;
}

int main(void)
{
	char str1[] = "1234";
	char str2[] = "-1234";
	char str3[] = "0";
	int num1, num2, num3;
	char *s1, *s2, *s3;
	printf("str1: %d\n", num1 = my_atoi(str1));
	printf("str2: %d\n", num2 = my_atoi(str2));
	printf("str3: %d\n", num3 = my_atoi(str3));
	printf("str1: %s\n", s1 = my_itoa(num1));
	printf("str2: %s\n", s2 = my_itoa(num2));
	printf("str3: %s\n", s3 = my_itoa(num3));

	free(s1);
	free(s2);
	free(s3);
	return 0;
}
