#include <iostream>
#include <vector>

using namespace std;

class Heap
{
private:
  vector<int> A;
  void heapify_up(int i);
  void heapify_down(int i);
  int Left(int i);
  int Right(int i);
  int Parent(int i);

public:
  int size();
  void push(int data);
  void pop();
  int top();
};

int Heap::Parent(int i)
{
  return (i-1)/2;
}

int Heap::Left(int i)
{
  return i*2+1;
}

int Heap::Right(int i)
{
  return i*2+2;
}

void Heap::heapify_down(int i)
{
  int largest = i;
  int left = Left(i);
  int right = Right(i);

  if(left<size() && A[left]>A[largest])
  largest = left;
  if(right<size() && A[right]>A[largest])
  largest = right;

  if(largest!=i)
  {
    swap(A[i], A[largest]);
    heapify_down(largest);
  }
}

int Heap::size()
{
  return A.size();
}

void Heap::heapify_up(int i)
{
  if(i && A[Parent(i)]<A[i])
  {
    swap(A[i],A[Parent(i)]);
    heapify_up(Parent(i));
  }
}

void Heap::push(int data)
{
  A.push_back(data);
  int sz = size()  -1;
  heapify_up(sz);
}

void Heap::pop()
{
  if(size()==0) return;
  A[0] = A.back();
  A.pop_back();
  heapify_down(0);
}

int Heap::top()
{
  return A.at(0);
}

int main()
{
  Heap pq;
  pq.push(3);
  pq.push(2);
  pq.push(15);
  cout<<"PQ size "<<pq.size()<<endl;
  cout<<pq.top()<<" ";
  pq.pop();
}
