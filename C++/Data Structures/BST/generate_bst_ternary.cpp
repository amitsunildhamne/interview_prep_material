#include <bits/stdc++.h>

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
  node->right=node->left=NULL;
}

Node* createTree(string str, int i)
{
  if (str[i]==NULL) return NULL;
  Node* root = GetNewNode(int(str[i])-int('0'));
  ++i;
  if(str[i]=='?' && i<str.size())
  root->left = createTree(str,++i);
  else if (i<str.size())
  root->right = createTree(str,++i);
  return root;
}

void printTree(Node* root)
{
  queue <Node*> Q;
  Q.push(root);
  cout<<root->data<<endl;
  while(1)
  {
    if(Q.empty()) break;
    int sz = Q.size();
    while(sz--)
    {
      Node* node = Q.front();
      Q.pop();
      if (node->left) {Q.push(node->left);cout<<"left: "<<node->left->data<<" ";}
      if (node->right) {Q.push(node->right);cout<<"right: "<<node->right->data<<" ";}
    }
    cout<<endl;
  }
}
int main()
{
  string str = "1?2?3:4:5";
  Node* root=NULL;
  root = createTree(str,0);
  printTree(root);
  return 0;
}
