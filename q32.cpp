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

using namespace std;

double findMedianSortedArrays(int A[],int m, int B[], int n)
{
	bool isEven = false;
	if(m+n%2 == 0){
		isEven = true;
	}

	int si;
	if(isEven)
	{
		si = (m+n)/2-1;
	}else{
		si  = (m+n)/2;
	}
	int count = 0;
	int ai = 0;
	int bi = 0;
	double me;

	while(count<si && ai < m  && bi < n)
	{
		if(A[ai] > B[bi]){
			bi++;
		}else{
			ai++;
		}
		count++;
	}

	while(count < si && ai < m)
	{
		ai++;
		count++;
	}

	while(count < si && bi < n)
	{
		bi++;
		count++;
	}

	if(isEven){
		me = (A[ai] + B[bi])/2; 
	}else{
		me = min(A[ai],B[bi]); 
	}

	return me;
}

int main(){
	int A[] = {};
	int m = 0;
	int B[] = {1};
	int n = 1;
	double ans = findMedianSortedArrays(A,m,B,n);
	cout << ans << endl;
}