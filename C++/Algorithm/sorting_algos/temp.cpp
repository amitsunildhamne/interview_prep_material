#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

void swap(int* a, int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(vector <int>& v, int low, int high)
{
  int pivot = v[high];
  int i = low;
  for(int j=i; j<high; ++j)
  {
    if(pivot>v[j])
    {
      swap(&v[i], &v[j]);
      ++i;
    }
  }
  swap(&v[i],&v[high]);
  return i;
}

void quick_sort(vector<int>& v, int low, int high)
{
  if (low<high)
  {
    int pi = partition(v, low, high);
    quick_sort(v, low, pi-1);
    quick_sort(v, pi+1, high);
  }
}

void print(vector <int>& v)
{
  for(int i=0;i<v.size();++i) cout<<v[i]<<" ";
  cout<<endl;
}

int main()
{
  srand(time(NULL));
  vector <int> v;
  for(int i=0; i<10; ++i) v.push_back(rand()%100);
  print(v);
  quick_sort(v,0, v.size()-1);
  print(v);
  return 0;
}
