#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	unsigned int data;
	struct Node *next;
} Node;

Node *create_node(unsigned int data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

 Node *InsertNode(Node *head,unsigned int data)
{
	Node *node = create_node(data);
	if (head == NULL) {
		head = node;
	} else {
		Node *curr = head;
		while(curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = node;
	}

	return head;
}

Node *DeleteNode(Node *head,unsigned int pos)
{
	Node *curr = head, *prev = NULL;
	unsigned int itr = 0;

	if (head == NULL) {
		printf("Empty list\n");
	} else if (pos == itr) {
		head = head->next;
		free(curr);
	} else {
		curr = curr->next;
		prev = curr;
		++itr;
		while(curr != NULL) {
			if (pos == itr) {
				prev->next = curr->next;
				free(curr);
				break;
			}
			++itr;
			prev = curr;
			curr = curr->next;
		}
	}

	return head;
}

unsigned int FindMiddleElement(Node *head)
{
	Node *FastPtr = head, *SlowPtr = head;
	while ((FastPtr != NULL) && (FastPtr->next != NULL)) {
		SlowPtr = SlowPtr->next;
		FastPtr = FastPtr->next->next;
	}
	return SlowPtr->data;
}

void PrintList(Node *head)
{
	printf("List Data:\n");
	while(head != NULL) {
		printf("%u ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

Node *ReverseList(Node *head)
{
	Node *curr = head, *prev = NULL, *next = NULL;
	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

int main()
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

	printf("Middle element: %u\n", FindMiddleElement(head));

	head = ReverseList(head);
	PrintList(head);
	return 0;
}
