#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int BinarySearch(int num, vector<int> v)
{
  int mid, start, end;
  start = 0;
  end = v.size()-1;
  while(start<=end)
  {
    mid = (start+end)/2;
    if ( num == v[mid] ) return mid;
    else if (num < v[mid]) end = mid-1;
    else start = mid+1;
  }
  return -1;
}

int main()
{
  vector<int> v;
  v.push_back(2); //0
  v.push_back(4); //1
  v.push_back(8); //2
  v.push_back(10); //3
  v.push_back(15); //4
  v.push_back(19); //5
  v.push_back(20); //6
  v.push_back(21); //7
  v.push_back(26); //8
  v.push_back(32); //9
  int res = BinarySearch(21,v);
  if (res==-1) cout<<"Not present in the list"<<endl;
  else cout<<"Present at location: "<<res<<endl;
  res = BinarySearch(8,v);
  if (res==-1) cout<<"Not present in the list"<<endl;
  else cout<<"Present at location: "<<res<<endl;
  res = BinarySearch(26,v);
  if (res==-1) cout<<"Not present in the list"<<endl;
  else cout<<"Present at location: "<<res<<endl;
  return 0;
}
