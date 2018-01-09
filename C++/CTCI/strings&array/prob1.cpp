#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map <char,int> u_map;

int main()
{
  string a;
  bool flag = 0;
  cout<<"Enter the string: "<<endl;
  cin>>a;
  int n = a.length();
  cout<<n<<endl;
  char* i = &a[0];
  int ii=0;
  while(*i)
  {
    u_map[*i] = ++u_map[*i];
    cout<<"Char: "<<*i<<" num: "<<u_map[*i]<<endl;
    i++;
  }
  unordered_map <char, int> ::const_iterator itr;
  for (itr = u_map.begin();itr!=u_map.end(); itr++)
  {
    if (itr->second>1)
    {
      flag = 1; break;
    }
  }
  if(flag==1) cout<<"String is not Unique"<<endl;
  else cout<<"String is Unique"<<endl;
}
