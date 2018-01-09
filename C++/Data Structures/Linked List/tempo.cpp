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
  node->next = NULL;
  node->data = data;
  if(head==NULL)
  {
    head = node;
    return head;
  }
  Node* curr= head;
  while(curr->next!= NULL)
  {
    curr = curr->next;
  }
  curr->next = node;
  return head;
}

Node* reverse(Node* head)
{
  if(head==NULL) return head;
  Node* curr = head;
  Node* prev = NULL;
  Node* next = curr->next;
  while(next!=NULL)
  {
    curr->next = prev;
    prev = curr;
    curr = next;
    next = next->next;
  }
  curr->next = prev;
  head = curr;
  return head;
}

Node* del(Node* head,int data)
{
  Node* prev = NULL;
  Node* curr = head;
  if(curr->data == data)
  {
    head = curr->next;
    delete curr;
    return head;
  }
  while(curr!=NULL)
  {
    if(curr->data== data)
    {
      prev->next = curr->next;
      delete curr;
    }
    prev = curr;
    curr = curr->next;
  }
  return head;
}

void print(Node* head)
{
  Node* curr = head;
  while(curr!=NULL)
  {
    cout<<curr->data<<endl;
    curr = curr->next;
  }
}

int main()
{
  Node* head = NULL;
  head = Insert(head, 2);
  head = Insert(head, 3);
  head = Insert(head, 5);
  head = Insert(head, 7);
  head = Insert(head, 9);
  head = reverse(head);
  print(head);
  cout<<endl;
  head = del(head,5);
  print(head);
  return 0;
}
