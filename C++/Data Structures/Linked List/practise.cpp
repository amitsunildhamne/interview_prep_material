#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void Insert(Node* head, int data)
{

    Node* node = new Node();
    node->next = NULL;
    node->data = data;
    if (head==NULL) head = node;
    Node* curr = head;
    while(curr->next!=NULL)
    {
      curr = curr->next;
    }
    curr->next = node;
}

void print_list(Node* head)
{
  Node* curr = head;
  while(curr)
  {
    cout<<curr->data<<" ";
  }
  cout<<endl;
}

void reverse_list(Node* head)
{
  Node* curr, next, prev;
  curr = head;
  next = head;
  prev = NULL
  while(curr)
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
  Node* head = NULL;
  Insert(1);
  Insert(2);
  Insert(3);
  Insert(4);
  cout<<"Printing Original List"<<endl;
  print_list(head);
  reverse_list(head);
  cout<<"Printing New List"<<endl;
  print_list(head);
  delete_idx(4);
}
