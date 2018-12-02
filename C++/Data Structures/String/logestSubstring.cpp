/*
Longest Substring without duplicate chars
*/
#include <iostream>
#include <string>
#include <utility>
using namespace std;

string longestSubStr(string str)
{
  string max_val;
  int j;
  for(int i = 0; i < str.size(); ++i)
  {
    j = i;
    string ret;
    bool visited[256] =  {false};
    while( j < str.size() )
    {
      if(visited[str[j]] == false)
      {
        ret += str[j];
        ++j;
        visited[str[j]] = true;
      }
      else
      {
        break;
      }
    }
    printf("val: %d", str[j]);
    cout<<" str: "<<ret<<endl;
    if (max_val.size() < ret.size())
    {
      max_val = ret;
    }
  }
  return max_val;
}

int main()
{
  string str = "GEEKSFORGEEKS";
  cout<<"Longest unique substr: \n "<< longestSubStr(str)<<endl;
  return 0;
}
