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
  if (head == NULL) head = node;
  else
  {
    Node* curr = head;
    while(curr->next!=NULL)
    {
      curr=curr->next;
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
    curr=curr->next;
  }
}

void delete_item(int data)
{
  Node* curr = head->next;
  Node* prev = head;
  if (head->data==data) {head = head->next; delete(prev);return;}
  while(curr!=NULL)
  {

    if(curr->data ==data)
    {
      prev->next = curr->next;delete(curr);
    }
    prev = curr;
    curr = curr->next;
  }
}
int main()
{
  Insert(4);
  Insert(3);
  Insert(5);
  Insert(6);
  print_list();
  cout<<"Printed List"<<endl;
  delete_item(6);
  print_list();
  cout<<"Deleted item, new list"<<endl;
  return 0;
}
