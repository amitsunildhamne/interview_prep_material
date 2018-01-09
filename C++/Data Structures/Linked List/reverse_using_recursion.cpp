#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node* next;
};
Node* head = NULL;

Node* Insert(Node* head, int data)
{
  Node* node = new Node();
  node->data = data;
  node->next = NULL;
  Node* curr = head;
  if (curr==NULL) head = node;
  else
  {
    while(curr->next != NULL) curr = curr->next;
    curr->next = node;
  }

  return head;
}

void reverse_recurse(Node* ptr)
{
  if (ptr->next == NULL)
  {
    head = ptr;
    return;
  }
  else
  {
    reverse_recurse(ptr->next);
    Node* q = ptr->next;
    q->next = ptr;
    ptr->next = NULL;
  }
}

void forward_print(Node* ptr)
{
  while(ptr!=NULL)
  {
    cout<<ptr->data;
    ptr = ptr->next;
  }
}
int main() {
  head = Insert(head, 1);
  head = Insert(head, 2);
  head = Insert(head, 3);
  head = Insert(head, 4);
  reverse_recurse(head);
  forward_print(head);
  return 0;
}
