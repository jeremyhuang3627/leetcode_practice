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
#include <tr1/unordered_set>
#include <ctime>

using namespace std;

int add(int n){
    return n*(n+1)/2;
}

int candy(vector<int> &ratings) {
    vector<int> c (ratings.size(),0);

    c[0] = 1;
    // left to right
    for(int i=1;i<ratings.size();i++){
        c[i] = (ratings[i] > ratings[i-1]) ? c[i-1] + 1 : 1;  
    }

    int sum = 0;
    // right to left
    for(int i=ratings.size()-1;i>=1;i--){
        if(ratings[i-1] > ratings[i]){
            if(c[i-1]<=c[i]){
                c[i-1] = c[i] + 1;
            }
        }
        sum += c[i];
    }

    sum += c[0];
    return sum; 
}

int main(){
	std::clock_t start;
    double duration;
    
	int a[] = {4,2,3,4,1};
    vector<int> ratings (a,a + sizeof(a)/sizeof(int));
	start = std::clock();
	int ans = candy(ratings);

	cout << "ans is " << ans << endl;
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"printf: "<< duration <<'\n';
	return 0;
}