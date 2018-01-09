#include <iostream>
#include <stack>
#include <ctime>
using namespace std;

struct value
{
  int data;
  int min_val;
};

int main()
{
  stack<value> st;
  int min;
  srand((unsigned)time(0));
  int random_int;
  for(int i=0;i<5;i++)
  {
    random_int = rand();
    value v;
    v.data = random_int;
    if (i==0 || min>random_int) min=random_int;
    v.min_val = min;
    st.push(v);
  }
  while(!st.empty())
  {
    value v;
    v = st.top();
    cout<<v.data<<" Minval: "<<v.min_val<<endl;
    st.pop();
  }
}
