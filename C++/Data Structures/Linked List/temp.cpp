#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node* next;
};

Node* Insert(Node* head, int data)
{
  Node* node = new Node();
  node->data = data;
  node->next = NULL;
  if(head == NULL) head = node;
  else
  {
    Node* curr = head;
    while(curr->next!=NULL)
      curr = curr->next;
    curr->next = node;
  }
  return head;
}

void print(Node* head)
{
  Node* curr = head;
  while(curr!=NULL)
  {
    cout<<curr->data<<" ";
    curr= curr->next;
  }
  cout<<"\n";
}

int main()
{
  Node* head = NULL;
  head = Insert(head, 1);
  head = Insert(head, 2);
  head = Insert(head, 3);
  head = Insert(head, 4);
  head = Insert(head, 5);
  print(head);
  return 0;
}
