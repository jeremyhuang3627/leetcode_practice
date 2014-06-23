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

using namespace std;

int sn = 0;

bool wordBreak(string s,tr1::unordered_set<string> dict)
{	
	if(s.length()==0){
		return true;
	}

	
	sn++;
	string space = "";
	for(int j=0;j<sn;j++)
	{
		space  += "    ";
	}

	for(int i=s.length()-1;i>=0;i--)
	{
		bool inDict = false;
		string ns = s.substr(0,i);
		string r = s.substr(i);
		cout << space << "ns " << ns <<endl;
		cout << space << "r " << r <<endl;
		tr1::unordered_set<string>::iterator it = dict.find(r);
		if(it != dict.end()){
			cout << space << "found "<<endl;
			inDict = true;
		}
		bool res = wordBreak(ns,dict);
		if(inDict && res){
			sn--;
			cout << space << "return true "<<endl;
			return true;
		}
	}
	sn --;
	cout << space << "return false "<<endl;
	return false;
}

int main()
{
	tr1::unordered_set<string> dict;
	dict.insert("aaaa");
	dict.insert("aa");

	string ms = "aaaaaaa";

	if(wordBreak(ms,dict))
	{
		cout << "true" <<endl;
	}else{
		cout << "false" <<endl;
	}

	return 0;
}