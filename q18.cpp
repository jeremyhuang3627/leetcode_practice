#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <stdlib.h>
#include <tr1/unordered_set>
#include <queue>
#include <set>
#include <map>

using namespace std;

vector<vector<string> > res;
vector<string> s;

int charDiff(string s1,string s2)
{	
	if(s1.length() == s2.length()){
		const char *cp1 = s1.c_str();
		const char *cp2 = s2.c_str();
		int diffNum = 0;

		for(int i=0;i<s1.length();i++)
		{
			if(*cp1!=*cp2)
			{
				diffNum ++;
			}
			cp1++;
			cp2++;
		}
		return diffNum;
	}
	return -1;
}

vector<string> getNeighbors(string s,tr1::unordered_set<string> dic)
{	
	tr1::unordered_set<string>::iterator it;
	vector<string> v;
	for(it=dic.begin();it!=dic.end();it++)
	{
		if(charDiff(s,*it) == 1)
		{
			v.push_back(*it);
		}
	}
	return v;
}

void DFS(string end,string start,map<string,vector<string> *> p)
{	
	if(end == start){
		s.insert(s.begin(),start);
		res.push_back(s);
		cout << "pushing stack " << endl; 
		for(int i=0;i<s.size();i++)
		{
			cout << s[i] << " ";
		}
		cout<< endl;
		s.clear();
	}else{	
		vector<string> *n = p[end];
		for(int i=0;i<(*n).size();i++)
		{	
			string ns = (*n)[i];
			s.insert(s.begin(),end);
			DFS(ns,start,p);
		}
	}
}

vector<vector<string> > findLadders(string start, string end, tr1::unordered_set<string> dict) {
	 dict.insert(end);
	 queue<string> q;
	 q.push(start);
	 map<string,int> m;
	 map<string,vector<string> *> p;
	 p[start] = new vector<string>();
	 int found = 99999;

	 while(!q.empty())
	 {	
	 	string l = q.front();
	 	q.pop();
		
		vector<string> sa = getNeighbors(l,dict);
		cout << "poping " << l << endl;
		cout << "level is " << m[l] + 1 << endl;
		cout << "found is " << found << endl;
		if( m[l] + 1 <= found){
			for(int i=0;i<sa.size();i++)
			{
				if(m[sa[i]] == 0)
				{
					m[sa[i]] = m[l] + 1;

					if(sa[i] == end && m[sa[i]] <= found){
						found = m[sa[i]];
					}

					if(p[sa[i]] == NULL){
						vector<string> *v = new vector<string>();
						(*v).push_back(l);
						p[sa[i]]= v;
					}else{
						(*p[sa[i]]).push_back(l);
					}
					cout << "pushing " << sa[i]<<endl;
					q.push(sa[i]);				
				}else if(sa[i] == end){

					if(p[sa[i]] == NULL){
						vector<string> *v = new vector<string>();
						(*v).push_back(l);
						p[sa[i]]= v;
					}else{
						(*p[sa[i]]).push_back(l);
					}

				}
			}
		}else{
			break;
		}
	}
	
	cout << "size of the parent array of end" << (*p[end]).size()<<endl;
	DFS(end,start,p);
	return res;
}

int main()
{
	string s = "teach";
	string e = "place";
	tr1::unordered_set<string> dic ;// {"hot","dot","dog","lot","log"};
	dic.insert("peale");
	dic.insert("wilts");
	dic.insert("place");
	dic.insert("fetch");
	dic.insert("purer");
	dic.insert("pooch");
	dic.insert("peace");
	dic.insert("poach");
	dic.insert("berra");
	dic.insert("teach");
	dic.insert("rheum");
	dic.insert("peach");
//	dic.insert("lot");
//	dic.insert("log");
	vector<vector<string> > ans = findLadders(s,e,dic);

	cout << "["<<endl;
	for(int i=0;i<ans.size();i++)
	{
		cout << "[ ";
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j] << ",";
		}
		cout << "] " <<endl; 
	}
	cout<<"]"<<endl;
	return 0;
}