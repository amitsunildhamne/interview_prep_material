#include <iostream>
using namespace std;

int main ()
{
  int a = 10;
  int a_copy = a;
  int res=0;
  while(a_copy)
  {
    res = res<<1;
    res |= a_copy & 1 ;
    a_copy = a_copy>>1;
  }
  cout<<res<<endl;
}
