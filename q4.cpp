#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <stdlib.h>
#include <tr1/unordered_set>
#include <queue>

using namespace std;

vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
 	queue<string> q;
 	map<string,int> m;
 	map<string,vector<string>> p;
 	tr1::unordered_set::iterator it;
 	for(it = dic.begin();it!=dic.end();++it)
 	{
 		vector<string> v;
 		p[*it] = v;
 	}
 	vector<string> v;
 	p[end] = v;

 	int foundL = 0;
 	int beginL = 0;
 	int endL = 0;
 	m[start] = 0;// visited
 	q.push(start);
 	int found = 0;

 	while(!q.empty())
 	{
 		string s = q.dequeue();
 		vector<string> n = getN(s,dict,m);
 		for(int i=0;i<n.size();i++)
 		{
 			(*p[n[i]]).push(n[i]);
 			m[n[i]] = m[s] + 1;
 			q.push(n[i]);
 			if(n[i] == end){
 				found = true;
 				foundL = m[n[i]];
 			}
 		}

 		if(found && foundL && m[s] == foundL)
 		{
 			break;
 		}
 	}
}

void getAns(int foundL,)

vector<string> getN(string s, unordered_set<string> &dict, map<string,int> m)
{
	char * sp = s.c_str();
	vector<string> res;
	tr1::unordered_set<string>::iterator it;
	for(it=dic.begin();it!=dic.end();++it)
	{
		char * dic_c = *it;
		if(charDiff(sp,dic_c)==1 && m.find(*it) == m.end())
		{
			res.push(*it);
		} 
	}
	return res;
}

int charDiff(char *sp, char *dic_c)
{
	int diffCount = 0;
	while(*sp != 0){
		if(*sp != *dic_c){
			diffCount++
		}
		sp++;
		dic_c++;
	}
	return diffCount;
}

int main()
{
	tr1::unordered_set<string> dic = {"hot","dot","dog","lot","log"};
	dic.insert("hot");
	dic.insert("dot");
	dic.insert("dog");
	dic.insert("lot");
	dic.insert("log");

	string start = "hit";
	string end = "cog";
	vector<vector<string>> ans = findLadders(start,end,dic);

	return 0;
}