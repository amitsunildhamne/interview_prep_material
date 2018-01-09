#include <iostream>
#include <climits>
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
  else if(root->data>data) root->left = Insert(root->left, data);
  else root->right = Insert(root->right, data);
  return root;
}

bool validate_bst(Node* root, int min, int max)
{
  if (root==NULL) return;
  if(root->data>min && root->data<max && validate_bst(root->left, min, root->data) && validate_bst(root->right, root->data,max))
  return true;
  else return false;
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
  root = Insert(root, 27);
  root = Insert(root, 29);
  bool f = validate_bst(root, INT_MIN, INT_MAX);
  if(f) cout<<"is BST";
  else cout<<"NoT BST";
  return 0;
}
