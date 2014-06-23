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

int searchInsert(int A[],int n,int target)
{
	if (target <= A[n-1] && target > A[0]){

		int res = -1;
		int high = n-1;
		int low = 0;
		int mid = high/2;

		while(low !=  mid)
		{
			if(target > A[mid])
			{
				low = mid;
				mid = (high+low)/2;
			}else if(target < A[mid]){
				high = mid;
				mid = (high+low)/2;
			}else{
				return mid;
			}
		}
		return low + 1;
	}else if(target <= A[0]){
		return 0;
	}else{
		return n;
	}
}


int main()
{	
	int test[4] = {1,3,5,6};
	int index = searchInsert(test,4,0);
	cout << "index is " << index << endl;
	return 0;
}



