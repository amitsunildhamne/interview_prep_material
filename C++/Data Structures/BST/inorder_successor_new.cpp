#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
	int data;
	Node *left;
	Node *right;
};

static inline Node *GetNewNode(int data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
}

Node *Insert(Node *root, const int data)
{
	if (root == NULL) {
		root = GetNewNode(data);
	} else if (data < root->data) {
		root->left = Insert(root->left, data);
	} else {
		root->right = Insert(root->right, data);
	}

	return root;
}

void InOrderPrint(Node *root)
{
	if (NULL == root) {
		return;
	}

	InOrderPrint(root->left);
	printf("%d\n", root->data);
	InOrderPrint(root->right);
}

void InOrderSuccesor(Node *root, const int data, int *const ValToFind)
{
	static int found = 0;
	if (NULL == root) {
		return;
	}

	if (-1 == found) {
		return;
	}

	InOrderSuccesor(root->left, data, ValToFind);

	if (1 == found) {
		*ValToFind = root->data;
		found = -1;
	}

	if ((data == root->data) && (0 == found)) {
		found = 1;
	}
	InOrderSuccesor(root->right, data, ValToFind);
}

int main(void)
{
	Node* root = NULL;
	int Succesor = -1;
	int Data = 1;

	root = Insert(root,5);
	root = Insert(root,10);
	root = Insert(root,3);
	root = Insert(root,4);
	root = Insert(root,1);
	root = Insert(root,11);

	InOrderPrint(root);
	InOrderSuccesor(root, Data, &Succesor);
	printf("InOrderSuccesor for %d: %d\n", Data, Succesor);
	return 0;
}
