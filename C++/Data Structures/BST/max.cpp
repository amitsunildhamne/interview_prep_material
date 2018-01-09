#include <iostream>

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
  node->left = NULL;
  node->right = NULL;
}

Node* Insert(Node* root, int data)
{
 if(root==NULL)
  root = GetNewNode(data);
 else if (root->data >= data)
  root->left = Insert(root->left, data);
else root->right = Insert(root->right, data);
  return root;
}

int MaxBST(Node* root)
{
  if (root == NULL)
  {
    std::cout << "Error!! No tree exists" << '\n';
    return -1;
  }
  else if (root->left==NULL)
    return root->data;
  return MaxBST(root->left);
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
  int a =  MaxBST(root);
  cout<<"The minimum data is: "<<a<<endl;
  return 0;
}
