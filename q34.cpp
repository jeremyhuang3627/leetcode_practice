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

int divide(int dividend, int divisor){

	long long a  = abs((double) dividend);
	long long b = abs((double) divisor);


	long long ret = 0;
	while(a>=b){
		long long c = b;
		for(int i=0;a>=c;++i,c<<=1){
			a -= c;
			ret += 1<<i;
		}
	}

	return ((dividend^divisor)>>31) ? (-ret):(ret);
}

int main(){
	int a = -10;
	int b = 2;

	int ans = divide(a,b);
	cout << "ans " << ans <<endl;

	return 0;
}