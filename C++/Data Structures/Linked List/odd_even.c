#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node Node;

struct Node {
	int data;
	struct Node *next;
};

void Print(Node *Head)
{
	for (Node *Curr = Head; Curr != NULL; Curr = Curr->next) {
		printf("%d\t", Curr->data);
	}
	printf("\n");
}

void Insert(Node **Head, const int data)
{
	Node *Curr;
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if (NULL == *Head) {
		*Head = node;
		return;
	}

	for (Curr = *Head; Curr->next != NULL; Curr = Curr->next) {
		;
	}

	Curr->next = node;
}

void DivideArr(Node **Arr, Node *Head)
{
	int i;
	Node *curr = Head;
	bool flag = false;
	Node *CurrE = Arr[0];
	Node *CurrO = Arr[1];

	if (NULL == Head) {
		return;
	}

	/*
	 * 0 ->  1    -> 2 -> 3 -> 4
	 * f(he) t(ho)
	 */

	while (curr != NULL) {
		if (false == flag) {
			if (NULL == Arr[0]) {
				Arr[0] = curr;
			} else {
				 CurrE->next = curr;
			}
			CurrE = curr;
		} else {
			if (NULL == Arr[1]) {
				Arr[1] = curr;
				CurrO = curr;
			} else {
				CurrO->next = curr;
			}
			CurrO = curr;
		}
		curr = curr->next;
		flag = !flag;
	}

	if (NULL != Arr[0]) {
		CurrE->next = NULL;
	}

	if (NULL != Arr[1]) {
		CurrO->next = NULL;
	}
}

int main(int argc, char *argv[])
{
	Node *Head = NULL;
	int i = 0;
	int Size;
	Node *Arr[2] = {NULL};

	if (2 != argc) {
		printf("Usage ./a.out <size>\n");
		return 1;
	}

	Size = atoi(argv[1]);
	for (i = 0; i < Size; ++i) {
		Insert(&Head, i);
	}

	DivideArr(Arr, Head);

	for (i = 0; i < 2; ++i) {
		Print(Arr[i]);
	}

	return 0;
}
