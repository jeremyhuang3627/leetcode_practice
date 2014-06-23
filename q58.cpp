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

set<string> ms;
string str = "";
map<string,bool> mp;

void permAll(vector<string> &l)
{
	bool usedUp = true;
	for(int i=0;i<l.size();i++)
	{
		if(!mp[l[i]])
		{
			str += l[i];
			mp[l[i]] = true;
			usedUp = false;
			permAll(l);
			mp[l[i]] = false;
			str = str.substr(0,str.length()-3);
		}
	}

	if(usedUp)
	{
		ms.insert(str);
	}
}

vector<int> findSubstring(string s,vector<string> &l)
{
	permAll(l);
	
}


int main()
{
	string s = "barfoothefoobarman";
	vector<string> v;
	v.push_back("foo");
	v.push_back("bar");

	//vector<int> ans = findSubstring(s,v);

/*	for(int i=0;i<ans.size();i++)
	{
		cout << ans[i] << endl;
	}	 */


/*	set<string>::iterator it;
	for(it=ms.begin();it!=ms.end();it++)
	{
		cout << *it << endl; 
	} */

	return 0;
}