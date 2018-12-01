/*
Save all leaf nodes of a Binary tree in a Doubly Linked List by using Right node
as Next node and Left Node as Previous Node
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct BSTNode
{
  int value;
  BSTNode *left, *right;
};

BSTNode *DFS(BSTNode **head, BSTNode *root)
{
  if (root == NULL)
  {
    return root;
  }
  if (root->left == NULL && root->right == NULL)
  {
    cout<<"Debug"<<endl;
    root->right = *head;
    if (*head != NULL)
    {
      (*head)->left = root;
    }
    *head = root;
    return NULL;
  }
  root->right = DFS(head, root->right);
  root->left  = DFS(head, root->left);
  return root;
}
BSTNode *GetNewNode(int value)
{
  BSTNode *node = new BSTNode();
  node->value = value;
  node->left = node->right = NULL;
  return node;
}

BSTNode *Insert(BSTNode *root, int value)
{
  if (root == NULL)
  {
    return GetNewNode(value);
  }
  else if (root->value > value)
  {
    root->left = Insert(root->left, value);
  }
  else
  {
    root->right = Insert(root->right, value);
  }
  return root;
}

void printlist(BSTNode *head)
{
    BSTNode *curr = head;
    while(curr != NULL)
    {
      cout<<curr->value<<" ";
      curr = curr->right;
    }
    cout<<endl;
}


int main()
{
  BSTNode *root = NULL;
  BSTNode *head = NULL;
  root = Insert(root,15);
  root = Insert(root,10);
  root = Insert(root,20);
  root = Insert(root,25);
  root = Insert(root,8);
  root = Insert(root,12);
  root = Insert(root, 27);
  root = Insert(root, 29);
  head = DFS(&head,root);
  printlist(head);
  return 0;
}
