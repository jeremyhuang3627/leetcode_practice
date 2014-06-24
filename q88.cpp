//Subsets
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

vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > sets;
    sort(S.begin(),S.end());
    vector<int> set;
    vector<int> temp;
    int cur_size = 0;
    sets.push_back(set);
   	for(int i=0;i<S.size();i++){
   		cur_size = sets.size();
   		for(int j=0;j<cur_size;j++){
   			temp = sets[j];
   			temp.push_back(S[i]);
   			sets.push_back(temp);
   		}
   	}

   	return sets;
}

int main(){
	int t [] = {1,2,3};
	vector<int> S (t,t+sizeof(t)/sizeof(int));
	vector<vector<int> > ans = subsets(S);

	for(int i=0;i<ans.size();i++)
	{	
		for(int j=0;j<ans[i].size();j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}