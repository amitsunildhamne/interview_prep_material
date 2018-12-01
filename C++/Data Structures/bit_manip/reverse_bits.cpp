#include <iostream>
using namespace std;

void print_binary(int a)
{
  int t;
  while(a)
  {
    cout<< (a&1) <<" ";
    a>>=1;
  }
  cout<<endl;
}

int main()
{
  int a = 11;
  int b;
  int i;
  print_binary(a);
  while(a)
  {
    b = b<<1;
    b|=a&1;

    a>>=1;
    ++i;
  }

  cout<< b<<endl;
  return 0;
}
