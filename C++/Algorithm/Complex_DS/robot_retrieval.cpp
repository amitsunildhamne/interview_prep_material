/*
Count the total number of rtrievals required required by a robot that is given M
items to store and but it can store only N items. It will kick out the least
recently used to item to accomodate the next item
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Basket
{
private:
  int capacity;
  int count;
  list<int> ls;

public:
  Basket(int capacity)
  {
    this->capacity = capacity;
    this->count = 0;
  }

  int put_bin(int value)
  {

    int ret_val = 0;
    if (ls.size() != 0)
    {
      if (find(ls.begin(), ls.end(), value) != ls.end())
      {
        ls.remove(value);
        --(this->count);
      }
      else
      {
        if(this->count >= this->capacity)
        {
          ret_val = 1;
          ls.pop_back();
        }
      }
    }
    ls.push_front(value);
    ++(this->count);
    return ret_val;
  }
};
int retrieve_bin(int *M, int size,int capacity)
{
  Basket *basket = new Basket(capacity);
  int ret_val = 0, val;
  for (int i = 0; i < size; ++i)
  {
    val = basket->put_bin(M[i]);
    cout<<"val: "<<val<<endl;
    ret_val += val;
  }
  return ret_val;
}

void print_array(int *arr, int size)
{
  for(int i = 0; i < size; ++i )
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main()
{
  srand(time(0));
  int M[30];
  int size = 30;
  for (int i =0; i<size; ++i)
  {
    M[i] = rand()%20;
  }
  print_array(M, size);
  int capacity = 5;
  cout<<"Count: " <<retrieve_bin(M, size,capacity)<<endl;
}
