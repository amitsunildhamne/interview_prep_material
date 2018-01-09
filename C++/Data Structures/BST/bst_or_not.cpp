#include <iostream>
#include <limits.h>
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
  return node;
}

Node* Insert(Node* root, int data)
{
  if(root==NULL) root = GetNewNode(data);
  else if(root->data>data) root->left =Insert(root->left,data);
  else root->right = Insert(root->right,data);
  return root;
}

Node* Insert_b(Node* root, int data)
{
  if(root==NULL) root = GetNewNode(data);
  else if (root->data > data) root->right = Insert(root->left, data);
  else root->left = Insert (root->right, data);
  return root;
}

bool is_bst_util(Node* node, int min_limit, int max_limit)
{
  if (node==NULL) return true;
  if ((node->data > min_limit)&&(node->data < max_limit) && is_bst_util(node->left, min_limit, node->data ) && is_bst_util(node->right, node->data, max_limit))
    return true;
  else
    return false;
}

bool is_bst(Node* node)
{
  return is_bst_util(node, INT_MIN ,INT_MAX);
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
  root = Insert_b(root, 1);
  if(is_bst(root)) cout<<"Given Tree is Binary Tree"<<endl;
  else cout<<"Given Tree is not Binary"<<endl;
  return 0;
}
