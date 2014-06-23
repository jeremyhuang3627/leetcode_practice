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

int candy(vector<int> &ratings)
{
	vector<int> candies;
	for(int i=0;i<ratings.size();i++)
	{	
		//cout << "i " << i<< endl;
		if(candies.size()==0)
		{
			candies.push_back(1);
		}else{
			if(ratings[i-1]<ratings[i]){
				candies.push_back(candies.back()+1);
			}else{
				candies.push_back(min(1,candies.back()-1));
			}
		}
	}

	int smallest = 9999;
	int total = 0;

	for(int i=0;i<candies.size();i++)
	{
		total += candies[i];
		cout << candies[i] << endl;
		smallest = min(candies[i],smallest);
	}

	//cout << "smallest " << smallest << "total "<<total <<endl; 
	if(smallest<=0){
		total += (abs(smallest) +1)*candies.size();
	}

	return total;

}

int main()
{
	vector<int> ratings ;
	ratings.push_back(1);
	ratings.push_back(2);
	ratings.push_back(9);
	ratings.push_back(5);
	ratings.push_back(1);

	int ans = candy(ratings);

	cout << "ans " << ans << endl;
	return 0;
}