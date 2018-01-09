#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int findIndex(vector<int> v)
{
  int start, end, next,mid, prev,N;
  N = v.size();
  start = 0;
  end = v.size()-1;
  while(start<=end)
  {
    if(v[start]<=v[end]) return start;
    mid = floor((start+end)/2);
    next = (mid+1)%N;
    prev = (mid+N-1)%N;

     if ((v[mid]<=v[next])&& (v[mid]<=v[prev])) return mid;
    else if (v[mid]<=v[end]) end = mid-1;
    else if (v[mid]>=v[end]) start = mid+1;
  }
}

int main()
{
  vector<int> v;
  v.push_back(20); //8
  v.push_back(21); //9
  v.push_back(26); //10
  v.push_back(32); //12
  v.push_back(2); //0
  v.push_back(4); //1
  v.push_back(8); //2
  v.push_back(10); //3
  v.push_back(15); //6
  v.push_back(19); //7
  rotate(v.begin(),v.end()-2, v.end());
  int idx = findIndex(v);
  cout<<"Find the index: "<<idx<<endl;
  return 0;
}
