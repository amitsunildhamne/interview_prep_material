#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int IsPalindrome(char *Str)
{
	int Size = strlen(Str);
	if ((Size==0) && (Str==NULL))
		return -1;
	for(int i=0; i<Size/2; ++i) {
		if (Str[i] != Str[Size - 1 -i])
			return 0;
	}

	return 1;
}

int main(void)
{
	char A[] = "AMTTMA";
	char B[] = "ATTM";
	char C[] = "AMTMA";
	volatile char D[] = {'a','b','c','v'};
	printf("%s:%d\t%s:%d\t%s:%d\n", A, IsPalindrome(A), B, IsPalindrome(B), C,
	IsPalindrome(C));
}
