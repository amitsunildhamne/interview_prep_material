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

  if (curr==NULL) head = node;
  else
  {
    while(curr->next!=NULL) curr = curr->next;
    curr->next=node;
  }
  return head;
}
void forward_print_recurse(Node* ptr)
{
  if (ptr==NULL) return;


    cout<<ptr->data<<endl;
    forward_print_recurse(ptr->next);

}

void reverse_print_recurse(Node* ptr)
{
  if (ptr==NULL) return;
  else{
    reverse_print_recurse(ptr->next);
    cout<<ptr->data<<endl;
}
}
int main()
{
  Node* head = NULL;
  head = Insert(head, 2);
  head = Insert(head, 3);
  head = Insert(head, 4);
  head = Insert(head, 5);
  //forward_print_recurse(head);
  reverse_print_recurse(head);
  return 0;
}
