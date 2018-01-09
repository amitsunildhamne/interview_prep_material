#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

void swap(int *l, int* m)
{
  int temp = *l;
  *l = *m;
  *m = temp;
}
void p_and_v()
{
  sort(v.begin(),v.end());
  for(int i=1;i<v.size()-2;i+=2)
  {
    swap(&v[i],&v[i+2]);
  }
}

int main()
{
  int i=0;
  while(i< 10 )
  {
    v.push_back(rand()%15);
    i++;
  }
  cout<<"1st List"<<endl;
  for(int j=0;j<v.size();j++) cout<<v[j]<<endl;
  p_and_v();

  cout<<"2nd List"<<endl;

  for(int j=0;j<v.size();j++) cout<<v[j]<<endl;
  return 0;
}
