#include <string>
#include <iostream>
#include <vector>
using namespace std;
string convert(string s, int numRows)
{
    if (numRows==1) return s;
    int size = s.size();
    string res;
    int sz=0;
    bool flag = false;
    string st[numRows];
    int i=0;
    while(sz<size)
    {
      if (!flag)
        {
          st[i++]+=s[sz++];
        //  cout<<st[i-1]<<endl;
        }
      else
          st[i--]+=s[sz++];
      if (i>=numRows)
        {
          flag=true;
          i= numRows-1;
        }
      else if (i<=0)
        {
          flag = false;
          i = 0;
        }
    }
    for(int i=0; i<numRows; i++)
    {
      cout<<st[i]<<endl;
      res += st[i];
    }
      cout<<res<<endl;
      return res;
  }

int main()
{
  cout<<convert("ABCDEFG",3)<<endl;
  return 0;
}
