#include <stdio.h>
#include <string.h>

void reverse(char *a, int start, int end)
{
  char temp;
  for(int i = start, j = end-1; i <= j; ++i, --j)
  {
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
  }
  printf("In fn=%s a = %s start=%d end=%d\n", __FUNCTION__, a, start, end);
}

void word_reverse(char *a, int length)
{
  int i,j;
  i=0;
  j=0;
  while(j < strlen(a)+1)
  {
    if( j == strlen(a) || a[j] == ' ')
    {
      printf("a=%s i=%d j=%d\n", a, i, j );
      reverse(a, i , j);
      i = j+1;
    }
    j++;
  }
}

int main()
{
  char a[100] = "My name is amit";
  reverse(a, 0, strlen(a));
  word_reverse(a , strlen(a));
  printf("%s\n", a);
  return 0;
}
