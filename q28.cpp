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

using namespace std;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin(); i!=(v).end(); i++)

typedef long long ll;
typedef vector<int> VI;

int main()
{
	int N;
	cin >> N;
	REP(i,0,N){
		int vN;
		cin >> vN;
		map<char,int> m;
		char c;
		int val;
		REP(j,0,vN)
		{
			cin >> c >> val;
			m[c] = val;
		}

		int lN;
		cin >> lN;
		string l;
		ll amt = 0;
		REP(k,0,lN+1)
		{
			getline(cin,l);
			const char * p = l.c_str();
			while(*p != '\0')
			{	
				amt += m[*p];
				p++;
			}
		}

		stringstream ss;
		ss << amt/100;
		string dollar = ss.str();
		ss.str("");
		ss << amt%100;
		string dec = ss.str();
		if(amt%100 < 10){
			dec = "0" + dec;
		}
		string ans = dollar + "." + dec + "$";
		cout << ans << endl;
	}
	return 0;
}

