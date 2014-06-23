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

bool isScramble(string s1,string s2)
{
	if(s1.length() != s2.length()){
		return false;
	}

	int A[26];
	memset(A,0,26*sizeof(A[0]));

	for(int i=0;i<s1.length();i++)
	{
		A[s1[i]-'a']++;
		A[s2[i]-'a']--;
	}

	for(int i=0;i<26;i++)
	{
		if(A[i]!=0)
		{
			return false;
		}
	}

	if(s1.size() ==1 && s2.size() ==1) return true; 
	for(int i=0;i<s1.length();i++)
	{
		bool res = isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i));
		res = res || (isScramble(s1.substr(0,i),s2.substr(s2.length()-i,i)) && isScramble(s1.substr(i),s2.substr(0,s2.length()-i)));
		if(res){return true;}
	}

	return false;
}

int main()
{
	string s1 = "great";
	string s2 = "rgeat";

	if(isScramble(s1,s2)){
		cout << "is scramble " << endl;
	}else{
		cout << " is not scramble " << endl;
	}

	return 0;
}