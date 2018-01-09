#include <iostream>

using namespace std;

struct Animal
{
  bool type; //Dog = 0 Cat =1
  Animal* next;
};

Animal* front = NULL;
Animal* back = NULL;

void enqueue(bool type)
{
  Animal* node = new Animal();
  node->type = type;
  node->next = NULL;
  if(front==NULL && back==NULL)
  {
    front = back = node;
  }
  else
  {
    back->next = node;
    back = node;
  }
}

void dequeueAny()
{
  if (front== NULL && back==NULL)
  {
    cout<<"All animals ran away"<<endl;
    return;
  }
  else if (front==back)
  {
    Animal* curr = front;
    if(curr->type==0) cout<<"Kutta"<<endl;
    else cout<<"Billi"<<endl;
    front = back = NULL;
    return;
  }
  else
  {
    Animal* curr = front;
    if(curr->type==0) cout<<"Kutta"<<endl;
    else cout<<"Billi"<<endl;
    front = curr->next;
    free(curr);
  }
}

void dequeueSpecific(int type)
{
  Animal* curr = front;
  Animal* prev = NULL;
  while(curr!=NULL)
  {
    if(curr->type==type)
    {
      if(front==back)
      {
        front = back=NULL;
        free(curr);
        return;
      }
      else
      {
        if(curr==front)
        {
          front =curr->next ;
          free(curr);
          return;
        }
        else
        {
          prev->next = curr->next;
          free(curr);
          return;
        }
      }
    }
    prev = curr;
    curr = curr->next;
  }
  cout<<"No dogs found"<<endl;
}

void print_queue()
{
  Animal* curr = front;
  while(curr!=NULL)
  {
    cout<<curr->type<<endl;
    curr = curr->next;
  }
}

int main()
{
  dequeueAny();
  enqueue(1);
  enqueue(0);
  enqueue(1);
  enqueue(0);
  enqueue(1);
  enqueue(1);
  enqueue(0);
  enqueue(0);
  enqueue(1);
  dequeueAny();
  dequeueAny();
  dequeueAny();
  dequeueAny();
  dequeueAny();
  dequeueAny();
  dequeueAny();
  dequeueSpecific(1);
  dequeueSpecific(0);
  return 0;
}
