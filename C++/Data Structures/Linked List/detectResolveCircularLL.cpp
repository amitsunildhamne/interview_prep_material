#include <iostream>
using namespace std;
struct Node
{
  int value;
  Node *next;
};

Node* Insert(int value, Node* head)
{
  Node* node = new Node();
  node->value = value;
  node->next = NULL;
  if (head==NULL) return node;
  Node* curr = head;
  while(curr->next) curr = curr->next;
  curr->next = node;
  return head;
}

Node* InsertLoop(Node* head)
{
  Node* curr = head;
  Node* toLoop;
  while(curr->next!=NULL)
  {
    if (curr->value == 2) toLoop=curr;
    curr = curr->next;
  }
  curr->next = toLoop;
  return head;
}

void print_list(Node *head)
{
    Node *curr = head;
    while(curr != NULL)
    {
      cout<<curr->value<<" ";
      curr = curr->next;
    }
    cout<<endl;
}

void Remove(Node *head, Node *ptr)
{
  Node *ptr1 = head, *ptr2;
  while(1)
  {
    ptr2 = ptr;
    while(ptr2 != ptr && ptr2 != ptr1)
    {
      ptr2 = ptr2->next;
    }
    if (ptr2->next == ptr1)
    {
        ptr2->next = NULL;
        break;
    }
    ptr1 = ptr1->next;
  }
}

bool isCircularAndRemove(Node *head)
{
  Node *slowPtr = head;
  Node *fastPtr = head;
  bool ret_val = false;
  while (slowPtr !=NULL && fastPtr!=NULL && fastPtr->next != NULL )
  {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
    if (slowPtr == fastPtr)
    {
      ret_val = true;
      Remove(head, slowPtr);
      break;
    }
  }
  return ret_val;
}

int main()
{
  Node* head = NULL;
  head = Insert(1,head);
  head = Insert(2,head);
  head = Insert(3,head);
  head = Insert(4,head);
  head = Insert(5,head);
  head = InsertLoop(head);
  cout<<"Is the Linkedlist circular "<<isCircularAndRemove(head)<<endl;
  print_list(head);
  return 0;
}
