#include <iostream>
#include <cstdlib>
#include <unordered_map>

using namespace std;

struct Node {
	int data;
	Node *next;
};

Node *Insert(int data, Node *head)
{
	Node *curr = NULL;
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if (head == NULL) {
		head = node;
		goto done;
	}
	curr = head;
	while(curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = node;

done:
	return head;
}

void Print(Node *head)
{
	while(head != NULL) {
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void RemoveDup(Node *head)
{
	unordered_map <int, int> MyMap;

	Node *curr = head;
	Node *prev = NULL;
	while(curr != NULL) {
		if (MyMap.find(curr->data) != MyMap.end()) {
			prev->next = curr->next;
			free(curr);
			curr = prev->next;
			if (curr != NULL)
				MyMap[curr->data] = 1;
			continue;
		}
		MyMap[curr->data] = 1;
		prev = curr;
		curr = curr->next;
	}
}

int main(void)
{
	Node *head = NULL;
	head = Insert(1, head);
	head = Insert(2, head);
	head = Insert(3, head);
	head = Insert(2, head);
	head = Insert(1, head);
	Print(head);
	RemoveDup(head);
	Print(head);
	return 0;
}
