#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

typedef struct Node{
	int data;
	struct Node *left, *right;
} Node ;

Node *GenerateNode(int data)
{
	Node *root = (Node *)malloc(sizeof(Node));
	root->data = data;
	root->left = root->right = NULL;
	return root;
}

Node *Insert(Node *root, int data)
{
	if(root == NULL) {
		root = GenerateNode(data);
	} else if (root->data > data) {
		root->left = Insert(root->left, data);
	} else {
		root->right = Insert(root->right, data);
	}
	return root;
}

void Print(Node *root)
{
	if (root == NULL)
		return;
	Print(root->left);
	printf("%d\n", root->data);
	Print(root->right);
}

int Height(Node *root)
{
	if (root==NULL)
		return -1;
	return max(Height(root->left), Height(root->right)) + 1;
}

void BFS(Node *root)
{
	printf("BFS\n");
	queue <Node *> q;
	q.push(root);
	while(q.size() > 0 ) {
		Node *node = q.front();
		q.pop();
		printf("%d\n", node->data);
		if (node->left != NULL)
			q.push(node->left);
		if (node->right != NULL)
			q.push(node->right);
	}
}

int MinHeight(Node *root)
{
	int size = 0;
	int ret_val = 0;
	int flag =0;
	Node *node = NULL;
	queue<Node *> q;
	q.push(root);

	printf("\nMinHeight\n");
	while(1) {
		size = q.size();
		if (size == 0)
			break;
		while(size>0) {
			node = q.front();
			q.pop();
				printf("%d ", node->data);
			if ((node->left ==NULL) && (node->right==NULL)) {
				flag =1;
				break;
			}
			if (node->left != NULL)
				q.push(node->left);
			if(node->right != NULL)
				q.push(node->right);
			--size;
		}
		printf("\n");

		if (flag == 1) {
			printf("Entered here\n");
			break;
		}
		++ret_val;
	}
	return ret_val;
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
	Print(root);
	printf("%d\n", Height(root));
//	BFS(root);
	printf("MinHeight: %d\n", MinHeight(root));
	return 0;
}
