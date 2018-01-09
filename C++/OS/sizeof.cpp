#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
  long long int p;
  int size;
  char* p1 = (char*)&p;
  char* p2 = (char*)(&p+1);
  size = p2-p1;
  cout<<size<<endl;
  return 0;
}
