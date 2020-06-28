#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
	int data;
	Node *left, *right;
};

Node *Insert(Node *root, int data)
{
	if(root == NULL) {
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

void Print(Node *root)
{
	if (root == NULL) return;
	Print(root->left);
	printf("%d\n", root->data);
	Print(root->right);
}

void BstToDll(Node *root, Node **head)
{
	if (root == NULL)
		return;

	printf("root=%d\n", root->data);

	static Node *prev = NULL;

	BstToDll(root->left, head);
	if (prev == NULL) {
		printf("root=%d prev=NULL\n", root->data);
		*head = root;
	} else {
		printf("root=%d prev=%d\n", root->data, prev->data);
		root->left = prev;
		prev->right = root;
	}
	prev = root;
	BstToDll(root->right, head);
}

void PrintDll(Node *head)
{
	while(head!=NULL) {
		printf("%d ", head->data);
		head = head->right;
	}
}

int main()
{
	Node *root = NULL;
	Node *head = NULL;
	root = Insert(root,15);
	root = Insert(root,10);
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	Print(root);
	BstToDll(root, &head);
	PrintDll(head);
	return 0;
}
