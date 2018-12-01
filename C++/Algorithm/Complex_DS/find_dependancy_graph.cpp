#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Node
{
public:
  int id;
  vector<Node *> edge;
  Node(char id)
  {
    this->id = (int) id;
  }
  void addEdge(Node *node)
  {
    this->edge.push_back(node);
  }
};

void findDependancy(Node *node, vector<Node *> *dependantNodes, vector<Node *> *seen)
{
  seen->push_back(node);
  for( int i=0; i<node->edge.size(); ++i)
  {
    if ( find(dependantNodes->begin(), dependantNodes->end(), node->edge[i]) == dependantNodes->end() )
    {
      if ( find(seen->begin(), seen->end(), node->edge[i]) == seen->end() )
      findDependancy(node->edge[i], dependantNodes, seen);
      else
      {
         cout<<"Circular dependancy"<<endl;
         exit(0);
      }
    }
    dependantNodes->push_back(node);
  }
}

int main()
{
  Node *a = new Node('a');
  Node *b = new Node('b');
  Node *c = new Node('c');
  Node *d = new Node('d');
  Node *e = new Node('e');
  a->addEdge(b);    // a depends on b
  a->addEdge(d);    // a depends on d
  b->addEdge(c);    // b depends on c
  b->addEdge(e);    // b depends on e
  c->addEdge(d);    // c depends on d
  c->addEdge(e);    // c depends on e

  vector<Node *> *dependantNodes = new vector<Node *>();
  vector<Node *> *seen = new vector<Node *>();
  findDependancy(a, dependantNodes, seen);
  for (int i=0; i<dependantNodes->size(); ++i)
  {
    cout<<dependantNodes->at(i)<<" ";
  }
  cout<<endl;
  return 0;
}
