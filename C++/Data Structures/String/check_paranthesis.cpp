#include <stack>
#include <iostream>
#include <string>
using namespace std;

bool isValid(string s)
{
  stack<char> stck;

  for(int i=0; i<s.length();++i)
  {
    if((s[i] == '[') || (s[i]=='{') || (s[i]=='(')) stck.push(s[i]);
    if((s[i]==']')||(s[i]=='}')||(s[i]==')'))
    {
        if(stck.empty()) return false;
        char st = stck.top();
        if(s[i]==']') {if(st!='[') return false; }
        if(s[i]=='}') {if(st!='{') return false; }
        if(s[i]==')') {if(st!='(') return false; }
        stck.pop();
    }
  }
  if(stck.empty()) return true;
  else return false;
}

int main()
{
bool val;
val = isValid("{()}{[]}");
cout<<val<<endl;
  return 0;
}
