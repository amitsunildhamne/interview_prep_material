#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
	int data;
	struct Node *next, *prev;
} Node;

void PrintList(Node *head, Node *tail)
{
	Node *curr = head;
	printf("ForwardList:\t");
	while(curr!=NULL) {
		printf("%d\t", curr->data);
		curr = curr->next;
	}
	printf("\nBackwardList:\t");
	curr = tail;
	while(curr!=NULL) {
		printf("%d\t",curr->data);
		curr = curr->prev;
	}
	printf("\n");
}

void InsertNode(Node **head, Node **tail, int data)
{
	Node *curr = *tail;
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = node->prev = NULL;

	if ((*head==NULL) && (*tail==NULL)) {
		*head = *tail = node;
		return;
	}

	curr->next = node;
	node->prev = curr;
	*tail = node;
}

int FindMiddleElement(Node *head, Node *tail)
{
	int ret_val = INT_MIN;
	Node *curr_fwd = head, *curr_rwd = tail;
	if(curr_fwd==NULL)
		goto done;
	while((curr_fwd!=curr_rwd) &&
		  ((curr_rwd->prev != curr_fwd) && (curr_fwd->next != curr_rwd))) {
		curr_fwd = curr_fwd->next;
		curr_rwd = curr_rwd->prev;
	}

	ret_val = curr_fwd->data;

done:
	return ret_val;
}

void ReverseList(Node **head, Node **tail)
{
	Node *curr = *head;
	while(curr!=NULL) {
		Node *temp = curr->next;
		curr->next = curr->prev;
		curr->prev = temp;
		curr = curr->prev;
	}
	curr = *head;
	*head = *tail;
	*tail = curr;
}

int main(void)
{
	Node *head = NULL, *tail = NULL;
	InsertNode(&head,&tail, 5);
	InsertNode(&head,&tail, 4);
	InsertNode(&head,&tail, 3);
	InsertNode(&head,&tail, 2);
	InsertNode(&head,&tail, 1);
	PrintList(head, tail);

	/* Delete at pos */
//	DeleteNode(&head, &tail, 2);
//	DeleteNode(&head, &tail, 0);
//	PrintList(head, tail);

	printf("Middle element: %d\n", FindMiddleElement(head,tail));

	ReverseList(&head, &tail);
	PrintList(head, tail);

	return 0;
}

