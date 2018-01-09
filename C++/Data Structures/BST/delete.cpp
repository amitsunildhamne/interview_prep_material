#include <iostream>

using namespace std;

struct Node
{
  Node* left;
  Node* right;
  int data;
};

Node* GetNewNode(int data)
{
  Node* node = new Node();
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Node* Insert(Node* root, int data)
{
  if (root==NULL) root = GetNewNode(data);
  else if (data<root->data) root->left = Insert(root->left,data);
  else root->right = Insert(root->right, data);
  return root;
}

Node* FindMin(Node* root)
{
  if(root->left == NULL)
  return root;
  else
  return FindMin(root->left);
}
Node* Delete(Node* root, int data)
{
  if(root ==NULL)
  return root;
  else if (root->data>data) root->left = Delete(root->left, data);
  else if (root->data<data) root->right = Delete(root->right, data);
  else
  {
    if(root->left ==NULL && root->right == NULL)
    {
      delete root;
      root = NULL;
    }

    else if (root->left == NULL)
    {
      Node* temp = root;
      root = root->right;
      delete temp;
    }

    else if (root->right == NULL)
    {
      Node* temp = root;
      root = root->left;
      delete temp;
    }

    else
    {
      Node* temp = FindMin(root->right);
      root->data = temp->data;
      root->right = Delete(root->right, temp->data);
    }
  }
  return root;
}

void Inorder(Node* root)
{
  if (root==NULL) return;
  Inorder(root->left);
  cout<<root->data<<endl;
  Inorder(root->right);
}

void Preorder(Node* root)
{
  if (root==NULL) return;
  cout<<root->data<<endl;
  Preorder(root->left);
  Preorder(root->right);
}

void Postorder(Node* root)
{
  if(root == NULL) return;
  Postorder(root->left);
  Postorder(root->right);
  cout<<root->data<<endl;
}

int main()
{
  Node* root = NULL;
	root = Insert(root,5); root = Insert(root,10);
	root = Insert(root,3); root = Insert(root,4);
	root = Insert(root,1); root = Insert(root,11);
  Inorder(root);
	// Deleting node with value 5, change this value to test other cases
	root = Delete(root,5);
  cout<<"In Order Traversal"<<endl;
  Inorder(root);
  cout<<"Pre Order Traversal"<<endl;
  Preorder(root);
  cout<<"Post Order Traversal"<<endl;
  Postorder(root);
}
