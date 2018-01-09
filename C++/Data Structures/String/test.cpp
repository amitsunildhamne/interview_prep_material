#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;


void rev(string& str,int start, int end)
	{
      int n = end-start+1;
	  	for(int i=start;i<n/2;++i)
      {
      swap(str[i],str[n-1-i]);
      }

	}

int main()
{
	string str = "Amit is a scary Dhamne";
	rev(str,0,str.size()-1);
	int j=0;
	for(int i=0;i<str.size()+1;i++)
	{
		if (str[i]==' ' || i==str.size())
		{
			rev(str,j,i-1);
			j = i+1;
		}
	}
	//for(int i=0;i<str.size();i++)
	//{
		cout<<str<<endl;

	return 0;
}
