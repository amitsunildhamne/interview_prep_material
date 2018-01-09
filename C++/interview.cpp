/*3 Butter
4 Fly
3 & 4 ButterFly
*/
#include <iostream>
using namespace std;

void print1to100_itr(int n)
{
  for(i=1;i<=n;++i)
  {
    if(i%3==0 || i%4==0)
    if(i%3==0)  cout<<"Butter";
    if(i%4==0) cout<<"Fly";
    else cout<<i;
    cout<<endl;

  }
}

void print1to100_rec(int n);
{
  if(n==1)
  {
    cout<<n;
    return;
  }
  print1to100_rec(n-1);
  if(n%3==0 || n%4==0)
  if(n%3==0)  cout<<"Butter";
  if(n%4==0) cout<<"Fly";
  else cout<<n;
  cout<<endl;

}

int main()
{
  int n = 100;
  print1to100_itr(n);
  print1to100_rec(n);
  return 0;
}
