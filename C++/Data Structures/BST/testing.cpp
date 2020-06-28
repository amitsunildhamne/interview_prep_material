#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

Node *Insert(Node *root, int data)
{
	if (root==NULL) {
		root = (Node *)malloc(sizeof(Node));
		root->data = data;
		root->left = root->right = NULL;
	} else if (root->data > data) {
		root->left = Insert(root->left, data);
	} else {
		root->right = Insert(root->right, data);
	}
	return root;
}

Node *GetNewNode(int data)
{
	Node *root = (Node *)malloc(sizeof(Node));
	root->data = data;
	root->left = root->right = NULL;
	return root;
}

Node* Insert_b(Node* root, int data)
{
  if(root==NULL) root = GetNewNode(data);
  else if (root->data > data) root->right = Insert(root->left, data);
  else root->left = Insert (root->right, data);
  return root;
}

void Print(Node *root)
{
	if (root == NULL) return;
	Print(root->left);
	printf("%d\n", root->data);
	Print(root->right);
}

int Search(Node *root, int data)
{
	if (root == NULL) {
		return 0;
	} else if (root->data == data) {
		return 1;
	} else if (root->data < data) {
		return Search(root->right, data);
	} else{
		return Search(root->left, data);;
	}
}

int IsBst(Node *root, int min, int max)
{
	if (root == NULL)
		return 1;
	if (IsBst(root->left, min, root->data) && IsBst(root->right, root->data, max) && (root->data >= min) && (root->data < max))
		return 1;
	return 0;
}

int Height(Node *root)
{
	if (root==NULL)
		return 0;
	return max(Height(root->left), Height(root->right))+1;
}

void BFS(Node * root)
{
	queue<Node *> Q;
	Q.push(root);
	Node *node;
	while(!Q.empty()) {
		node = Q.front();
		printf("%d\n", node->data);
		Q.pop();
		if(node->left)
			Q.push(node->left);
		if(node->right)
			Q.push(node->right);
	}
	printf("\n");
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
	//root = Insert_b(root,1);
	Print(root);
	printf("Present: %d\n",Search(root, 21));
	printf("IsBst: %d\n", IsBst(root, INT_MIN, INT_MAX));
	printf("Height: %d\n",Height(root));
	BFS(root);
	return 0;
}
