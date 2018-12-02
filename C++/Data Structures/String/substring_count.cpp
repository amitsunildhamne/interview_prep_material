#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int countBinarySubstrings(string s)
  {
    int count=0;
    for(int sz=2;sz<=s.length();sz=sz*2)
    {
      for(int i=0;i<s.length()-sz;++i)
        {
          string temp = s.substr(i,sz);
          cout<<"sub string"<<temp<<endl;
            int flag, is_cons,sum;
            is_cons=1;
            flag = (int)(temp[0]) -48;
            for(int k=0;k<temp.length()/2;k++)
            {
             if(((int)(temp[k])-48)!=flag) is_cons=0;
             else
               {sum++;}
            }
            flag = !flag;
            for(int k=((temp.length()/2)+1);k<temp.length();++k)
            {
              if(((int)(temp[k])-48)!=flag) is_cons=0;
              else
              {--sum;}
            }
                if (is_cons && sum==0) count++;
                temp.clear();
            }
        }
        return count;
    }


int main()
{
  string str = "0011";
  int count =countBinarySubstrings(str);
  cout<<"Count is "<<count<<endl;
  return 0;
}
