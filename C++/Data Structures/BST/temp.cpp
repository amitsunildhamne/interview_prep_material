#include <iostream>
#include <climits>
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
  node->value =  data;
  node->left  =  NULL;
  node->right =  NULL;
}

Node *Insert(Node* root, int data)
{
    if ( root==NULL )
    {
        root =  GetNewNode(data);
    }
    else if ( data <= root->value )
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

void Print(Node *root)
{
    if (root == NULL) return;
    Print( root-> left);
    cout<<root->value<<" "<<endl;
}

int minHeight(Node *root)
{
    if ( root==NULL )
    {
       return -1;
    }
    else if (root->left==NULL)
    {
        return root->value;
    }
    else
    {
        return minHeight(root->left);
    }
}

int Height(Node *root)
{
   if (root == NULL)
   {
      return 0;
   }

   else return max(Height(root->left), Height(root->right))+1;
}

bool isBST(Node *root, int min, int max)
{
    if (root==NULL) return 1;
    else if ( (root->value >= min) &&
              (root->value <= max) &&
              isBST(root->left, min, root->value) &&
              isBST(root->right, root->value, max) )
              {
                 return 1;
              }
    return 0;
}

void BFS(Node *root)
{
   if (root == NULL) return;
   int counter;
   queue<Node *> Q;
   Q.push(root);
   while(1)
   {
     if (Q.empty()) break;
     counter = Q.size();
     while(counter)
     {
       Node *node = Q.front();
       cout<<node->value<<" ";
       Q.pop();
       if (node->left)  Q.push(node->left);
       if (node->right) Q.push(node->right);
       --counter;
     }
     cout<<endl;
   }
}

void deleteNode(Node *root, int value)
{
    if  (root==NULL) return;
    else if (root->value > value) deleteNode(root->left, value);
    else if (root->value < value) deleteNode(root->right, value);
    else
    {
      if (root->left == NULL && root->right == NULL)
      {

      }
    }
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
  cout<<"Max Height: "<<Height(root)<<endl;
  cout<<"Is BST: "<<isBST(root,INT_MIN,INT_MAX)<<endl;
  BFS(root);
  deleteNode(root, 10);
  return 0;
}
