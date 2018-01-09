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
  node->left = node->right = NULL;
}

Node* Insert(Node* root, int data)
{
  if(root==NULL) root = GetNewNode(data);
  else if (root->data >= data) root->left = Insert(root->left, data);
  else root->right = Insert(root->right, data);
  return root;
}

void breadth_traversal(Node* root)
{
  if (root==NULL) return;
  else
  {
    queue <Node*> Q;
    Q.push(root);
    while(!Q.empty())
    {
      Node* current_node = Q.front();
      cout<<current_node->data<<endl;
      if (current_node->left!=NULL) Q.push(current_node->left);
      if (current_node->right!=NULL) Q.push(current_node->right);
      Q.pop();
    }
  }
}

int main()
{
  Node* root;
  root = Insert(root,15);
	root = Insert(root,10);
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
  breadth_traversal(root);
}
