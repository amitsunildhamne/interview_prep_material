#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class SetofStacks
{
private:
  vector<stack <int>> v(1) ;
  vector<int> size(1);
  int which_stack;
  int max_size;
public:
  SetofStacks(int max_size);
  void push();
  void pop();
  void popAt(int);
};

SetofStacks::SetofStacks(int max_size)
{
  which_stack=0;
  this->max_size = max_size;
}

void SetofStacks::push(int data)
{
  if (size[which_stack]>max_size)
  {
    v.push_back(Stack());
    v[which_stack+1].push(data);
    size.push_back(1);
  }
  else
  {
    v[which_stack].push(data);
    size[which_stack]++;
  }
}

void SetofStacks::pop()
{
  cout<<v[which_stack].top()<<endl;
  v[which_stack].pop();
  size[which_stack]--;
  if (size[which_stack]==0)
  {
    v.pop();
    size.pop();
    which_stack--;
  }
}

void SetofStacks::popAt(int idx)
{
  cout<<v[idx]<<endl;
  
}

int main()
{

  return;
}
