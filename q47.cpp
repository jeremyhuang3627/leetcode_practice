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

int removeElement(int A[], int n, int elem) {
        int c = n;
        for(int i=0;i<n;i++)
        {
            if(A[i] == elem){
            	for(int j=i;j<n;j++)
            	{
            		A[j]= A[j+1];
            	}
                c--;
                i--;
            }
        }
        return c;
}

int main()
{
	clock_t start;
	double duration;
	int A[] = {2,4,3,1,2,0};
	int n = 6;

	int ans = removeElement(A,n,1);
	cout << "cout " << ans << endl;

	for(int i=0;i<ans;i++)
	{
		cout << A[i]<<" ";
	}
	cout << endl;

	 duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	 cout << "duration is " << duration << endl;
	 return 0;
}