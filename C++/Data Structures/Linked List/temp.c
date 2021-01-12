#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

Node *GetNewNode(int data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

void InsertNode(Node **head, int data)
{
	if (NULL == *head) {
		*head = GetNewNode(data);
		goto done;
	}

	if (NULL == (*head)->next) {
		(*head)->next = GetNewNode(data);
		goto done;
	}

	InsertNode(&(*head)->next, data);

done:
	return;
}

void InsertNodeItr(Node **head, int data)
{
	Node *curr = *head;
	Node *node = GetNewNode(data);

	if (NULL == *head) {
		*head = node;
	}

	while ((NULL != curr) && (NULL != curr->next)) {
		curr = curr->next;
	}

	curr->next = node;
}

void PrintList(Node *head)
{
	while(NULL != head) {
		printf("%d\t", head->data);
		head = head->next;
	}
	printf("\n");
}

void DeleteNode(Node **head, int data)
{
	Node *curr = *head, *prev = NULL;

	while ((NULL != curr)) {
		if (data == curr->data) {
			if (prev != NULL) {
				prev->next = curr->next;
			} else {
				*head = curr->next;
			}
			free(curr);
			curr = NULL;
			break;
		}
		prev = curr;
		curr = curr->next;
	}
}

void ReverseNode(Node **head)
{
	Node *curr = *head, *prev = NULL, *next;

	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	*head = prev;
}

int main(void)
{
	Node *head = NULL;
	InsertNode(&head, 5);
	InsertNode(&head, 4);
	InsertNode(&head, 3);
	InsertNode(&head, 2);
	InsertNode(&head, 1);
	DeleteNode(&head, 5);
	DeleteNode(&head, 2);
	ReverseNode(&head);
	PrintList(head);
	return 0;
}
