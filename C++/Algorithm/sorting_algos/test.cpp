#include <iostream>
#include <vector>

using namespace std;

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(vector<int> &arr, int start, int end)
{
  int pivot = arr[end];
  int pindex = start;
  for (int i=start; i<=end;i++)
  {
    if(arr[i]<pivot)
    {
      swap(arr[i],arr[pindex]);
      pindex++;
    }
  }
  swap(&arr[pindex],&arr[end]);
  return pindex;
}

void quickSort(vector<int> &arr, int start, int end)
{
  if (end>start)
  {
    int pindex = partition(arr, start,end);
    quickSort(arr, start, pindex-1);
    quickSort(arr, pindex+1, end);
  }
}
void vector_print(std::vector<int> v)
{
  cout<<"Print Result: "<<endl;
  for(int i=0;i<v.size();i++) cout<<v[i]<<endl;
}
int main()
{
  std::vector<int> v;
  /*int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr)/sizeof(arr[0]);
  quickSort(arr, 0, n-1);
  printf("Sorted array: n");
  printArray(arr, n);*/
  v.push_back(23);
  v.push_back(33);
  v.push_back(3);
  v.push_back(13);
  v.push_back(10);
  v.push_back(1);
  v.push_back(90);
  vector_print(v);
  quickSort(v,0, v.size()-1);
  vector_print(v);
  return 0;
}
