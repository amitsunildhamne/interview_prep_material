#include <iostream>

using namespace std;

struct Node
{
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
  while(curr->next)
  {
    curr = curr->next;
  }
  curr->next = node;
  return head;
}

void print(Node* head)
{
  while(head)
  {
    cout<<head->data<<" ";
    head = head->next;
  }
  cout<<endl;
}

Node* Delete(int data_to_be_found, Node* head)
{
  Node* curr = head;
  Node* prev = NULL;
  if (head==NULL) return NULL;
  if (head->data==data_to_be_found)
  {
    head= head->next;
    delete curr;
    return head;
  }
  while(curr)
  {
    prev = curr;
    curr = curr->next;
    if(curr->data == data_to_be_found)
    {
      prev->next = curr->next;
      delete curr;
      break;
    }
  }
  return head;
}

Node* Rev(Node* head)
{
  if (head==NULL) return NULL;
  Node* next;
  Node* prev=NULL;
  Node* curr = head;
  while(curr)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

Node* findIntersection(Node* head1, Node* head2)
{
  Node* p1 = head1;
  Node* p2 = head2;
  if (p1==NULL || p2==NULL) return NULL;
  while(p1!=NULL && p2!=NULL && p1!=P2)
  {
    p1=p1->next;
    p2=p2->next;
    if (p1==NULL) p1 = head2;
    if(p2==NULL) p2 = head1;
    if(p1==p2) return p1;
  }
  return NULL;
}

int main()
{
  Node* head = NULL;
  head = Insert(1,head);
  head = Insert(2,head);
  head = Insert(3,head);
  head = Insert(4,head);
  head = Insert(5,head);
  head = Delete(5,head);
  head = Rev(head);
  print(head);
  return 0;
}
