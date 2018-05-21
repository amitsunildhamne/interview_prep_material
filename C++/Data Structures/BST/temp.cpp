#include <iostream>
#include <queue>
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
}

Node* Insert(Node* root, int data)
{
  if (root==NULL) root= GetNewNode(int data);
  else if (root->data>data) root->left = Insert(root->left, int data);
  else root->right = Insert(root->right, int data);
  return root;
}

void Print(Node* root)
{
  if (root==NULL) return;
  Print(root->left);
  cout<<root->data<<" ";
  Print(root->right);
}

int maxHeight(Node* root)
{
  if (root==NULL) return -1;
  return max(maxHeight(root->left),maxHeight(root->right))+1 ;
}

int minHeight(Node* root)
{
  if (root==NULL) return 0;
  queue <int> Q;
  Q.push(root);
  int sum;
  while(!Q.empty())
  {
    Node* curr = Q.front();
    Q.pop();
    if (curr->left) Q.push(curr->left);
    if (curr->right) Q.push(curr->right);
    if (curr->left==curr->right==NULL) return sum;
    ++sum;
  }
  return sum;
}

bool isBST(Node* root, int minLimit, int maxLimit)
{
  if (root==NULL) return NULL;
  if (root->data>minLimit && root->data<maxLimit && isBST(root->right,root->data, maxLimit) && isBST(root->left, minLimit, root->data)) return true;
  else return 0;
}

Node* findNode(,Node* root, int data)
{
  if(root==NULL) return NULL;
  else if( root->data == data) return root;
  else if (root->data>data) return findNode(root->left);
  else return findNode(root->right);
}

Node* FindMin(Node* root)
{
  if(root->left==NULL && root->right==NULL) return root;
  return FindMin(root->left);
}

Node* Delete(Node* root, int data_to_delete)
{
  if (root==NULL) return root;
  else if (root->data>data) root->left= Delete(root->left, data_to_delete);
  else if (root->data<data) root->right = Delete(root->right, data_to_delete);
  else
  {
    if (root->right==root->left==NULL)
    {
      delete root;
      root = NULL;
    }
    else if (root->right==NULL)
    {
      Node* temp = root;
      root = root->left;
      delete temp;
    }
    else if (root->left ==NULL)
    {
      Node* temp = root;
      root = root->right;
      delete temp;
    }
    else
    {
      Node* temp = FindMin(root->right);
      root->data = temp->data;
      root->right = Delete(root->right,root->data)
    }
  }
  return root;
}

int main()
{
  Node* root=NULL;
  root = Insert(root,15);
	root = Insert(root,10);
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
  Print(root);
  cout<<"Min Height: "<<minHeight(root)<<endl;
  cout<<"Max Height: "<<maxHeight(root)<<endl;
  cout<<"Is BST: "<<isBST(root,INT_MIN,INT_MAX)<<endl;
  return 0;
}
