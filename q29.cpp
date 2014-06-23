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

using namespace std;

vector<int> twoSum(vector<int> v,int t)
{
	int i,j,d;
	bool f = false;
	vector<int> ans;
	map<int,vector<int> > m;
	for(i=0;i<v.size();i++){
		m[v[i]].push_back(i);
	}

	sort(v.begin(),v.end());
	int index1,index2;
	for(i=0;i<v.size();i++)
	{
		d = t-v[i];
		for(j=i+1;j<v.size();j++)
		{	
			if(v[i] + v[j] == t){

				if(v[i]==v[j])
				{
					index1 = m[v[i]][0];
					index2 = m[v[i]][1];

				}else{
					index1 = m[v[i]][0];
					index2 = m[v[j]][0];
				}

				if(index2<index1){
						swap(index1,index2);
				}
				ans.push_back(index1+1);
				ans.push_back(index2+1);

				f = true;
				break; 
			}
			if(v[j]>d){
				break;
			}

		}
		if(f){
			break;
		}
	}
	return ans;
}

int main()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(7);
	v.push_back(10);
	v.push_back(11);
	int t = 9;

	vector<int> ans = twoSum(v,t);

	cout << "the answer is"; 

	int i;
	for(i=0;i<ans.size();i++)
	{
		cout << ans[i] << " ";
	}

	cout << endl;
	return 0;
}