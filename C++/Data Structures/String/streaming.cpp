#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
  string str = "192.168.0.1";
  stringstream ss(str);
  string block;
  while(getline(ss, block, '.'))
  {

  cout<<block<<endl;
}
  return 0;
}
