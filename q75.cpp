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
#include <tr1/unordered_set>
#include <ctime>

using namespace std;

int singleNumber(int A[], int n) {
    map<int,int> m;
    for(int i=0;i<n;i++){
    	m[A[i]] ++;
    	if(m[A[i]]==3){
    		m.erase(A[i]);
    	}
    }

    if(m.size()==1){
    	return m.begin()->first;
    }else{
    	return -1;
    }
}

int main(){
	int n = 7;
	int a[] = {1,2,3,1,2,2,1};
	int ans = singleNumber(a,n);
	cout << "ans is " << ans;
	return 0;
}