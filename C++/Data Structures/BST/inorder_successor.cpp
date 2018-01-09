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
}

Node* Insert(Node* root, int data)
{
  if (root==NULL) root = GetNewNode(data);
  else if (root->data>data) root->left = Insert(root->left, data);
  else if (root->data<data) root->right = Insert(root->right, data);
  return root;
}

Node* Find(Node* root, int data)
{
  if (root==NULL) return NULL;
  else if (root->data == data) return root;
  else if (root->data > data) return Find(root->left, data);
  else if (root->data < data) return Find(root->right, data);

}

Node* FindMin(Node* root)
{
  if (root == NULL) return NULL;
  while(root->left!=NULL)
  {
    root = root->left;
  }
  return root;
}

Node* GetSuccessor(Node* root, int data)
{
  Node* current = Find(root, data);
  if (current == NULL) return NULL;
  else if (current->right!=NULL)
  {
    return FindMin(root->right);
  }
  else
  {
    Node* successor = NULL;
    Node* ancestor = root;
    while (ancestor != current)
    {
      if(current->data < ancestor->data)
      {
        successor = ancestor;
        ancestor = ancestor->left;
      }
      else
      ancestor = ancestor->right;
    }
    return successor;
  }
}

void Inorder(Node* root)
{
  if (root == NULL) return;
  Inorder(root->left);
  cout<<root->data<<endl;
  Inorder(root->right);
}

int main()
{
  /*Code To Test the logic
	  Creating an example tree
	        5
			   / \
			  3   10
			 / \   \
			1   4   11
    */
	Node* root = NULL;
	root = Insert(root,5); root = Insert(root,10);
	root = Insert(root,3); root = Insert(root,4);
	root = Insert(root,1); root = Insert(root,11);

	//Print Nodes in Inorder
	cout<<"Inorder Traversal: ";
	Inorder(root);
	cout<<"\n";

	// Find Inorder successor of some node.
	struct Node* successor = GetSuccessor(root,1);
	if(successor == NULL) cout<<"No successor Found\n";
	else
    cout<<"Successor is "<<successor->data<<"\n";
  return 0;
}
