#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void reverse(char *str, int low, int high)
{
	int n = high - low;
	for(int i=0; i<n/2; ++i) {
		swap(&str[i+low], &str[n-i-1+low]);
		printf("DEBUG:char[%d]=%c char[%d]=%c\t", i+low, str[i+low],n-i-1+low, str[n-i-1+low] );
	}
	printf("\n");
}

void Reverse(char *str)
{
	int n = strlen(str);
	char ch = ' ';
	int j = 0, i=0;
	for(i=0, j=0; (i<n)&&(j<n);) {
		if (str[j] == ch)
			++j;
		if ((str[i] == ch) && (str[j]!=ch)) {
			printf("j:%d\ti:%d\n", j, i);
			reverse(str, j, i);
			printf("DEBUG:%s\n", str);
			j = i+1;
		}
		++i;
	}
	while((str[j]==ch) && j<n) ++j;
	reverse(str, j ,i);
}

int main(void)
{
	char ch[] = "Amit is a scary dhamne";
	reverse(ch, 0, strlen(ch));
	printf("original string: %s\n",ch);
	Reverse(ch);
	printf("original string: %s\n",ch);
	return 0;
}
