#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;


void rev(char* ch,int start, int end)
	{
	  	char temp;
	    while(start<end)
	  	{
		  temp = ch[start];
		  ch[start] = ch[end];
		  ch[end] = temp;
		 start++; end--;
	  	}
	}

int main()
{
	char ch[] = "Amit is a scary Dhamne";
	rev(ch,0,strlen(ch)-1);
	int j=0;
	for(int i=0;i<strlen(ch)+1;i++)
	{
		if (ch[i]==' ' || i==strlen(ch))
		{
			rev(ch,j,i-1);
			j = i+1;
		}
	}
	for(int i=0;i<strlen(ch);i++)
	{
		cout<<ch[i]<<endl;
	}
	return 0;
}
