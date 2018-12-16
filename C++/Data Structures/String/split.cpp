/*
 Method to reverse a sentence
*/
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	vector<string> v;
	/*char a[] = "amit dhamne";
	char* token = strtok(a," ");
	while(token!=NULL)
	{
	 v.push_back(token);
	 token = strtok(NULL," ");
	}
	vector<char*>::const_iterator itr;
	for(itr = v.begin();itr!=v.end();itr++)
	cout<<*itr<<endl; */
	std::string str = "HAPPY NEW YEAR";
	std::istringstream iss(str);
	std::string token;
	while(getline(iss, token, ' '))
	v.push_back(token);
	for(int i=0;i<v.size();++i)
	cout<<v[i]<<" ";
}
