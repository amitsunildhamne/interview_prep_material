#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

class Heap
{
private:
  vector<int> A;
  int Parent(int i);
  int Left(int i);
  int Right(int i);
  bool empty();
  void heapify_down(int i);
  void heapify_up(int i);
public:
  int size();
  void push(int key);
  void pop();
  int top();
};

int Heap::Parent(int i)
{
  return (i-1)/2;
}

int Heap::Left(int i)
{
  return (2*i+1);
}

int Heap::Right(int i)
{
  return (2*1+2);
}

void Heap::heapify_down(int i)
{
  int left = Left(i);
  int right = Right(i);
  int largest = i;
  if(left<size() && A[left]>A[largest])
  {
    largest = left;
  }
  if(right<size() && A[largest]<A[right])
  {largest = right;}
  if(largest !=i){
  swap(A[i], A[largest]);
  heapify_down(largest);
 }
}

void Heap::heapify_up(int i)
{
  if(i && A[Parent(i)]<A[i])
  {
    swap(A[i], A[Parent(i)]);
    heapify_up(Parent(i));
  }
}

int Heap::size()
{
  return A.size();
}

bool Heap::empty()
{
  return size()==0;
}

void Heap::push(int key)
{
  A.push_back(key);
  int index = size() - 1;
  heapify_up(index);
}

void Heap::pop()
{
  try
  {
    if (size() == 0)
    throw out_of_range("Vector");
    A[0] = A.back();
    A.pop_back();
    heapify_down(0);
  }
  catch(const out_of_range& oor)
  {
    cout<<oor.what();
  }
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
