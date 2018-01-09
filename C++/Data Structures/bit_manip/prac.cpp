#include <iostream>
using namespace std;

int main()
{
  int a = 4;
  int res=0;
  while(a)
  {
    res = a&1==0?0:1;
    a = a>>1;
  }
  cout<<res;
  return 0;
}
