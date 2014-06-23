// Triangle
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

int minimumTotal(vector<vector<int> > &triangle) {
	if(triangle.size()){
		vector<vector<int> > minSum (triangle.size());

		for(int i=triangle.size()-1;i>=0;i--){
			minSum[i].resize(triangle[i].size());
			for(int j=0;j<triangle[i].size();j++){
				if(i==triangle.size()-1){
					minSum[i][j] = triangle[i][j];
				}else{
					minSum[i][j] = min(minSum[i+1][j]+triangle[i][j],minSum[i+1][j+1]+triangle[i][j]);
				}
			}
		}
	    return minSum[0][0];
	}

	return 0;
}

int main(){

	vector<vector<int> > tri;
	int l1 [] = {-1};

	vector<int> l1_v (l1,l1+sizeof(l1)/sizeof(int));
	tri.push_back(l1_v);

	int l2 [] = {2,3};
	vector<int> l2_v (l2,l2+sizeof(l2)/sizeof(int));
	tri.push_back(l2_v);

	int l3 [] = {1,-1,-3};
	vector<int> l3_v (l3,l3+sizeof(l3)/sizeof(int));
	tri.push_back(l3_v);

	/*int l4 [] = {4,1,8,3};
	vector<int> l4_v (l4,l4+sizeof(l4)/sizeof(int));
	tri.push_back(l4_v); */

	int ans = minimumTotal(tri);
	cout << "ans is " << ans << endl;

	return 0;
}
