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

  if (curr==NULL) head = node;
  else
  {
    while(curr->next!=NULL) curr = curr->next;
    curr->next=node;
  }
}

void rev_rec(Node* node)
{
  if (node==NULL)
  {
  ; return ;
  }
   rev_rec(node->next);
  cout<<node->data<<endl;
  return ;
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
int main()
{

  Insert( 2);
  Insert( 3);
   Insert(4);
   Insert(5); rev_rec(head);
print_list();
  return 0;
}
