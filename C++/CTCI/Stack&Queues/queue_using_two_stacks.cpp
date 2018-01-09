#include <iostream>
#include <stack>

using namespace std;

stack <int>  s1;
stack <int>  s2;

void add(int item)
{
  while(!s2.empty())
  {
    int a = s2.top();
    cout<<"add: "<<a<<endl;
    s1.push(a);
    s2.pop();
  }

  s1.push(item);

}

void remov()
{
  while(!s1.empty())
  {
    int a = s1.top();
    cout<<"remove: "<<a<<endl;
    s2.push(a);
    s1.pop();
  }

  s2.pop();
}

int peek()
{
  while(!s1.empty())
  {
    int a = s1.top();
    cout<<"peek: "<<a<<endl;
    s2.push(a);
    s1.pop();
  }

 return  s2.top();
}

int main()
{
  add(1);
  add(2);
  add(3);
  cout<<peek()<<endl;
  add(4);
  cout<<peek()<<endl;
  remov();
  cout<<peek()<<endl;
  remov();
  cout<<peek()<<endl;
  remov();
  cout<<peek()<<endl;
  return 0;
}
