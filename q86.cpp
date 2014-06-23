//Regular Expression Matching
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
#include <tr1/unordered_map>
#include <ctime>
#include <cctype>

using namespace std;

string preprocess(vector<int> &look,string &p){
	int i = 0;
	string temp = "";
	while(p[i]!='\0')
	{
		if(p[i]!='*'){
			temp += p[i];
			if(p[i+1]=='*'){
			   look.push_back(1);
			}else{
			   look.push_back(0);
			}
		}
		i++;
	}

	return temp;
}

bool match(string &s,string &p,int i,int j,vector<int> &look)
{
	if(j==p.length()){
		if(i<s.length()){
			return false;
		}else{
			return true;
		}
	}

	if(i==s.length()){
		bool ok = true;
		for(int l=j;l<look.size();l++)
		{
			if(!look[l]){
				ok = false;
			}
		}
		return ok;
	}

	if(s[i]!=p[j] && p[j] != '.'){
		if(look[j]){
			return match(s,p,i,j+1,look);
		}else{	
			return false;
		}
	}else{
		if(look[j]){
			return match(s,p,i+1,j,look) || match(s,p,i,j+1,look);
		}else{
			return match(s,p,i+1,j+1,look);
		}
	}
}

bool isMatch(const char *s, const char *p) {
	string sstr (s);
	string temp (p);

	if(temp.length()==0 && sstr.length()!=0){
		return false;
	}

	vector<int> look;
	string pstr = preprocess(look,temp);
	
	return match(sstr,pstr,0,0,look);	
}

string intToString(int c)
{
	if(c==0){
		return "false";
	}else if(c==1){
		return "true";
	}
	return "invalid " + c;
}

int main(){

	cout  << "isMatch('aaa','a*a') → true " << intToString(isMatch("aaa","a*a")) << endl;
	cout  << "isMatch('aaa','aaaa') → false " << intToString(isMatch("aaa","aaaa")) << endl;
	cout << "isMatch('aaa','aa') → false " << intToString(isMatch("aaa","aa")) << endl;
	cout << "isMatch('aa','a*') → true " << intToString(isMatch("aa","a*")) << endl;
	cout << "isMatch('aa','.*') → true " << intToString(isMatch("aa",".*")) << endl;
	cout << "isMatch('ab','.*') → true " << intToString(isMatch("ab",".*")) << endl;
	cout << "isMatch('aab','c*a*b') → true " << intToString(isMatch("aab","c*a*b")) << endl; 
 
	return 0;
}