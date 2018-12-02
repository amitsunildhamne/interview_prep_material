#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

struct Edge
{
  int src, dest,weight;
}

class Graph
{
public:
  vector<pair<int, int>> adjList;
  int N;
  Graph(vector<Edge> edges, int N)
  {
    adjList.resize(N);
    for (int i=0;i<edges.size();++i)
    {
       int src = edges[i].src;
       int dest = edges[i].dest;
       int weight = edges[i].weight;
       adjList[src].push_back(make_pair(dest, weight));
    }
  }
};

void Print(Graph const &G)
{
  for(int i=0;i<N;++i)
  {
    vector<pair<int,int>> ::const_iterator itr;
    for(itr=adjList[i].begin();itr!=adjList.end();++itr)
    {
      cout<<i<<" "<<i<<" "<<adjList[i].first<<" "<<adjList[i].second<<endl;
    }
  }
}

int main()
{
  return 0;
}
