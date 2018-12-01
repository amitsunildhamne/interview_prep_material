/*
Given an array,find the maximum j – i such that arr[j] > arr[i]
*/

#include <iostream>
#include <stdlib>
#include <ctime>

srand(time(0));
int main()
{
  int a[100];
  int n = 100;
  for (int i = )
  int diff = n - 1;
  while(diff > 0)
  {
    int i = 0;
    while( (i + diff ) < n )
    {
      if ( a[i] > a[i + diff])
      {
        break;
      }
      ++i;
    }
    --diff;
  }
}
