#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
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

vector<string> split(string &s,char delim)
{
	const char * p = s.c_str();
	vector<string> ret;
	string str = "";

	while(*p!='\0')
	{
		if(*p==delim){
			if(str!=""){
				ret.push_back(str);
				str = "";
			}
		}else{
			str += *p;
		}
		p++;
	}

	if(str != "")
	{
		ret.push_back(str);
		str= "";
	}

	return ret;
}

string simplifyPath(string p)
{
	vector<string> v = split(p,'/');

	vector<string> s;
	for(int i=0;i<v.size();i++)
	{
		if(v[i]=="."){
			continue;
		}else if(v[i] == "..")
		{
			if(s.size() != 0){

				s.pop_back();
			}
		}else{
			s.push_back(v[i]);
		}
	}

	string np = "";
	for(int i=0;i<s.size();i++)
	{
		np += "/" + s[i];
	}

	if(s.size()==0)
	{
		np+="/";
	}
	return np;
}

int main()
{
	string path = "/..";

	//vector<string> v = split(path,'/');

	string s = simplifyPath(path);
	cout << "ans " << s <<endl;
	return 0;
}