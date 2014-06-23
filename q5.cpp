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

int singleNumber(int a[],int n){
	map<int,int> m;
	for(int i=0;i<n;i++)
	{
		m[a[i]]++;	
	}

	for(int i=0;i<n;i++)
	{
		if(m[a[i]]==1)
		{
			return a[i];
		}
	} 

	return 0;
}


int main()
{
	int n=21;
	int a[n];

	for(int i=0;i<20;i+=2)
	{
		a[i]= a[i+1] = i;
	}

	a[n-1] = 13;

	cout << "original array " << endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}

	int ans = singleNumber(a,n);

	cout << "single number is " << ans << endl;

	return 0;
}