/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void merger(vector<int>& v, int low, int mid, int high)
{
    int* temp = new int[high-low+1];
    int i = low;
    int j = mid+1;
    int k = 0;
    while(i<=mid && j<=high)
    {
        if(v[i]>v[j]) temp[k++] = v[j++];
        else temp[k++]=v[i++];
    }
    while(i<=mid)
    {
        temp[k++] = v[i++];
    }
    while(j<=high)
    {
        temp[k++]  = v[j++];
    }
    for(int i=0, j =low; i<high-low+1;++j, ++i )
    {
        v[j]  = temp[i];
    }
    delete []temp;

}

void sort_helper(vector<int>& v, int low, int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        sort_helper(v, low , mid-1);
        sort_helper(v, mid+1, high);
        merger(v, low, mid, high);
    }
}

void sort(vector<int>& v)
{
    sort_helper(v, 0, v.size());
}

void print(vector<int>& v)
{
    for(int i=0;i<v.size();++i) cout<<v[i]<<" ";
    cout<<endl;
}

int main()
{
    vector<int> v;
    srand((unsigned)time(0));
    for(int i=0;i<10;++i)
    {
        v.push_back(rand()%10);
    }

    sort(v);
    print(v);
    return 0;
}
