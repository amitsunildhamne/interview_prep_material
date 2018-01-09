#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

Node* Insert(Node* head,int data)
{
  Node* node = new Node();
  node->data = data;
  node->next = NULL;
  Node* curr = head;
  if(curr==NULL) head = node;
  else
  {
    while(curr->next!=NULL) curr = curr->next;
    curr->next = node;
  }
  return head;
}

int calculate(Node* head)
{
 stack<int> stak;
 int sum=0;
 Node* curr = head;
 while(curr!=NULL)
 {
   stak.push(curr->data);
   curr = curr->next;
 }
while(!stak.empty())
{
  sum+= stak.top()*pow(10,(stak.size()-1));
  cout<<sum<<endl;
  stak.pop();
}
return sum;
}
int main()
{
  Node* head1 = NULL;
  Node* head2 = NULL;
  head1 = Insert(head1, 7);
  head1 = Insert(head1, 1);
  head1 = Insert(head1, 6);
  head2 = Insert(head2, 5);
  head2 = Insert(head2, 9);
  head2 = Insert(head2, 2);
  int a = calculate(head1);
  cout<<"Completed Initializing head2"<<endl;
  int b = calculate(head2);
  int sum = a+b;
  cout<<sum<<endl;
  return 0;
}
