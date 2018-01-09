#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int findFirst(int x, vector <int> v)
{
  int start, mid, end, result;
  start = 0;
  end = v.size()-1;
  result =-1;
  while(start<=end)
  {
    mid = floor((start+end)/2);
    if(v[mid]==x)
    {
      result=mid;
      end = mid -1;
    }
    else if (x<v[mid])
    {
      end = mid-1;
    }
    else start = mid+1;
  }
  return result;
}

int findLast(int x, vector<int> v)
{
  int start, mid, end, result;
  result = -1;
  start =0;
  end = v.size() -1;
  while(start<=end)
  {
    mid = floor((start+end)/2);
    if(x==v[mid])
    {
      result = mid;
      start = mid+1;
    }
    else if (x<v[mid]) end = mid-1;
    else start = mid + 1;
  }
  return result;
}

int main()
{
  vector<int> v;
  v.push_back(2); //0
  v.push_back(4); //1
  v.push_back(8); //2
  v.push_back(10); //3
  v.push_back(10); //4
  v.push_back(10); //5
  v.push_back(10); //5
  v.push_back(15); //6
  v.push_back(19); //7
  v.push_back(20); //8
  v.push_back(21); //9
  v.push_back(26); //10
  v.push_back(26); //11
  v.push_back(32); //12
  v.push_back(32); //12
  v.push_back(32); //12
  v.push_back(32); //12
  v.push_back(32); //12

  int count = findLast(32,v) - findFirst(32,v) + 1;
  cout<<"The count is "<<count<<endl;
  return 0;
}
