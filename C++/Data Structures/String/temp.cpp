#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

string ReverseWords(string str)
{
	stringstream ss(str);
	vector<string> vec;
	string ret;
	string token;
	while(getline(ss, token, ' ')) {
//		cout<<token<<"\t";
		vec.push_back(token);
	}

	cout<<endl;
	for(int i=vec.size()-1; i>=0; --i) {
		ret += vec[i]+' ';
	}
	return ret;
}

int main(void)
{
	string str = "Amit is a good boy";
	string res = ReverseWords(str);
	cout<<res<<"\t";
	return 0;
}
