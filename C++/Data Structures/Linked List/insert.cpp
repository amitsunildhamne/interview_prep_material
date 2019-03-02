#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	Node *next;
};

Node *Insert(int data, Node *head)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if (head == NULL)
	{
		return node;
	}
	else
	{
		Node *curr = head;
		while(curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = node;
	}
	return head;
}

void printList(Node *head)
{
	while(head != NULL)
	{
		printf("%d\t", head->data);
		head = head->next;
	}
	printf("\n");
}

Node *InsertAtPos(int data, int pos, Node *head)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	
	if (pos == 1 || head == NULL)
	{
		node->next = head;
		head = node;
	}
	else
	{
		Node *curr = head, *prev;
		int count = 1;
		while( curr != NULL)
		{
			++count;
			prev = curr;
			curr = curr->next;
			if (pos == count)
			{
				prev->next = node;
				node->next = curr;
			}
		}
	}
	return head;
}

int main()
{
	Node *head = NULL;
	head = InsertAtPos(7 , 2, head);
	head = Insert(1, head);
  	head = Insert(2, head);
  	head = Insert(3, head);
  	head = Insert(4, head);
	printList(head);
	head = InsertAtPos(7 , 2, head);
	//head = InsertAtPos(8 , 5, head);
	printList(head);
	return 0;
}