#include <iostream>

using namespace std;

struct Node
{
  int value;
  Node *next;
};

Node *Insert(Node* head, int value)
{
  Node *node = new Node();
  node->value = value;
  node->next  = NULL;
  if (head == NULL)
  {
    return node;
  }
  Node * curr = head;
  while(curr->next != NULL)
  {
    curr = curr->next;
  }
  curr->next = node;
  return head;
}

Node *Delete(Node *head, int value)
{
  if (head == NULL)
  {
    return NULL;
  }

  Node *curr = head;
  Node *prev = NULL;

  while(curr != NULL)
  {
     if (curr->value == value)
     {
       if (curr != head)
       {
         prev->next = curr->next;

       }
       else
       {
         head = head->next;
       }
         delete(curr);
         return head;
     }
     prev = curr;
     curr = curr->next;
  }
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

Node *reverse(Node *head)
{
  Node *curr = head;
  Node *prev = NULL, *next = head;
  while(curr != NULL)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
  return head;
}


Node *merge_list(Node *head1, Node *head2)
{
  Node *curr1 = head1;
  Node *curr2 = head2;
  Node *res_node = new Node();
  Node *head = res_node;
  res_node->value = 0;
  res_node->next = NULL;
  while(curr1 != NULL && curr2 != NULL)
  {
    if (curr1->value <= curr2->value)
    {
      res_node->next = curr1;
      curr1 = curr1->next;
    }
    else
    {
      res_node->next = curr2;
      curr2 = curr2->next;
    }
    res_node = res_node->next;
  }

  if (curr1 != NULL)
  {
    res_node->next = curr1;
  }
  else if (curr2 != NULL)
  {
    res_node->next = curr2;
  }
  else
  {
    cout<<"ERROR"<<endl;
  }

  res_node = head;
  head = head->next;
  delete(res_node);
  return head;
}

Node *sort_list(Node *head)
{
  if (head == NULL || head->next == NULL)
  {
    return head;
  }
  Node *slowPtr = head;
  Node *fastPtr = head->next;

  while (slowPtr != NULL && fastPtr != NULL && fastPtr->next != NULL)
  {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
  }
  fastPtr = slowPtr->next;
  slowPtr->next = NULL;
  return merge_list( sort_list(head), sort_list(fastPtr));
}

int main()
{
  Node *head = NULL;
  head = Insert(head, 5);
  head = Insert(head, 2);
  head = Insert(head, 6);
  head = Insert(head, 3);
  head = Insert(head, 1);
  print_list(head);
  Delete(head, 6);
  print_list(head);
  head = reverse(head);
  print_list(head);
  head = sort_list(head);
  print_list(head);
  return 0;
}
