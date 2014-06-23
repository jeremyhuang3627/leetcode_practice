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

int * look;

int getNum(string s,int n)
{
	if(n<= 1)
	{
		return 1;
	}else if(look[n]!=0){
		return look[n];
	}else if(n>0){
		int num = 0;
		if(n >= 2){
			string lasttwo = s.substr(n-2,2);
			if (atoi(lasttwo.c_str()) >=10 && atoi(lasttwo.c_str()) <= 26){
				cout << "lasttwo " << atoi(lasttwo.c_str()) << endl;
				num += getNum(s,n-2);
			}
		}
		if(s.substr(n-1,1)!="0"){
			num += getNum(s,n-1);
		}
		look[n] = num;
		return num;
	}
	return 0;
}

int numDecodings(string s)
{
	if(s.size()==0 || s.substr(0,1) == "0")
	{
		return 0;
	}
	look = new int[s.size()];
	int ans = getNum(s,s.length());
	return ans;
}


int main()
{
	string s = "101";
	int ans = numDecodings(s);

	cout << "num ways " << ans << endl;
	return 0;
}