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

int numTreesRange(int s,int e)
{
	if(s>=e){
		return 1;
	}

	int num = 0;
	for(int i=s;i<=e;i++)
	{
		int numi = numTreesRange(s,i-1) * numTreesRange(i+1,e);
		num += numi;
	}

	return num;
}

int numTrees(int n)
{
	if(n<1){
		return 0;
	}
	
	int num = numTreesRange(1,n);
	return num;
}

int main()
{	
	int n = 3;
	int ans = numTrees(n);
	cout << "n is " << n << " ans " << ans << endl;
}