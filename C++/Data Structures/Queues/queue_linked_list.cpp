#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node* next;
};

Node* front = NULL;
Node* back = NULL;

void Enqueue(int x)
{
  Node* node = new Node();
  node->data = x;
  node->next = NULL;
  if (front==NULL && back ==NULL)
  {
    front = node;
    back = front;
  }
  else
  {
    back->next = node;
     back = node;
  }
}

void Dequeue()
{
  Node* node = front;
  if (front==NULL)
  {
    cout<<"Queue is empty"<<endl;
    return;
  }

  if (front == back)
  {
    front =back = NULL;
    return;
  }

  front = front->next;
  free(node);
}

void print_list()
{
  Node *itr = front;
  while(itr!=NULL)
  {
    cout<<itr->data<<endl;
    itr = itr->next;
  }
}


int main()
{
  Dequeue();
  Enqueue(1);
  Enqueue(2);
  Enqueue(3);
  Enqueue(4);
  cout<<"List 1 "<<endl;
  print_list();
  Dequeue();
  cout<<"List 2 "<<endl;
  print_list();
  Enqueue(5);
  cout<<"List 3 "<<endl;
  print_list();
  return 0;
}
