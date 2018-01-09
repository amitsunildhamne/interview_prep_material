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
  Node* curr = head;
  if(curr == NULL)
  head = node;
  else
  {
    while(curr->next!=NULL)
    {
      curr = curr->next;
    }
    curr->next = node;
  }

  return head;
}

void problem(Node* head, int x)
{
  Node* slow_ptr = head;
  Node* fast_ptr = head->next;
  int temp;
  while(fast_ptr != NULL)
  {

    if(slow_ptr->data>x && fast_ptr->data<x)
    {
      temp = slow_ptr->data;
      slow_ptr->data = fast_ptr->data;
      fast_ptr->data = temp;
    }
    slow_ptr = slow_ptr->next;
    fast_ptr = fast_ptr->next;
  }
}

void print_list(Node* head)
{
  Node* curr = head;
  cout<<"///// Printing List /////////"<<endl;
  while(curr!=NULL)
  {
    cout<<curr->data<<" ";
    curr = curr->next;
  }
  cout<<"\n";
}

int main()
{
  Node* head = NULL;
  head = Insert(head,3);
  head = Insert(head,6);
  head = Insert(head,10);
  head = Insert(head,1);
  head = Insert(head,7);
  head = Insert(head, 11);
  head = Insert(head, 8);
  print_list(head);
  problem(head, 9);
  print_list(head);
  return 0;
}
