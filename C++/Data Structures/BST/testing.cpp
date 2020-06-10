#include <iostream>
#include <queue>
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
  node->left = node->right = NULL;
  node->data = data;
  return node;
}

Node* Insert(Node* root, int data)
{
  if(root==NULL) root = GetNewNode(data);
  else if(root->data<data) root->right = Insert(root->right, data);
  else root->left = Insert(root->left, data);
  return root;
}

void Print(Node* root)
{
  if(root==NULL) return;
  Print(root->left);
  cout<<root->data<<endl;
  Print(root->right);
}

void bfs(Node* root)
{
  queue<Node*> q;
  q.push(root);
  int sz = q.size();
  while(1)
  {
    if(q.size()==0) break;
    sz  = q.size();
    while(sz-->0)
    {
      Node* temp = q.front();
      cout<<temp->data<<" ";
      q.pop();
      if(temp->left!=NULL) q.push(temp->left);
      if(temp->right!=NULL) q.push(temp->right);
    }
    cout<<endl;
  }
}
int height(Node* root)
{
    if(root==NULL) return -1;
    return max(height(root->left),height(root->right))+1;
}

int main()
{
  Node* root = NULL;
  root = Insert(root, 6);
  root = Insert(root, 5);
  root = Insert(root, 8);
  root = Insert(root, 4);
  root = Insert(root, 7);
  root = Insert(root, 3);
  root = Insert(root, 9);
  Print(root);

  int hght = height(root);
  cout<<"Height "<<hght<<endl;
  bfs(root);
  Print(root);
  return 0;
}


/*
          6
       5    8
    4     7  9
3



*/
