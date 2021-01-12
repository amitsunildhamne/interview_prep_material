#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next, *prev;
} Node;

Node *GetNewNode(int data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = node->prev = NULL;
	return node;
}

void InsertNode(Node **head, Node **tail, int data)
{
	Node *curr = *head;
	Node *node = GetNewNode(data);

	if (NULL == curr && NULL == *tail) {
		*head = *tail = node;
		return;
	}

	(*tail)->next = node;
	node->prev = *tail;
	*tail = node;
}

void PrintList(Node *head)
{
	while(head) {
		printf("%d\t", head->data);
		head = head->next;
	}
	printf("\n");
}

void PrintListRev(Node *head)
{
	while(head) {
		printf("%d\t", head->data);
		head = head->prev;
	}
	printf("\n");
}

void DeleteNode(Node **head, int data)
{
	Node *curr = *head;
	if (NULL == curr)
		return;

	while (NULL != curr) {

		curr = curr->next;
	}
}

int main(void)
{
	Node *head = NULL;
	Node *tail = NULL;
	InsertNode(&head, &tail, 5);
	InsertNode(&head, &tail, 4);
	InsertNode(&head, &tail, 3);
	InsertNode(&head, &tail, 2);
	InsertNode(&head, &tail, 1);
	PrintList(head);
	PrintListRev(tail);
//	DeleteNode(&head, 5);
//	DeleteNode(&head, 2);
//	DeleteNode(&head, 7);
//	ReverseNode(&head);
	PrintList(head);

	return 0;
}
