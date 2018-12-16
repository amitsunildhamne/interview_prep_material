#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
private:
  unordered_map<int, bool> visited;
  unordered_map<int, vector<int>> adj_list;
  int node_count;
public:
  Graph(int node_count)
  {
      this->node_count = node_count;
  }

  void Insert(int node_value, vector<int> &neighbours)
  {
      visited[node_value] = false;
      for (int i = 0; i < neighbours.size(); ++i)
      {
        adj_list[node_value].push_back(neighbours[i]);
        visited[neighbours[i]] = false;
      }
  }

  void BFS()
  {
      queue <int> Q;
      auto itr = adj_list.begin();
      Q.push(itr.first);
      while(!Q.empty)
      {
        int key = Q.front();
        Q.pop_front();
        cout<<"Node: "<<key<< " ";
        visited[key] = true;
        for(auto v_itr = (itr.second).begin(); v_itr != (itr.second).end(); ++v_itr)
        {
          if(visited[*v_itr] == false )
          {
            Q.push(*v_itr);
          }
        }
      }
  }

  void DFS(int v)
  {
      visited[v] = true;
      cout<<"Node: "<<v<<" ";
      for(int i = 0; i < adj_list[v].size(); ++i)
      {
        if (visited[adj_list[v][i]] == false)
        {
          DFS(adj_list[v][i]);
        }
      }
  }
};

int main()
{

}
