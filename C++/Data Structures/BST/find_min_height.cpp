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
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

Node* Insert(Node* root, int data)
{
  if (root==NULL) root = GetNewNode( data);
  else if (root->data<data) root->right = Insert(root->right, data) ;
  else root->left = Insert(root->left, data);
  return root;
}



int find_min_height(Node* root)
{
  queue <Node*> Q;
  Q.push(root);
  int sum =0;
  while(!Q.empty())
  {
    root = Q.front();
    Q.pop();
    if(root->left!=NULL) Q.push(root->left);
    else if (root->right!=NULL) Q.push(root->right);
    else if ((root->left==NULL) && (root->right==NULL)) return sum;
    sum++;
  }
}

int main()
{
  Node* root = NULL;

  root = Insert(root,5);
  root = Insert(root,3);

  root = Insert(root, 1);
  root = Insert(root, 0);

    root = Insert(root, 7);
    root = Insert(root, 8);
    root = Insert(root, 9);

  int shortest = find_min_height(root);
  cout<<shortest<<endl;
}
/*
                    5
                  3   6
                2        7
              1              8
*/
