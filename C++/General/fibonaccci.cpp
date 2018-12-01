#include<iostream>

using namespace std;

void fib(int a, int b, int n)
{
  if (n==1)
  {
    std::cout<<a+b<<endl;
    return;
  }
  fib(a+b, a, --n);
}

int main()
{
  int n = 5;
  int a,b;
  a =0; b = 1;
  fib(a, b, n);
  return 0;
}
