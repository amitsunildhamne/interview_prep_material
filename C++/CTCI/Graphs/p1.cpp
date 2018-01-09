#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map <int,vector<int>> mp;
unordered_map <int,bool> marked;

void create_graph()
{
  mp[0].push_back(1);
  mp[0].push_back(4);
  mp[0].push_back(5);
  mp[1].push_back(4);
  mp[1].push_back(3);
  mp[3].push_back(2);
  mp[3].push_back(4);
  mp[2].push_back(1);

  marked[0] =false;
  marked[1] = false;
  marked[2] = false;
  marked[4] = false;
  marked[3] = false;
  marked[5] = false;
}


bool check_path_exists(int a, int b)
{
  vector<int>::iterator itr;
  marked[a] = true;
  if(a==b)
  {
    return true;
  }
  for(itr=mp[a].begin();itr!=mp[a].end();itr++)
  {
    if(!marked[*itr])
      return check_path_exists(*itr,b);
  }
  return false;
}

int main()
{
  create_graph();
  bool a = check_path_exists(0,1);
  if(a) cout<<"Path exists"<<endl;
  else cout<<"Path doesnt exist"<<endl;
  a = check_path_exists(2,0);
  if(a) cout<<"Path exists"<<endl;
  else cout<<"Path doesnt exist"<<endl;
  return 0;
}
