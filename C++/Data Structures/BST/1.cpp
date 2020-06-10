#include <cstdio>
#include <iostream>
#include <cstdint>
#include <queue>

using namespace std;

typedef struct BSTNode {
	uint32_t data;
	BSTNode *left, *right;
} BSTNode;

BSTNode *CreateNode(uint32_t data)
{
	BSTNode *node =  (BSTNode *)malloc(sizeof(BSTNode));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

BSTNode *Insert(BSTNode *root, uint32_t data)
{
	if( root == NULL) {
		root = CreateNode(data);
	} else if (root->data >= data) {
		root->left = Insert(root->left, data);
	} else {
		root->right = Insert(root->right, data);
	}

	return root;
}

void Print(BSTNode *root)
{
	if (root !=NULL) {
		printf("%u ",root->data);
	}

	if (root->left != NULL) {
		Print(root->left);
	}

	if(root->right != NULL) {
		Print(root->right);
	}
}

void BFS(BSTNode *root)
{
	queue<BSTNode *> Q;
	Q.push(root);
	int sz = Q.size();
	while(1) {
		if (Q.size() == 0)
			break;
		sz = Q.size();
		while(sz-->0) {
			BSTNode *temp = Q.front();
			printf("%u ", temp->data);
			Q.pop();
			if (temp->left != NULL) Q.push(temp->left);
			if (temp->right != NULL) Q.push(temp->right);
		}
		printf("\n");
	}
}

int main(void)
{
	BSTNode *root = NULL;
	root = Insert(root, 6);
	root = Insert(root, 5);
	root = Insert(root, 8);
	root = Insert(root, 4);
	root = Insert(root, 7);
	root = Insert(root, 3);
	root = Insert(root, 9);
//	Print(root);

	BFS(root);

	return 0;
}
