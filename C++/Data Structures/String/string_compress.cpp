#include <string>
#include <iostream>
using namespace std;

int main()
{
  string s = "aabbccd";
  string str;
  int count =1;
for(int i=1;i<=s.size();++i)
{
if (s[i]==s[i-1])
count++;
else
{
str+=s[i-1]+to_string(count);
count=1;
}
}
cout<<str<<endl;
return 0;
}
