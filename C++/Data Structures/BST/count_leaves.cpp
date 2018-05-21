#include <vector>
#include <map>
#include <cstdlib>
#include <iostream>

using namespace std;

int safety_check(vector<int>& v, int node_to_delete)
{
  int max = v[0];
  for(int i=0;i<v.size();++i)
  {
    if (max<v[i]) max = v[i];
  }
  if (max<node_to_delete) return 0;
  else return 1;
}

void convert_to_adjacency_list(vector<int>& v, map<int,vector<int>>& mp)
{
  for(int i=0;i<v.size();++i)
  mp[v[i]].push_back(i);
  return mp;
}

void delete_node(map<int,vector<int>>& mp, int node_to_delete)
{
  if (mp.find(node_to_delete)==mp.end()) return;
  vector<int>::iterator itr;
  for(itr = mp[node_to_delete].begin(); itr!=mp[node_to_delete].end();++itr)
  {
    delete_node(mp,*itr);
  }
  mp.erase(node_to_delete);
  return;
}

int count_leaves(map<int, vector<int>>& mp)
{
  int leaves_to_add;
  int leaves_to_subtract=mp.size();
  map<int,vector<int>>::const_iterator itr;
  for(itr=mp.begin();itr!=mp.end();++itr)
  {
    for(int i=0; i<itr->size();++i) leaves_to_add++;
  }
  return leaves_to_add-leaves_to_subtract;
}

int main()
{
  int N;
  vector <int> v;
  int node_to_delete;
  map<int, vector<int>> mp;

  cout<<"Enter array size: ";
  cin>>N;
  cout<<"\nEnter array: ";
  for(int i=0; i<N; ++i)
  {
    int num;
    cin>>num;
    v.push_back(num);
  }
  cout<<"\nEnter node to delete";
  cin>>node_to_delete;

  if (safety_check(v,node_to_delete)==0) exit(1);

  convert_to_adjacency_list(v,mp);
  delete_node(mp,node_to_delete);
  cout<<"Leaves are "<<count_leaves(mp)<<endl;

  return 0;
}
