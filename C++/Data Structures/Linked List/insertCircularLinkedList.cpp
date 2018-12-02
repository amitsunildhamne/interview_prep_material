/*
Insert value in a circular linked list such that value should be lower than next
and greater than previous. Duplicates allowed
*/
#include <iostream>
using namespace std;

struct Node
{
  int value;
  Node *next;
};

Node *Insert( int value, Node *head)
{
  Node *node = new Node();
  node->value = value;
  node->next = NULL;
  Node *curr = head;
  if (curr == NULL)
  {
    head = node;
    node->next = node;
  }
  else if (curr->value > value)
  {
    while( curr->next != head)
    {
      curr = curr->next;
    }
    curr->next = node;
    node->next = head;
    head = node;
  }
  else
  {
    Node *curr = head;
    while(curr->next != head && curr->next->value < value)
    {
      curr = curr->next;
    }
    Node *temp = curr->next;
    curr->next = node;
    node->next = temp;
  }
  return head;
}

void print_list(Node *head)
{
  Node *curr = head;
  if (head == NULL)
  return;
  do
  {
    cout<<curr->value<<" ";
    curr = curr->next;
  } while(curr!=head);
}

int main()
{
  Node* head = NULL;
  head = Insert(2, head);
  head = Insert(3, head);
  head = Insert(5, head);
  head = Insert(9, head);
  head = Insert(10, head);
  head = Insert(2, head);
  head = Insert(1, head);
  print_list(head);
  return 0;
}
