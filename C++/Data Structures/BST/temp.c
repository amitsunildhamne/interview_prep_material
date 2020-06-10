#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <queue>

using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

Node *GenerateNode(int data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

Node *Insert(Node *root, int data)
{
	if (root == NULL) {
		Node *node = GenerateNode(data);
		root = node;
	} else if (root->data > data) {
		root->left = Insert(root->left, data);
	} else if (root->data <= data) {
		root->right = Insert(root->right, data);
	}

	return root;
}

void Print(Node *root)
{
	if (root==NULL)
		return;
	Print(root->left);
	printf("%d\t", root->data);
	Print(root->right);
}

int MaxHeight(Node *root)
{
	if (root == NULL)
		return 0;
	return max(MaxHeight(root->left), MaxHeight(root->right))+1;
}

int NoN(Node *root)
{
	if (root == NULL)
		return 0;
	return NoN(root->left) + NoN(root->right) + 1;
}

void bfs(Node *root)
{
	queue<Node*> Q;
	if (root==NULL)
		return;
	Q.push(root);
	printf("BFS:\t");
	while(Q.empty() != true) {
		Node *temp = Q.front();
		Q.pop();
		printf("%d\t",temp->data);
		if (temp->left != NULL)
			Q.push(temp->left);
		if (temp->right != NULL)
			Q.push(temp->right);
	}
	printf("\n");
}

void modified_bfs(Node *root)
{
	int size = 0, MinHght = 0, flag = 0;
	queue<Node *> Q;
	if (root==NULL)
		return;
	
	Q.push(root);
	printf("Modified BST\n");
	MinHght = 1;
	while(1) {
		size = Q.size();
		if (size == 0)
			break;
		while(size > 0) {
			Node *temp = Q.front();
			printf("%d\t", temp->data);
			Q.pop();
			if (temp->left != NULL)
				Q.push(temp->left);
			if (temp->right!=NULL)
				Q.push(temp->right);
			if ((temp->left == NULL) && (temp->right == NULL))
				flag = 1;
			--size;
		}
		if (flag==0)
			++MinHght;
		printf("\n");
	}
	printf("END\n");
	printf("MinHght: %d\n", MinHght);
}

int IsBstHelper(Node *root, int min, int max)
{
	if (root==NULL)
		return 1;
	if ((root->data >= min) &&
		(root->data<max) &&
		(IsBstHelper(root->left, min, root->data)) &&
		(IsBstHelper(root->right, root->data, max)) )
		return 1;
	return 0;
}

int isBST(Node *root)
{
	int min = INT_MIN;
	int max = INT_MAX;
	return IsBstHelper(root, min, max);
}

int main(void)
{
	Node *root = NULL;
	root = Insert(root,15);
	root = Insert(root,10);
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	root = Insert(root, 27);
	root = Insert(root, 29);
	Print(root);
	printf("\n");
	printf("Number of Nodes: %d\n",NoN(root));
	printf("MaxHght:0x%x\n", MaxHeight(root));
	bfs(root);
	modified_bfs(root);
	isBST(root);

	return 0;
}
