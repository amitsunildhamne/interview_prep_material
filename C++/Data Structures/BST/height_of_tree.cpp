#include <iostream>
#include <math.h>
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
 if(root==NULL)
 root = GetNewNode(data);
 else if (root->data >= data)
 root->left = Insert(root->left,data);
 else
 root->right = Insert(root->right,data);
 return root;
}

int Height(Node* root)
{
  if(root == NULL) return -1;
  else
  return max(Height(root->left), Height(root->right))+1;
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
  root = Insert(root, 27);
  root = Insert(root, 29);
  int height = Height(root);
  cout<<"The height of tree is: "<<height<<endl;
  return 0;
}
