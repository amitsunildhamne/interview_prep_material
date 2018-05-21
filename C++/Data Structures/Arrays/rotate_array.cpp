#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int* rotate(int* a, int length, int idx)
{
  int* temp = new int[length];
  for(int i=idx, j=0; i<length;++i,++j)
  {
    temp[j] = a[i];
  }
  for(int i=0, j=length-idx; i<idx; ++i,++j)
  {
    temp[j] = a[i];
  }
  for(int i=0;i<length; ++i)
  {
    a[i] = temp[i];
  }
  delete [] temp;
  return a;
}

void print(int* a, int length)
{
  for(int i=0; i<length; ++i)
  {
    cout<<a[i]<<" ";
  }
  cout<<endl;
}

int main()
{
  int a[10];
  srand(time(NULL));
  for (int i=0; i< 10; ++i)
  {
    a[i] = rand()%1000;
  }
  print(a,10);
  rotate(a,10, 3);
  print(a,10);
  return 0;
}
