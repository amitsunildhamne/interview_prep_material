#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int findIndex(int x, vector <int>v)
{
  int start,end, mid;
  start =0;
  end = v.size()-1;
  while(start<=end)
  {
    mid = floor((start+end)/2);
    if (x==v[mid]) return mid;
    else if (v[mid]<=v[end])
    {
      if((x<=v[end])&&(x>v[mid]))
        start = mid +1;
      else end = mid-1;
    }
    else if(v[start] <= v[mid] )
    {
      if((x>=v[start]) && (v[mid]>x))
      end = mid-1;
      else start = mid+1;
    }
  }
}
int main()
{
  vector<int> v;
  v.push_back(2); //0
  v.push_back(4); //1
  v.push_back(8); //2
  v.push_back(10); //3
  v.push_back(15); //6
  v.push_back(19); //7
  v.push_back(20); //8
  v.push_back(21); //9
  v.push_back(26); //10
  v.push_back(32); //12
  rotate(v.begin(),v.end()-4,v.end());
  int idx = findIndex(2,v);
  cout<<""<<idx<<endl;
  return 0;
}

// 8 9 10 1 2 3 4 5 6 7
