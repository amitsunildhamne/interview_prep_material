#include <stdlib.h>
#include <stdio.h>

#define SUCCESS				0
#define FAILURE				-1

int MyItoA(int Value, char **Str, int *Size)
{
	int i = 0;
	int temp = Value;
	int IsNegative = Value<0?1:0;
	int Status = FAILURE;

	if (Value == 0) {
		*Str = (char *)malloc(sizeof(char)*1);
		*Size = 1;
		(*Str)[0] = '0';
		Status = SUCCESS;
		goto done;
	}

	temp = IsNegative==1? -1*Value:Value;
	printf("temp1:%d\n", temp);
	while(temp!=0) {
		++(*Size);
		temp/=10;
	}

	temp = IsNegative==1? -1*Value : Value;
	printf("temp2:%d\n",temp);
	*Size = IsNegative==1? *Size+1: *Size;
	*Str = (char *)malloc(sizeof(char) * *Size);
	for(int i=0; i<*Size; ++i) {
		(*Str)[*Size-1-i] =(char)('0'+(temp%10));
		printf("%c:%d\t",(*Str)[i],temp%10);
		temp/=10;
	}
	printf("\n");
	if (IsNegative==1)
		(*Str)[0] = '-';

	printf("Size:%d\n",*Size);
	Status = SUCCESS;
done:
	return Status;
}

void Print(int Status, char *str, int Size)
{
	printf("Status:%d\tString:", Status);
	for(int i=0; i<Size; ++i) {
		printf("%c", str[i]);
	}
	printf("\n");
}

int main(void)
{
	int Value = -12345;
	char *Str = NULL;
	int Size = 0;
	int Status = MyItoA(Value,&Str,&Size);
	Print(Status,Str,Size);
	free(Str);
	return 0;
}
