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

int maxProfit(vector<int> &prices)
{
	int p = 0;
	int period_p = 0;
	for(int i=1;i<prices.size();i++)
	{	
		if(prices[i-1] > prices[i])
		{
			p += period_p;
			period_p = 0;
		}else{
			period_p += prices[i] - prices[i-1];
		}
	}
	p += period_p;
	period_p = 0;
	return p;
}

int main()
{
	vector<int> prices;
	prices.push_back(1);
	prices.push_back(10);
	prices.push_back(1);
	prices.push_back(10);
	prices.push_back(1);
	prices.push_back(10);
	prices.push_back(1);
	prices.push_back(10);
	prices.push_back(1);
	prices.push_back(10);
	prices.push_back(1);
	prices.push_back(10);

	int p = maxProfit(prices);
	cout<<"max profit is " << p << endl;

	return 0;
}