#include <iostream>
using namespace std;

struct Node
{
  Node* next;
  int data;
};

 Node* Insert(Node* head; int data)
 {
   Node* node = new Node();
   node->next = NULL;
   node->data = data;
   if(head==NULL) head = node;
   Node* curr = head;
   while(curr->next !=NULL)
 }

int main()
{
  return 0;
}
