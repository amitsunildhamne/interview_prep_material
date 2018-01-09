/* C implementation QuickSort */
#include <iostream>
#include <vector>

using namespace std;

// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;    // increment index of smaller element

        }
    }
    swap(&arr[i], &arr[high]);
    return (i);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}
void vector_print(std::vector<int> v)
{
  cout<<"Print Result: "<<endl;
  for(int i=0;i<v.size();i++) cout<<v[i]<<endl;
}
// Driver program to test above functions
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
