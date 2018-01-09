#include <iostream>
#include <vector>

using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
};
vector <int> v;
Node* CreateBst(int start, int end)
{
  if(end<start) return NULL;
  int mid = (start+end)/2;
  Node* node = new Node();
  node->data = v[mid];
  node->left = CreateBst(start, mid-1);
  node->right = CreateBst(mid+1,end);
}

void PrintBST(Node* node)
{
  if(node==NULL) return;
  PrintBST(node->left);
  cout<<node->data;
  PrintBST(node->right);
}

int main()
{
  v.push_back(2);
  v.push_back(4);
  v.push_back(7);
  v.push_back(8);
  v.push_back(9);
  v.push_back(10);
  v.push_back(11);
  Node* root = NULL;
  root = CreateBst(0, v.size()-1);
  PrintBST(root);
  return 0;
}
