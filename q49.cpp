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

vector<int> sol;
vector<vector<int> > v;
int sum;
set<vector<int> > s;

void DFS(vector<int> candidates,int target)
{
	for(int i=0;i<candidates.size();i++)
	{
		sum+=candidates[i];
		sol.push_back(candidates[i]);
		if(sum<target){
			DFS(candidates,target);	
		}else if(sum==target){
			vector<int> temp (sol.size());
			copy(sol.begin(),sol.end(),temp.begin());

			sort(temp.begin(),temp.end());
			if(s.count(temp)==0)
			{
				v.push_back(temp);
				s.insert(temp);
			}
		}
		sum -= candidates[i];
		sol.pop_back();
	}
}

vector<vector<int> > combinationSum(vector<int> candidates,int target)
{
	sum = 0;
	DFS(candidates,target);
	return v;
}

int main()
{
	vector<int> candidates;
	candidates.push_back(1);
	candidates.push_back(2);

	int target = 4;
	vector<vector<int> > ans = combinationSum(candidates,target);

	for(int i=0;i<ans.size();i++)
	{
		cout << "[";
		for(int j=0;j<ans[i].size();j++)
		{
			cout << ans[i][j] << ",";
		}
		cout << "]";
	}
	cout << endl; 

	return 0;
}