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

int canCompleteCircuitAt(int i,vector<int> &gas,vector<int> &cost)
{
	int j = i;
	int tank = 0;
	do{	
		tank += gas[j];
		tank -= cost[j];
		if(tank < 0){
			return j;
		}
		j = (j+1)%gas.size();
	}while(j!=i);
	return j;
}

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{	
	int i =0;
	while(i < gas.size()){
		if(gas[i]>=cost[i]){
			int j = canCompleteCircuitAt(i,gas,cost);
			if(j!= i){
				if(j<i)
				{
					return -1;
				}
				i =  j + 1 ;
			}else{
				return i;
			}
		}else{
			i ++ ;
		}
	}

	return -1;
}


int main()
{	
	int gas[] = {2,4};
	int cost[] = {3,4};
	vector<int> gasV (gas,gas+2);
	vector<int> costV (cost,cost+2);
	int gasStation = canCompleteCircuit(gasV,costV);
	cout << "gasStation is " << gasStation << endl;
	return 0;
}