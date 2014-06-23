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

ll cycleLen(ll n){
	ll c = 0;

	while(true){
		c++;
		if(n==1){break;}
		if(n%2==1){
			n = 3*n+1;
		}else{
			n = n>>1;
		}
	}
	return c;
}

int main()
{
	ll i,j,max;
	while(cin >> i >> j){
		int swaped = false;
		if(i>j){
		 swaped = true;
		 swap(i,j);
		};
		max = 0;
		for(ll k=i;k<=j;k++)
		{
			ll l = cycleLen(k);
			if(l > max){
				max = l;
			}
		}

		if(swaped){
			cout << j << " " << i << " " << max <<endl; 
		}else{
			cout << i << " " << j << " " << max <<endl; 
		}
	}
	return 0;
}
