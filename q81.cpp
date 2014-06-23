// Best Time to Buy and Sell Stock III 

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

int maxProfit(vector<int> &prices)
{
	if(prices.size()){

		vector<int> profits;

		int one_tran_profit = 0; 
		int min_price = prices[0];
		
		int min_index = 0;
		int start=0;
		int end=0;

		for(int i=0;i<prices.size();i++){
			if(prices[i] < min_price){
				min_price = prices[i];
				min_index = i;
			}	

			if( prices[i] - min_price > one_tran_profit)
			{
				one_tran_profit = prices[i] - min_price;
				start = min_index;
				end = i;
			}
		}

		profits.push_back(one_tran_profit);
		cout << "one_tran_profit is " << one_tran_profit << endl;
		cout << "start is " << start << " end is " << end << endl;

		int max_profit_2 = 0;
		int min_price_2 = prices[end];

		for(int i=end;i>=start;i--)
		{
			if(prices[i] < min_price_2){
				min_price_2 = prices[i];
			}	

			if( prices[i] - min_price_2 > max_profit_2)
			{
				max_profit_2 = prices[i] - min_price_2;
			}
		}

		profits.push_back(one_tran_profit + max_profit_2);
		cout << "min_price_2 is " << min_price_2 << " max_profit_2 is " << max_profit_2 << endl;

		//max_profit = max(max_profit,max_profit + max_profit_2);

		int max_profit_3 = 0;
		int min_price_3 = prices[0];

		for(int i=0;i<start;i++)
		{
			min_price_3 = min(prices[i],min_price_3);
			max_profit_3 = max(max_profit_3,prices[i]-min_price_3);
		}

		int max_profit_4 = 0;
		int min_price_4 = 0;
		if(end < prices.size()-2){
			min_price_4 = prices[end+1];
			for(int i=end+1;i<prices.size();i++)
			{
				min_price_4 = min(prices[i],min_price_4);
				max_profit_4 = max(max_profit_4,prices[i]-min_price_4);
			}
		}

		cout << "max_profit_3 " << max_profit_3 << endl;
		cout << "max_profit_4 " << max_profit_4 << endl;
		profits.push_back(one_tran_profit + max_profit_3);
		profits.push_back(one_tran_profit + max_profit_4);
		profits.push_back(max_profit_4 + max_profit_3);
		return *max_element(profits.begin(),profits.end());
	}
	return 0;
}

int main(){
	int a [] = {2,4,1};
	vector<int> prices (a,a + sizeof(a)/sizeof(int));
	int ans = maxProfit(prices);
	cout << "ans " << ans << endl;
	return 0;
}