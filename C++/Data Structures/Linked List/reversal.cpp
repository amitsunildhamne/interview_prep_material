#include <iostream>
using namespace std;
struct Node
{
  int data;
  Node* next;
};

Node* head = NULL;

void Insert(int data)
{
  Node* node = new Node();
  node->data = data;
  node->next = NULL;
  Node* curr = head;
  if (head == NULL) head = node;
  else
  {
    while(curr->next!=NULL)
    {
      curr = curr->next;
    }
    curr->next = node;
  }
}

void print_list()
{
  Node* curr = head;
  while(curr!=NULL)
  {
    cout<<curr->data<<endl;
    curr = curr->next;
  }
}

void reverse_list()
{
    Node* curr;
    Node* prev;
    Node* next;
    curr = head;
    prev = NULL;
    next = head;
  
    while(curr!=NULL)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    head = prev;
}

int main()
{
  Insert(1);
  Insert(2);
  Insert(3);
  Insert(4);
  cout<<"Printing Original List"<<endl;
  print_list();
  reverse_list();
  cout<<"Printing New List"<<endl;
  print_list();
  return 0;
}
