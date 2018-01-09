#include <iostream>
#include <bitset>
using namespace std;

int main()
{
  bool result = true;
  int n =10;
  int cnt = n;
  int i=1;
  int flag = n&1;
  cnt =cnt>>1;
  int chck = (n&(1<<1));
  cout<<"flag "<<flag<<"chck"<<chck<<endl;
         while (cnt!=0)
         {
           flag = !flag;
           int chck = (n&(1<<i))!=0;
           cout<<"flag "<<flag<<"chck"<<chck<<endl;
           if(flag != chck) {result = false;}
            ++i;
            cnt>>=1;
         }
        cout<<"Result "<<result<<" i "<<i<<endl;
}
