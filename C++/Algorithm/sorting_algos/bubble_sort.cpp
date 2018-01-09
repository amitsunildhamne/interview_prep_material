#include <iostream>
#include <vector>

using namespace std;

vector <int> v;

void vector_print()
{
  cout<<"Print Result: "<<endl;
  for(int i=0;i<v.size();i++) cout<<v[i]<<endl;
}

void sort()
{
  bool flag;
  int temp;
  for(int i=0;i<v.size();i++)
    {
      for(int j=0;j<v.size()-i-1;j++)
        {
          if(v[j]>v[j+1])
          {
            temp = v[j];
            v[j] = v[j+1];
            v[j+1] = temp;
            flag =1;
          }
        }
        if (!flag) break;
    }
}

int main()
{
  v.push_back(23);
  v.push_back(33);
  v.push_back(3);
  v.push_back(13);
  v.push_back(10);
  v.push_back(1);
  v.push_back(90);
  vector_print();
  sort();
  vector_print();
  return 0;
}
