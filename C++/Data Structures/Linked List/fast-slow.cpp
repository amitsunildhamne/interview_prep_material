/*Example for fast pointer and slow pointer*/
#include <iostream>

using namespace std;

struct Node{
  int data;
  Node* next;
};

Node* Insert(int data, Node* head)
{
  Node* node = new Node();
  node->data = data;
  node->next = NULL;
  if (head==NULL) return node;
  Node* curr = head;
  while(curr->next) curr = curr->next;
  curr->next = node;
  return head;
}

void Print(Node* head)
{
  while(head)
  {
    cout<<head->data<<" ";
    head = head->next;
  }
  cout<<endl;
}

Node* InsertLoop(Node* head)
{
  Node* curr = head;
  Node* toLoop;
  while(curr->next!=NULL)
  {
    if (curr->data == 2) toLoop=curr;
    curr = curr->next;
  }
  curr->next = toLoop;
  return head;
}

bool isCircular(Node* head)
{
  if (head==NULL) return false;
  Node* fastPtr=head->next;
  Node* slowPtr=head;
  while(fastPtr)
  {
    fastPtr = fastPtr->next->next;
    slowPtr = slowPtr->next;
    if(slowPtr==fastPtr) {break;}
  }
  if(fastPtr==NULL) return false;
  else return true;
}

int main()
{
  Node* head = NULL;
  head = Insert(1,head);
  head = Insert(2,head);
  head = Insert(3,head);
  head = Insert(4,head);
  head = Insert(5,head);
  //head = InsertLoop(head);
  cout<<"Is the Linkedlist circular "<<isCircular(head)<<endl;
  return 0;
}
