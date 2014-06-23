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

map<int,int> m;

int getCount(int n){
	if(n<=1)
	{
		return 1;
	}else if(m[n] != 0)
	{
		return m[n];
	}else{
		m[n] = getCount(n-1) + getCount(n-2);
		return m[n];
	}
}	

int climbStairs(int n)
{
	int c = getCount(n);
	return c;
}

int main()
{
	int n = 2;
	cout << " to climb steps " << climbStairs(n) << endl;
	return 0;
}