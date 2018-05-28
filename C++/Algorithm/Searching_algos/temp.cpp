#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int binary_search_helper(vector<int>& v, int start, int end, int data_to_find)
{
  if (start>=end) return -1;
  else{
  int mid = start+end/2;
  if (v[mid]==data_to_find) return mid;
  else if (v[mid]>data_to_find) return binary_search_helper(v, start, mid-1, data_to_find);
  else return binary_search_helper(v, mid+1, end, data_to_find);}
}

void binary_search(vector<int>& v, int data_to_find)
{
  cout<<binary_search_helper(v,0, v.size()-1,data_to_find)<<endl;
}

int main()
{
  vector <int> v;
  srand(time(NULL));
  for(int i=0; i<10; ++i) v.push_back(rand()%100);
  sort(v.begin(),v.end());
  binary_search(v,v[3]);
  return 0;
}
