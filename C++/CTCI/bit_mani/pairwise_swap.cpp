#include <iostream>
using namespace std;

int main()
{
  int x = 2;
  int res = ((x&-1431655765)>>1)|((x&1431655765)<<1);
  cout<<res<<endl;
  return 0;
}
