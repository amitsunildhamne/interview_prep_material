/*
 * Create my_atoi function to convert strings to integers.
 * Example:
 *    Argument: "12345"
 *    Integer :  12345
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STRING_EMPTY			-1
#define WRONG_CHAR				-2
#define FAILURE					-3
#define SUCCESS					 0

int MyAtoi(char Str[], int *Value)
{
	int StrSize = 0;
	/* 0: +ve        1: -ve */
	int IsNegative = 0;
	int i = 0;
	int EOS = 0;
	int Status = FAILURE;
	*Value = 0;

	if (Str == NULL)
		goto done;

	StrSize = strlen(Str);
	i = StrSize-1;
	printf("Size:%d\n",i);
	if (Str[0] == '-') {
		IsNegative = 1;
		EOS = 1;
	}

	for(; i>=EOS; --i) {
		*Value *=10;
		if ((Str[i] >= '0') && (Str[i] <= '9'))
			*Value += Str[i] - '0';
		else
			Status = WRONG_CHAR;
	}

	*Value = IsNegative==1?  -1 * *Value: *Value;
	Status = SUCCESS;

done:
	return Status;
}

int main(void)
{
	char Str[] = "-12345";
	int Value = 0;
	int Status = MyAtoi(Str, &Value);
	printf("Status:%d Value:%d\n", Status, Value);
	return 0;
}
