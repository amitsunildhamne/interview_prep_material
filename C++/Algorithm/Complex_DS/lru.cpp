#include <iostream>
#include <map>
#include <utility>

using namespace std;

struct DNode
{
  int key;
  int value;
  DNode* prev;
  DNode* next;
};

class LRUCache
{
private:
  int size;
  map<int, DNode> KeytoNode;
  DNode *head, *tail;

  DNode* GetNewNode(int key, int value)
  {
    DNode* node = new DNode();
    node->key = key;
    node->value = value;
    node->prev = node->next = NULL;
    return node;
  }

  void moveToHead(DNode* node)
  {

    head->next = node;
    node->prev = head;
    head = node;
    if (tail==NULL)
    {
      head->prev = tail;
      tail->prev
    }
  }

  DNode* deleteTail()
  {

    return node->key;
  }

public:
  LRUCache()
  {
      this->size = size;
      head = tail = NULL;
  }

  int get(int key)
  {
      if(KeytoNode.find(key)==KeytoNode.end())
      {
        return -1
      }

      moveToHead(KeytoNode[key]);
      return KeytoNode[key]->value;
  }

  int put(int key, value)
  {
    if(KeytoNode.find(key)!=KeytoNode.end())
    {
      KeytoNode[key]->value = value;
      moveToHead(KeytoNode[key]);
    }
    else
    {
      DNode* node = GetNewNode(key, value);
      if (KeytoNode.size() == this->size)
      {
        moveToHead(node);
        int KeytoDelete = deleteTail();
        KeytoNode.erase(KeytoDelete);
        KeytoNode[key] = node;
      }
      else if (KeytoNode.size() < this->size)
      {
        moveToHead(node);
        KeytoNode[key] node;
      }
      else
      {
        return -1;
      }
    }
    return 1;
  }
};

int main()
{
  return 0;
}
