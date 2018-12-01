#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Heap
{
private:
  int capacity;
  int count;
  vector <int> v;
public:
  int left(int i)
  {
    return (2*i + 1);
  }
  int right(int i)
  {
    return (2*i + 2 );
  }
  int parent(int i) { return (i - 1)/2 ;   }

  Heap(int capacity)
  {
    this->capacity = capacity;
    v.reserve(capacity);
    for (int i = 0; i < capacity ; ++i)
    {
      v.push_back(0);
    }
    this->count = 0;
  }

  void Heapify(int i);
  void removeMin();
  void deleteVal(int i);
  void decreaseKey(int i, int new_val);
  int addVal(int val);
};

void Heap::Heapify(int i)
{
  int l = left(i);
  int r = right(i);
  int smallest = i;
  if (l < count && v[i] > v[l])
  {
    smallest = l;
  }
  if (r < count && v[smallest] > v[r])
  {
    smallest = r;
  }
  if (i != smallest)
  {
    swap(&v[i], &v[smallest]);
    Heapify(smallest);
  }
}

void Heap::removeMin()
{
  if (count == 0)
  {
    return INT_MAX;
  }
  else if ( count == 1)
  {
    --count;
    return v[0];
  }
  v[0] = v[v.size() - 1];
  --count;
  Heapify(0);
}

int deleteVal(int i)
{
  decreaseKey(i, INT_MIN);
  removeMin();
}

void decreaseKey(int i, int new_val)
{
  v[i] = new_val;
  while(i != 0 && v[parent(i)] > v[i] )
  {
    swap(&v[i], &v[parent(i)]);
    i = parent(i);
  }
}

int addVal(int val)
{
  if (count + 1 > capacity)
  {
    return -1;
  }
  ++count;
  count - 1;
  v[i] = val;
  while(i != 0 && v[parent(i)] > v[i])
  {
    swap(&v[i], &v[parent(i)]);
    i = parent(i);
  }
  return 0;
}
