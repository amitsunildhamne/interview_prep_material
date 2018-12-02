/*
A container can hold X quantity. An array is given with number of items. Find
most optimum way to reduce the counts.
nput:  wieght[]       = {4, 8, 1, 4, 2, 1}
        Bin Capacity c = 10
Output: 2
We need minimum 2 bins to accommodate all items
First bin contains {4, 4, 2} and second bin {8, 2}

Input:  wieght[]       = {9, 8, 2, 2, 5, 4}
        Bin Capacity c = 10
Output: 4
*/

#include <map>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int container(int *arr, int size, int max_capacity)
{
    int ret_val = 0;
    bool inserted_arr[size];
    int curr_capacity = 0;
    if(max_capacity == 0 || ( *(max_element(arr, arr+size-1)) > max_capacity) )
    {
      return -1;
    }
    int i = 0;
    bool flag = true;

    while(1)
    {
       while( curr_capacity < max_capacity && i < size)
       {
          if (inserted_arr[i] == false)
          {
            curr_capacity += arr[i];
            inserted_arr[i] = true;
          }
          ++i;
       }
       ret_val++;
       curr_capacity = 0;
       i = 0;
       flag = true;
       for(int j = 0; j < size; ++j)
       {
         flag = flag && inserted_arr[j];
       }
       if (flag == true)
       {
         break;
       }
    }
    return ret_val;
}

void print_array(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
      cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
  int arr[15];
  int size = 15;
  srand(time(0));
  int capacity = 30;
  int count = 0;
  for (int i; i < size; ++i)
  {
    arr[i] = rand()%30;
  }
  print_array(arr, size);
  count = container(arr, size, capacity);
  cout<<"Count: "<<count<<endl;
}
