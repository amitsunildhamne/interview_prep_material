#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
};

vector<list<int>> res;

Node* Insert(int data)
{
  Node* node = new Node();
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Node* CreateBst(Node* root, int data)
{
 if (root==NULL)
 {
   root = Insert(data);
 }
 else
 {
   if(root->data>data) root->left = CreateBst(root->left,data);
   else root->right = CreateBst(root->right, data);
 }
 return root;
}

void BFS(Node* root)
{
 queue<Node*> st;
 st.push(root);
 while(1)
 {
   int nodecount = st.size();
   list<int> ls;
   if(nodecount<=0) break;
   while(nodecount>0)
   {
     Node* node = st.front();
     ls.push_back(node->data);
     st.pop();
     if(node->left!=NULL) st.push(node->left);
     if(node->right!=NULL) st.push(node->right);
     nodecount--;
   }
   res.push_back(ls);
 }
}
void print_list()
{
  vector<list<int>>::const_iterator itr;
  list<int>::const_iterator l_itr;
  for(itr = res.begin(); itr!=res.end();itr++)
  {
    for(l_itr = (*itr).begin();l_itr!=(*itr).end();l_itr++)
    {
      cout<<*l_itr<<" ";
    }
    cout<<endl;
  }
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
  BFS(root);
  print_list();
  return 0;
}
