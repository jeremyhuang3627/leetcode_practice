#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <tr1/unordered_set>
#include <ctime>

using namespace std;

vector<string> str_v;
vector<vector<string> > all;

void cutString(string s,tr1::unordered_set<string> &dict)
{
	if(s.length()>0)
	{
		for(int i=0;i<s.length();i++)
		{
			string sub = s.substr(s.length()-1-i);
			if(dict.count(sub) > 0)
			{
				str_v.push_back(sub);
				cutString(s.substr(0,s.length()-1-i),dict);
				str_v.pop_back();
			}
		}
	}else{
		all.push_back(str_v);
	}
}

vector<string> wordBreak(string s,tr1::unordered_set<string> &dict)
{
	cutString(s,dict);
	vector<string> v;
	for(int i=0;i<all.size();i++)
	{	
		string s = "";
		for(int j=all[i].size()-1;j>=0;j--)
		{
			if(j!=0){
				s += all[i][j] + " ";
			}else{
				s += all[i][j];
			}
		}
		v.push_back(s);
	}
	return v;
}

int main(){
	string dict_arr[] = {"cat", "cats", "and", "sand", "dog"};
	string s = "catsanddog";
	tr1::unordered_set<string> dict;

	for(int i=0;i<sizeof(dict_arr)/sizeof(dict_arr[0]);i++)
	{
		//cout << "inserting " << dict_arr[i] <<endl;
		dict.insert(dict_arr[i]);
	}

	vector<string> v = wordBreak(s,dict);

	for(int i=0;i<v.size();i++)
	{
		cout << v[i] << endl;
	}

	return 0;
}