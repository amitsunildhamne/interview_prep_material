#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& v, int low, int high)
{
  int pivot = v[high];
  int i = low;
  for(int j=low; j<high; ++j)
  {
    if(pivot>=v[j])
    {
      swap(&v[i], &v[j])
      ++i;
    }
  }
  swap(&v[i],&v[high]);
  return i;
}

void sort(vector<int>& v, int low, int high)
{
  while(low<=high)
  {
    int pindex= partition(v, low, high);
    sort(v, low, pindex-1);
    sort(v, pindex+1, high);
  }
}

void Print(vector<int>& v)
{
  for(int i=0; i<v.size();++i)
  {
    cout<<v[i]<<" ";
  }
  cout<<endl;
}

int main()
{
  vector <int> v;
  v.push_back(5);
  v.push_back(7);
  v.push_back(1);
  v.push_back(3);
  v.push_back(0);
  sort(v, 0, v.size()-1);
  Print(v);
  return 0;
}
