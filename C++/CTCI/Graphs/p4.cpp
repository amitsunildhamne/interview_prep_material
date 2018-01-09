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
  node->left = node->right = NULL;
}

Node* CreateBst(Node* root, int data)
{
  if(root==NULL) root = GetNewNode(data);
  else if (root->data>data) root->left=CreateBst(root->left,data);
  else root->right = CreateBst(root->right,data);
}

int max_height(Node* root)
{
  if(root==NULL) return -1;
  return max(max_height(root->left),max_height(root->right))+1;
}

int min_height(Node* root)
{
  if(root==NULL) return -1;
  return min(min_height(root->left),min_height(root->right))+1;
}

void check(Node* root)
{
  if((max_height(root) - min_height(root))==0 || (max_height(root) - min_height(root))==1)
  cout<<"Balanced"<<endl;
  else
  cout<<"Not Balanced"<<endl;
}

int main()
{
  Node* root = NULL;
  root = CreateBst(root, 8);
  root = CreateBst(root, 4);
  root = CreateBst(root, 10);
  root = CreateBst(root, 2);
  root = CreateBst(root, 11);
  root = CreateBst(root, 7);
  root = CreateBst(root, 9);
  check(root);
  root = CreateBst(root,12);
  root = CreateBst(root, 13);
  root = CreateBst(root, 14);;
  check(root);
  return 0;
}
