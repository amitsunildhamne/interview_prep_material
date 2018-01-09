#include <iostream>
#include <queue>
using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
};

Node* GetNewNode(int data)
{
  Node* node = new Node();
  node->data = data;
  node->left = node->right= NULL;
}

Node* Insert(Node* root, int data)
{
  if(root==NULL) root = GetNewNode(data);
  else if (root->data>data) root->left = Insert(root->left, data);
  else root->right = Insert(root->right, data) ;
  return root;
}

void print(Node* root)
{
  if(root==NULL) return;
  print(root->left);
  cout<<root->data<<endl;
  print(root->right);
}

void bfs(Node* root)
{
  int counter;
  queue<Node*> Q;
  Q.push(root);
  while(1)
  {
    if(Q.empty()) break;
    counter = Q.size();
    while(counter>0)
    {
      Node* node = Q.front();
      cout<<node->data<<" ";
      if(node->left) Q.push(node->left);
      if(node->right) Q.push(node->right);
      Q.pop();
      --counter;
    }
    cout<<endl;
  }
}

int main()
{
  Node* root = NULL;
  root = Insert(root,15);
	root = Insert(root,10);
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
  print(root);
  cout<<"Breadth Traversal"<<endl;
  bfs(root);
}
