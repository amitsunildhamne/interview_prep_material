#include <iostream>
#include <string>
using namespace std;
    bool checkRecord(string s)
    {
        bool flag = true;
        int late_count;
        for(int i=0; i<s.length();++i)
        {
            if(s[i]=='A') late_count++;
        }
        if(late_count>=2) flag = false;
        if(flag==true)
        {
            for(int i=0;i<=s.length()-3;++i)
            {
                string temp = s.substr(i,3);
                if(temp == "LLL") flag = false;
            }
        }
        return flag;
    }
int main()
{
  bool attends;
  attends = checkRecord("PPALLP");
  cout<<attends<<endl;
  return 0;
}
