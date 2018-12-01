#include <iostream>
#include <string>
#define TOTAL_ALPHABETS 26
using namespace std;

struct trieNode
{
  trieNode *children[TOTAL_ALPHABETS];
  bool isEnd;
};

trieNode *GetNewNode()
{
  trieNode* node = new trieNode();
  node->isEnd = false;
  for(int i = 0; i < TOTAL_ALPHABETS; ++i)
  {
      node->children[i] = NULL;
  }

  return node;
}

void Insert( trieNode* root, string key)
{
  int character;
  for(int i = 0; i<key.size(); ++i )
  {
      character = key[i] - 'a';
      if (root->children[character] == NULL)
      {
         root->children[character] = GetNewNode;
      }
      root = root->children[character];
  }
  root->isEnd = true;
}

bool search( trieNode* root, string key )
{
  int character;
  for(int i = 0; i<key.size(); ++i)
  {
    character = key[i] - 'a';
    if(root->children[character]==NULL)
    {
      return false;
    }
    root = root->children[character];
  }

  return root->children[character] && root->end ;
}

int main()
{
  string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their"};
  int n = sizeof(keys)/sizeof(keys[0]);
  trieNode *root = GetNewNode;

  for(int i = 0; i < n; ++i )
  {
    Insert(root, keys[i]);
  }

  search(root, "the")? cout << "Yes\n" : cout << "No\n";
  search(root, "ass")? cout << "Yes\n" : cout << "No\n";

  return 0;
}
