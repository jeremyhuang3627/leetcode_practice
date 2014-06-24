//Roman to Integer
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

int charToInt(char c){
	int ret = -1;
	switch(c){
		case 'M':
			ret = 1000;
			break;
		case 'D':
			ret = 500;
			break;
		case 'C':
			ret = 100;
			break;
		case 'L':
			ret = 50;
			break;
		case 'X':
			ret = 10;
			break;
		case 'V':
			ret = 5;
			break;
		case 'I':
			ret = 1;
			break;
	}
	return ret;
}

int romanToInt(string s) {
    int ret = 0;
    int i;
    for(i=0;i<s.length()-1;i++)
    {	
    	int cur = charToInt(s[i]);
    	int nxt = charToInt(s[i+1]);

    	if(cur >= nxt){
    		ret+=cur;
    	}else{
    		ret += (nxt - cur);
    		i++;
    	}
    }

    if(i == s.length()-1){
    	ret += charToInt(s[i]);
    }

    return ret;
}

int main(){
	vector<string> strs;
	strs.push_back("MMXIV");
	strs.push_back("MDCCCCX");
	strs.push_back("MCMX");

	for(int i=0;i<strs.size();i++){
		int ans = romanToInt(strs[i]);
		cout << strs[i] << " " << ans << endl; 
	}	
	

	return 0;
}

