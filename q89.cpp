//Distinct Subsequences 
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

int numDistinct(string S, string T) {
	int m = T.length();
	int n = S.length();
	if (m > n) return 0;
	vector<vector<int> > path (m+1,vector<int> (n+1,0));

	for(int i=0;i<=n;i++){
		path[0][i] = 1;
	}

	for(int j=1;j<=n;j++){
		for(int i=1;i<=m;i++){
			path[i][j] = path[i][j-1] + (T[i-1] == S[j-1] ? path[i-1][j-1] : 0);
		}
	}

	return path[m][n];
}

int main(){
	string S = "rabbbit";
	string T = "rabbit";

	int num  = numDistinct(S,T); 

	cout << "num " << num <<endl;
	return 0;
}