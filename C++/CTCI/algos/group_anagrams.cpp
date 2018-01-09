#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> v;
vector<string> x;

void sort_vector()
{
  vector<string> temp;
  for(int j=0;j<v.size();j++)
  {
    temp.push_back(v[j]);
  }
  for(int i=0;i<v.size();i++)
  {
    sort(temp[i].begin(),temp[i].end()-1);
  }
 for(int m=0;m<v.size();m++)
 {
   x.push_back(v[m]);
   for(int f=m+1;f<v.size();f++)
   {
     if(temp[m].compare(temp[f]))
     {
       x.push_back(v[f]);
       v.erase(x.begin()+f);
       temp.erase(temp.begin()+f);
     }
   }
 }
}

void print_vector(bool flag)
{
  cout<<"//////String Print///////"<<endl;

  if(flag){
  for(int i=0;i<v.size();i++)
  {
    cout<<v[i]<<endl;
  }}
  else
  {
    for(int i=0;i<x.size();i++)
    {
      cout<<x[i]<<endl;
    }
  }
}

int main()
{
  v.push_back("amit");
  v.push_back("aamit");
  v.push_back("tima");
  v.push_back("dhamne");
  v.push_back("atmi");
  v.push_back("dhanme");
  print_vector(true);
  sort_vector();
  print_vector(false);
  return 0;
}
