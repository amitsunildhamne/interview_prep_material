#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void rotate(int *a, int size, int k)
{
  int* temp = new int[size];
  int j=0;
  for(int i=k;i<size;++i,++j)
  {
    temp[i] = a[j];
  }
  for(int x=0,y=j;x<k;x++,y++)
  {
    temp[x] = a[y];
  }
  for(int i=0;i<size;++i)
  {
    a[i] = temp[i];
  }
  delete [] temp;
}

void print(int *a, int size)
{
  for(int i=0;i<size;++i)
    cout<< a[i] <<" ";
  cout<<endl;
}

int main()
{
  int a[10];
  int k = 5;
  srand(time(NULL));
  for(int i=0;i<10;++i)
  {
    a[i]=rand()%100;
  }
  print(a, sizeof(a)/sizeof(int));
  rotate(a,sizeof(a)/sizeof(int),k);
  print(a, sizeof(a)/sizeof(int));
  return 0;
}
