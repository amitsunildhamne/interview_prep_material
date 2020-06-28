/*
 *  Group Shifting leetcode
 * Given a string, we can "shift" each of its letter to its successive letter,
 * for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence
 *
 *
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

void PrintV(vector<string> *strings)
{
	for(int i=0; i<strings->size(); ++i)
		cout<<strings->at(i)<<" ";
	cout<<endl;
}

string ShiftSequence(string str)
{
	string res = "0.";
	for(int i=1; i<str.size(); ++i) {
		res+= to_string(str[i]-str[i-1]);
		res+='.';
	}
	return res;
}

unordered_map<string, vector<string>>
SortString(vector<string> *strings, vector<vector<string>> *SortedV)
{
	unordered_map<string, vector<string>> Map;
	for(int i=0; i<strings->size(); ++i) {
		string key = ShiftSequence(strings->at(i));
		//cout<<"key "<<key<<" value "<<strings->at(i)<<endl;
		Map[key].push_back(strings->at(i));
	}
	return Map;
}

void PrintM(unordered_map<string, vector<string>> *Map)
{
	for(auto itr = Map->begin(); itr != Map->end(); ++itr) {
		cout<<"key "<<itr->first<<" value ";
		for (int i=0; i<itr->second.size(); ++i)
			cout<<itr->second[i]<<" ";
		cout<<endl;
	}
}


int main()
{
	vector<string> strings{"abc", "xyz", "acef", "bcd", "a", "z", "az","ba"};
	vector<vector<string>> SortedV;
	PrintV(&strings);
	unordered_map<string, vector<string>> Map;
	Map = SortString(&strings, &SortedV);
	PrintM(&Map);
	return 0;
}
