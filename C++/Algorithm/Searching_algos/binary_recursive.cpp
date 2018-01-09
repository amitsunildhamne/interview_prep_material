#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

std::vector<int> v;

int BinarySearch(int x, int start, int end)
{
  if (start>end) return -1;
  else
  {
    if (x==v[floor((start+end)/2)]) return floor((start+end)/2);
    else if (x<v[floor((start+end)/2)]) return BinarySearch(x, start, floor((start+end)/2)-1);
    else return BinarySearch(x,floor((start+end)/2)+1, end);
  }

}
int main()
{
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

  int res = BinarySearch(32, 0, v.size()-1);
  if(res==-1) cout<<"Not present"<<endl;
  else cout<<"Present in index: "<<res<<endl;
  return 0;
}
