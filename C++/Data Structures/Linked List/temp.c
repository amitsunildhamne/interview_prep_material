#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Node{
	int data;
	struct Node *next;
}Node;

Node *DeleteNode(Node *head, int pos)
{
	Node *curr = head, *prev = NULL;
	int i=0;
	if (head == NULL)
		return head;

	if (pos == 0) {
		head = head->next;
		free(curr);
	} else {
		while(curr!=NULL) {
			if ((i == pos) && (prev!=NULL) && (prev->next!=NULL)) {
				prev->next = curr->next;
				free(curr);
				break;
			}
			prev = curr;
			curr = curr->next;
			++i;
		}
	}

	return head;
}

Node *InsertNode(Node *head, int data)
{
	Node *curr = head;
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if (head == NULL) {
		head = node;
	} else {
		while(curr->next!=NULL)
			curr = curr->next;
		curr->next = node;
	}

	return head;
}

Node *ReverseList(Node *head)
{
	Node *curr=head, *prev=NULL, *next=NULL;

	while(curr!=NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;

	return head;
}

void PrintList(Node *head)
{
	while(head!=NULL) {
		printf("%d\t",head->data);
		head = head->next;
	}
	printf("\n");
}

int FindMiddleElement(Node *head)
{
	int ret_val = INT_MIN;
	Node *fast_ptr = head, *slow_ptr = head;
	if ((fast_ptr==NULL) || (fast_ptr->next==NULL))
		return (fast_ptr==NULL?ret_val:fast_ptr->data);

	while((fast_ptr!=NULL) && (fast_ptr->next!=NULL)) {
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
	}
	return slow_ptr->data;
}

int main(void)
{
	Node *head = NULL;
	head = InsertNode(head, 5);
	head = InsertNode(head, 4);
	head = InsertNode(head, 3);
	head = InsertNode(head, 2);
	head = InsertNode(head, 1);
	PrintList(head);

	/* Delete at pos */
	head = DeleteNode(head, 2);
	head = DeleteNode(head, 0);
	PrintList(head);

	printf("Middle element: %d\n", FindMiddleElement(head));

	head = ReverseList(head);
	PrintList(head);

	return 0;
}
