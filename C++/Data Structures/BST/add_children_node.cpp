/*
  Replace the parent node's value with children's value addition
*/

#include <iostream>

using namespace std;

struct Node
{
  int value;
  Node *left, *right;
};

Node *GetNewNode(int value)
{
  Node *node = new Node();
  node->value = value;
  node->left = node->right = NULL;
  return node;
}

 Node *Insert(Node *root, int value)
 {
   if (root == NULL)
   {
      root = GetNewNode(value);
   }
   else
   {
     if (root->value >= value)
     {
       root->left = Insert(root->left, value);
     }
     else
     {
       root->right = Insert(root->right, value);
     }
   }
   return root;
 }

void print_bst(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  cout<<root->value<<" ";
  print_bst(root->left);
  print_bst(root->right);
}

int Summify(Node *root)
{
  int temp;
  if (root == NULL)
  {
    return 0;
  }
  else if (root->left == NULL && root->right == NULL)
  {
    temp = root->value;
    root->value = 0;
  }
  else
  {
    temp = root->value;
    root->value = Summify(root->left) + Summify(root->right);
  }
  return temp + root->value;
}

int main()
{
  Node* root;
  root = Insert(root,5);
	root = Insert(root,2);
	root = Insert(root,1);
	root = Insert(root,3);
	root = Insert(root,6);
	root = Insert(root,8);
  print_bst(root);
  cout<<endl;
  Summify(root);
  print_bst(root);
  cout<<endl;
  return 0;
}

/*

      15
    10   20
  8   12    25

      5
    2   6
  1  3    8
  */
