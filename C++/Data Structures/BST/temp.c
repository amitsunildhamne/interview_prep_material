#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
	int data;
	Node *left;
	Node *right;
};

Node *Insert(Node *root, int data)
{
	if (root == NULL) {
		root = (Node *)malloc(sizeof(int));
		root->left = NULL;
		root->right = NULL;
		root->data = data;
	} else if (root->data < data) {
		root->right = Insert(root->right, data);
	} else {
		root->left = Insert(root->left, data);
	}

	return root;
}

void Inorder(Node *root)
{
	if (NULL == root) {
		return;
	}
	Inorder(root->left);
	printf("%d\t", root->data);
	Inorder(root->right);
}



int main(void)
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
	root = Insert(root,5);
	root = Insert(root,10);
	root = Insert(root,3);
	root = Insert(root,4);
	root = Insert(root,1);
	root = Insert(root,11);

	//Print Nodes in Inorder
	printf("Inorder Traversal:\n");
	Inorder(root);
	printf("\n");

	// Find Inorder successor of some node.
	Node* successor = -1;
	GetSuccessor(root,1, successor);
	if(successor == NULL)
		printf("No successor Found\n");
	else
		printf("Successor is %d\n", successor->data);
	return 0;
}
