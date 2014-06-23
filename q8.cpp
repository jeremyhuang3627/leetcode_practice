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

int reverse(int x)
{
	int ret = 0;
	while(x!=0){
		ret = ret*10 +x%10;
		x = x/10;
	}
	return ret;
}

int main(){
	int x = -123;
	int ret = reverse(x);

	cout << ret << endl;
	return 0;
}