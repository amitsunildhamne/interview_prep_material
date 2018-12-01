#include <iostream>

using namespace std;

struct Node
{
  int value;
  Node *left;
  Node *right;
};

Node *Insert(Node *root, int value)
{
  if (root == NULL)
  {
    return GetNewNode(value);
  }
  else if (root->value < value)
  {
    root->right = Insert(root->right, value);
  }
  else
  {
    root->left = Insert(root->left, value);
  }
  return root;
}

int distFromRoot(Node *root, int point)
{
  if (!root || point==root->value)
  return 0;
  else if (root->value > point)
   return distFromRoot(root->left, point)+1;
  else
  return distFromRoot(root->right, point)+1;

}

int shortestDist(int point1, int point2)
{
  if (!root || (point1 == point2))
  return 0;
  if (point2 > point1)
  {
    return shortestDist(root, point2, point1);
  }
  if (root->value > point1 && root->value > point2)
  {
    retrun shortestDist(root->left, point1, point2)
  }
  else if (root->value < point1 && root->value < point2)
  {
    return shortestDist(root->right, point1, point2)
  }
  else
  {
    return distFromRoot(root, point1) + distFromRoot(root, point2);
  }
}

int main()
{
  Node *root = NULL;
  root = Insert(root,15);
  root = Insert(root,10);
  root = Insert(root,20);
  root = Insert(root,25);
  root = Insert(root,8);
  root = Insert(root,12);
  root = Insert(root, 27);
  root = Insert(root, 29);
  int point1 = 15;
  int point2 = 27;
  cout<<"Distance between "<<point1<<" "<<point2<<" "<<shortestDist(point1, point2)<<endl;
  return 0;
}
