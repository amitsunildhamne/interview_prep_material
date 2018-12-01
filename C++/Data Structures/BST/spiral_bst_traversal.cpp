#include <iostream>
#include <queue>

using namespace std;

struct Node
{
  int value;
  Node *left;
  Node *right;
};

Node *GetNewNode(int data)
{
  Node *node = new Node();
  node->value = data;
  node->left = node->right = NULL;
  return node;
}

Node *Insert(Node *root, int data)
{
    if (root == NULL)
    {
      return GetNewNode(data);
    }
    else if (root->value>data)
    {
      root->left = Insert(root->left, data);
    }
    else
    {
      root->right = Insert(root->right, data);
    }
    return root;
}

void PrintTree(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  cout<<root->value<<" ";
  PrintTree(root->left);
  PrintTree(root->right);
}

void spiralTraverseBreadth(Node *root)
{
  queue<Node *> Q;
  Q.push(root);
  int size;
  int level=1;
  while(1)
  {
    if(Q.empty())
    {
      break;
    }
    else
    {
      size = Q.size();
    }
    while(size!=0)
    {
      Node *node = Q.front();
      cout<<node->value<<" ";
      Q.pop();
      if (size&1==0)
      {
        if (node->left)
        Q.push(node->left);
        if (node->right)
        Q.push(node->right);
      }
      else
      {
         if (node->right)
         Q.push(node->right);
         if (node->left)
         Q.push(node->left);
      }
      size--;
    }
    cout<<endl;

  }
}

int main()
{
  Node *root = NULL;
  root = Insert(root,15);
  root = Insert(root,10);
  root = Insert(root,20);
  root = Insert(root,25);
  root = Insert(root,8);
  root = Insert(root,12);
  root = Insert(root, 27);
  root = Insert(root, 29);
  //PrintTree(root);
  spiralTraverseBreadth(root);
  return 0;
}
