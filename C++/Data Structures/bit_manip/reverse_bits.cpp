#include <iostream>
using namespace std;

int main()
{
  int a = 6;
  int b;
  int i;
  while(a)
  {
    b = b<<1;
    b|=a&1;
    cout<<"i "<<i<<" b "<<b<<endl;

    a>>=1;
    ++i;
  }

  //110
  return 0;
}
