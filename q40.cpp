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

int l = 0;

string putSpace(int l)
{
	string s = "";
	for(int i=0;i<l;i++)
	{
		s+= " ";
	}
	return s;
}

int * look;

int findMax(int A[],int n)
{

	if(n<1){
	 //cout << "returning " << A[n] <<endl;
	 return A[n];
	}
	
	if(look[n]!=-99999){
		return look[n];
	}

	int v1 = findMax(A,n-1)+A[n];
	int v2 = A[n];
	int ans = max(v1,v2);
	look[n] = ans;
	//cout <<"n "<< n <<" v1 "<< v1 << "v2 "<< v2 <<"returning " << ans <<endl;
	return ans;
} 


int maxSubArray(int A[],int n)
{

	int maxSum = -99999;
	look = new int[n];

	for(int i=0;i<n;i++)
	{
		look[i] = -99999;
	}

	for(int i=0;i<n;i++)
	{
		//cout << "maxSum " << maxSum << endl;
		maxSum = max(findMax(A,n-i-1),maxSum);
	}
	return maxSum;
}

int main(){
	int A[] = {-2,1};
	int n = 2;
	int ans = maxSubArray(A,n);
	cout << "ans " << ans << endl;
	return 0;
}