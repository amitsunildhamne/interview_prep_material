#include <iostream>

using namespace std;
#define N 4
class Queue
{
  private:
    int arr[N];
    int front, back;
  public:
    Queue();
    void Enqueue(int x);
    void Dequeue();
    void Front();
    bool IsEmpty();
    bool IsFull();
    void print_queue();
};

Queue::Queue()
{
  front = -1;
  back = -1;
}

bool Queue::IsEmpty()
{
  return (front == -1) && (back ==-1);
}

bool Queue::IsFull()
{
  return back+1%N ==front? true:false;
}

void Queue::Enqueue(int x)
{
  if(IsFull())
  {
    cout<<"Queue Full! Empty Queue before Enqueuing"<<endl;
    return;
  }
  if(IsEmpty())
  {
    front = back = 0;
  }
  else
  {
    back = (back+1)%N;
  }
  arr[back] = x;
}

void Queue::Dequeue()
{
  if(IsEmpty())
  {
    cout<<"Nothing to Dequeue"<<endl;
    return;
  }
  else if (back == front)  back = front =-1;
  else
  {
    front = (front +1)%N;
  }
}

void Queue::Front()
{
  cout<<"Front of the Queue: "<<arr[front]<<endl;
}

void Queue::print_queue()
{
  int count = (back + N - front)%N;
  int index;
  cout<<"Printing the List: "<<endl;
  for (int i=0; i<=count;i++)
  {
    index = (front+i)%N ;
    std::cout << arr[index] << '\n';
  }
}

int main()
{
  Queue Q;
  Q.Dequeue();
  Q.Enqueue(1);
  Q.Enqueue(2);
  Q.Enqueue(3);
  Q.Front();
  Q.Enqueue(4);
  Q.print_queue();
  Q.Dequeue();
  Q.print_queue();
  for(int i=0;i<=4;i++) Q.Dequeue();
  return 0;
}
