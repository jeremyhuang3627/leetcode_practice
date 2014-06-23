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

using namespace std;

int maxProfit(vector<int> &prices) {
	// find the max and min
	if(prices.size()){
		int maxProfit = 0;
		int minPrice = prices[0];

		for(int i=0;i<prices.size();i++)
		{
			minPrice = min(minPrice,prices[i]);
			maxProfit = max(maxProfit,prices[i]-minPrice);
		}

		return maxProfit;
	}

	return 0;
}

int main(){
	std::clock_t start;
    double duration;
    start = std::clock();

    int a [] = {1,2,3,5,5,5,5,100};

    vector<int> prices (a,a + sizeof(a)/sizeof(int));

    int ans = maxProfit(prices);

    cout << "ans " << ans << endl;

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	std::cout<<"printf: "<< duration <<'\n';
	return 0;
}