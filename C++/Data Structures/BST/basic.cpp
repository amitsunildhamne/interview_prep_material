#include <iostream>

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
  node->left = NULL;
  node->right = NULL;
  return node;
}

Node* Insert(Node* root, int data)
{
  if (root==NULL)
    root = GetNewNode(data);
  else if (root->data >=  data)
    root->left = Insert(root->left, data);
  else
    root->right = Insert(root->right, data);
  return root;
}

bool Search(Node* root, int data)
{
  if (root==NULL) return false;
  else if (root->data == data)
    return true;
  else if (root->data >= data)
    return Search(root->left, data);
  else return Search(root->right, data);
}

int main()
{
  Node* root;
	root = Insert(root,15);
	root = Insert(root,10);
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
  int number;
  	cout<<"Enter number be searched\n";
  	cin>>number;
  	//If number is found, print "FOUND"
  	if(Search(root,number) == true) cout<<"Found\n";
  	else cout<<"Not Found\n";
  return 0;
}
