#include <iostream>
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
 if (head == NULL) {head = node;}
 else
 {
   Node* curr = head;
   while(curr->next!=NULL) curr = curr->next;
   curr->next = node;
 }
 return head;
}

void print_list(Node* head)
{
 Node* curr = head;
 while(curr!=NULL)
 {
   cout<<curr->data<<endl;
   curr = curr->next;
 }
}

Node* sortList(Node* head) {
       if (head == NULL || head->next == NULL)
           return head;

       Node* slow = head;
       Node* fast = head->next;

       while (fast != NULL && fast->next != NULL)
       {
           slow = slow->next;
           fast = fast->next->next;
       }
       //divide the list into two parts
       fast = slow->next;
       slow->next = NULL;

       return merge(sortList(head), sortList(fast));
   }

   Node* merge(Node* l1, Node* l2)
   {
       Node dump(0);
       Node* cur = &dump;

       while (l1 != NULL && l2 != NULL)
       {
           if (l1->val < l2->val)
           {
               cur->next = l1;
               l1 = l1->next;
           }
           else
           {
               cur->next = l2;
               l2 = l2->next;
           }

           cur = cur->next;
       }

       if (l1 != NULL)
           cur->next = l1;
       else
           cur->next = l2;

       return dump.next;
   }




int main()
{
  Node* head = NULL;
  head = Insert(head, 7);
  head = Insert(head, 5);
  head = Insert(head, 3);
  head = Insert(head, 6);
  print_list(head);
  head = sort_list(head);
  return 0;
}
