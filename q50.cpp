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

void merge(int A[],int m, int B[],int n)
{
	int C[m+n];
	int i,j,k;
	i = k = j = 0;

	while(i<m && j<n)
	{
		if(A[i] > B[j])
		{
			C[k] = B[j];
			j++;
		}else{
			C[k]= A[i];
			i++;
		}
		k++;
	}

	while(i<m)
	{
		C[k] = A[i];
		k++;
		i++;
	}

	while(j<n)
	{
		C[k] = B[j];
		k++;
		j++;
	}

	for(int i=0;i<m+n;i++)
	{
		A[i] = C[i];
	}
}

int main()
{
	int A[] = {1,2,3,4,5,6};
	int m = 6;
	int B[] = {3,4,6,9,10};
	int n = 5;

	merge(A,m,B,n);

	for(int i=0;i<m+n;i++)
	{	
		
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}