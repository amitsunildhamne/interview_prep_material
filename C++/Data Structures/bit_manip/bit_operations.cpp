/* Set, Reset, check, reverse, invert */
#include <iostream>

using namespace std;

int set(int x, int pos)
{
  return x|(1<<pos);
}

int reset(int x, int pos)
{
  return x&~(1<<pos);
}

int check(int x, int pos)
{
  return (x&(1<<pos))!=0;
}

int reverse(int x)
{
  int x_copy = x;
  int n=0,y=0;
  while(x_copy)
  {
    x_copy>>=1;
    ++n;
  }
  for(int i=0;i<n;++i)
{
  y=y<<1;
    y |= check(x,i);
  }
  return y;
}

int invert(int x, int pos)
{
  int x_copy = x;
  int n=0, y=0;
  while(x_copy)
  {
    x_copy>>=1;
    ++n;
  }
  for(int i=0;i<n;++i)
  {
    y  <<=1;
    y |= check(x,i)?1:0;
  }
  return y;
}

int invert_bit(int x, int pos)
{
  int val = check(x,pos);
  if (val) return x&~(1<<pos);
  else return x|(1<<pos)
}
int main()
{
  int i = 6;
  int pos=2;
  cout<<"Set: "<<set(i, 0)<<endl;
  cout<<"Reset: "<<reset(i, pos)<<endl;
  cout<<"Check 2nd position on 36: "<<check(i*i,0)<<endl;
  cout<<"reverse: "<<reverse(7)<<endl;
  cout<<"invert: "<<invert(2,pos)<<endl;
  return 0;
}
