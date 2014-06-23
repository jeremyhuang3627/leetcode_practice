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

int divide(int dividend,int divisor)
{	
	long long a = abs((double)dividend);
	long long b = abs((double)divisor);

	if(a < b){
		return 0;
	}

	int ret = 0;

	while(a>=b){
		long long c = b;
		for(int i=0;c<=a;++i,c <<= 1 ){
			a -= c;
			ret += 1<<i;
		}
	}
	
	return ((dividend^divisor)>>31) ? (-ret) : (ret);
}

int main()
{
	clock_t start;
	double duration;
	start = clock();

	int a = -1010369383;
	int b = -2147483648;
	int ans = divide(a,b);

	cout << a << "/"<< b << " is " << ans << endl;

	 duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	 cout << "duration is " << duration << endl;
	return 0;
}