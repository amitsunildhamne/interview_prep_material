#include <stdio.h>

int main()
{
  int d;
  int i;
  printf("Enter a number:");
  scanf("%d",&d);
  scanf("%d",&i);
  printf("The number is %d",(d>>i)&1);
  return 0;
}
