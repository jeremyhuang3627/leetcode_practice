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

stack<string> combi;
string s;

bool ok(string str)
{
	const char * p = str.c_str();
	stack<char> ms;
	for(int i=0;i<str.length();i++)
	{
		if(!ms.empty()){	
			if(ms.top()=='(' && p[i]==')')
			{
				ms.pop();
			}else{
				ms.push(p[i]);
			}
		}else{
			ms.push(p[i]);
		}
	}

	return ms.empty();
}


void genRec(int n);
{
	if(n!=0)
	{
		s+="(";
		genRec(n-1);
		s = s.substr(s.length()-2);

		s+=")";
		genRec(n-1);
		s = s.substr(s.length()-2);
	}else{
		combi.push(s);
	}
}

vector<string> permAll(int n)
{
	s = "";
	return combi;
}

vector<string> generateParenthesis(int n)
{
	vector<string> ret;
	vector<string> v = permAll(int n);
	for(int i=0;i<v.size();i++)
	{
		if(ok(v[i]))
		{
			ret.push_back(v[i]);
		}
	}

	return ret;
}

int main()
{
	int n = 3;

	vector<string> ans = generateParenthesis(n);

	for(int i=0;i<ans.size();i++)
	{
		cout << ans[i] << endl;
	}

	return 0;
}