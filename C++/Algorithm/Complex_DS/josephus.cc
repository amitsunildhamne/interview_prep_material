/*
  To solve Joshephus problem
*/
#include <iostream>
#include <vector>

using namespace std;

int execute(int n, int k)
{
  if (n == 1)
  {
    return 0;
  }

  return (execute(n-1,k)+k)%n;
}

int main()
{
  int n = 9;
  int k = 2;
  cout<<"Winner: "<<execute(n,k)<<endl ;
  return 0;
}
