#include <stdio.h>
#include <string.h>

void replace(char a[])
{
  int length = strlen(a);
  for(int i=0;i<length-1;++i)
  {
    if(a[i]=='A'&& a[i+1]=='B')
    {
      a[i]='C';
      char temp;
      for(int j=i+1;j<length-1;++j)
      {
        a[j] = a[j+1];
      }
      a[length-1] = '\0';
      --length;
    }
  }
  printf("%s",a);

}

int main()
{
  char a[]= "amitABABdhamne";
  replace(a);
  return 0;
}
