//Regular Expression Matching
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <tr1/unordered_map>
#include <ctime>
#include <cctype>

using namespace std;

double findMedianSortedArrays(int A[], int m, int B[], int n) {
     int len = m + n;
     vector<double> v;
     v.resize(len);

    int ia = 0;
    int ib = 0;

    for(int i=0;i<len;i++){
     	if(A[ia] > B[ib]){
     		v[i] = B[ib];
     		ib++;
     	}else{
     		v[i] = A[ia];
     		ia++;
     	}
    }

    if(len%2 == 1){
    	return (double)v[len/2];
    }else{
    	return (v[len/2-1] + v[len/2])/(double)2;
    }
}

int main(){
	int A [] = {};
	int m = 0;
	int B [] = {1};
	int n = 1;

	double ans = findMedianSortedArrays(A,m,B,n);

	cout << "ans " << ans <<endl;

	return 0;
}