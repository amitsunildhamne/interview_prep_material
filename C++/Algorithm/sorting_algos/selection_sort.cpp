#include <iostream>
#include <vector>

using namespace std;
vector<int> v;

void vector_print()
{
  cout<<" \\\\\\\\ "<<endl;
  for(int i=0;i<v.size();i++)
  {
    cout<<v[i]<<endl;
  }
}

void sort()
{
  int temp,temp1;
  for(int i=0;i<v.size()-1;++i)
  {
    temp = i;
    for(int j=i+1;j<v.size();++j)
    {
      if(v[j]<v[temp])
      temp = j;
    }
    cout<<"temp val: "<<v[temp]<<endl;
   temp1 = v[i];
   v[i] = v[temp];
   v[temp] = temp1;

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
