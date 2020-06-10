#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct Node
{
    int value;
    Node *right, *left;
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
    return GetNewNode(value);
  }
  else if (root->value > value)
  {
    root->left = Insert(root->left, value);
  }
  else
  {
    root->right = Insert(root->right, value);
  }
  return root;
}

void Print(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  Print(root->left);
  cout<<root->value<<" ";
  Print(root->right);
}

int MaxHeight(Node *root)
{
    if (root == NULL)
    {
      return 0;
    }
    return max(root->left, root->right ) + 1;
}

void bfs(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  int sizeOfQueue = 0;
  queue <Node *> q;
  q.push(root);
  while(1)
  {
    if (q.empty)
    {
      return;
    }
    else
    {
        sizeOfQueue = q.size();
    }
    while(sizeOfQueue>0)
    {
      Node *temp  = q.front();
      q.pop();
      cout<<temp->value<<" ";
      if (temp->left != NULL)
      {
        q.push(temp->left);
      }
      if (temp->right != NULL)
      {
        q.push(temp->right);
      }
      --sizeOfQueue;
    }
    cout<<endl;
  }
}

int isBSTHelper(Node *root, int min, int max)
{
  if (root == NULL)
  {
    return 1;
  }
  if ( ( root->value >= min ) &&
       ( root->value <  max ) &&
       ( isBSTHelper( root->left, min, root->value  ) ) &&
       ( isBSTHelper( root->right, root->value, max ) ) &&
     )
     {
        return 1;
     }
  return 0;
}

Node *deleteNode( Node *root, int value)
{
  if( root == NULL )
  {
    return NULL;
  }
  else if ( root->value > value )
  {
    root->left = deleteNode(root->left, value);
  }
  else if ( root->value < value)
  {
    root->right = deleteNode(root->right, value);
  }
  else
  {
    if ( root->left == NULL )
    {
      Node *temp = root;
      root = root->right;
      delete( temp );
    }
    else if ( root->right == NULL )
    {
      Node *temp = root;
      root = root->left;
      delete( temp );
    }
    else
    {
      Node *temp = findMin(root->right);
      root->value = temp->value;
      root->right = deleteNode( root->right, root->value );
    }
  }
  return root;
}

int isBST(Node *root)
{
  int max = INT_MAX;
  int min = INT_MIN;
  return isBSTHelper(Node *root, min, max);
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
	Print(root);
	cout<<endl;
	cout<<MaxHeight(root)<<endl;
	bfs(root);
	isBST(root);
	void deleteNode( Node *root, int value);
  return 0;
}
