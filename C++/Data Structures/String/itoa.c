#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void my_itoa(int val)
{
	int is_neg = val>0?0:1;
	int str_size = is_neg;
	int temp_val = val;
	while(temp_val!=0) {
		str_size++;
		temp_val/=10;
	}
	temp_val = is_neg==1?(-1*val):val;
	char *c_arr = (char *)malloc(sizeof(char)*str_size);
	for(int i = str_size-1; (i>=0) ; --i) {
		c_arr[i] = (char)((temp_val%10) +'0');
		temp_val/=10;
	}
	if (is_neg == 1)
		c_arr[0]='-';
printf("%s\n", c_arr);

	for(int i =0; i<str_size; ++i)
		printf("%c", c_arr[i]);
	printf("\n");

}

int main(void)
{
	int i = 100;
	my_itoa(i);
	i = -1290;
	my_itoa(i);
	i = 0;
	my_itoa(i);
	return 0;
}
