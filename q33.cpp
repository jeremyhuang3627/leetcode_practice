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

vector<vector<int> > threeSum(vector<int> &num)
{
	if(num.size()>2){
		vector<int> pos;
		vector<int> npos;

		for(int i=0;i<num.size();i++)
		{
			if(num[i]>0){
				pos.push_back(num[i]);
			}else{
				npos.push_back(num[i]);
			}
		}

		sort(pos.begin(),pos.end());
		sort(npos.begin(),npos.end());

		int c1,c2,c3;

		c1=0;
		c2=1;
		c3=npos.size()-1;
		set<vector<int> > s;

		while(c1<pos.size()){
			while(c2<pos.size() && c3>=0)
			{
				int sum = pos[c1] + pos[c2] + npos[c3];
				if(sum > 0){
					c3--;
				}else if(sum<0){
					c2++;
				}else{
					vector<int> v;
					v.push_back(npos[c3]);
					v.push_back(pos[c1]);
					v.push_back(pos[c2]);
					s.insert(v);
					c2++;
				}
			}
			c1++;
			c3=npos.size()-1;
			c2=c1+1;
		} 

		c1 = npos.size()-1;
		c2 = npos.size()-2;
		c3 = 0;

		while(c1>0)
		{
			while(c2>=0 && c3<pos.size()){
				int sum = npos[c1] + npos[c2] + pos[c3];
				if(sum>0)
				{
					c3++;
				}else if(sum<0)
				{
					c2--;
				}else{
					vector<int> v;
					v.push_back(npos[c2]);
					v.push_back(npos[c1]);
					v.push_back(pos[c3]);
					s.insert(v);
					c2--;
				}
			}
			c1--;
			c3=0;
			c2 = c1 - 1;
		}	

		set<vector<int> >::iterator it;
		vector<vector<int> > ans;
		for(it=s.begin();it!=s.end();it++)
		{	
			ans.push_back(*it);
		}
		return ans;
	}else{
		vector<vector<int> > ans;
		return ans;
	}
}

vector<string> split(string s,char delim)
{
	const char * c = s.c_str();
	vector<string> v;
	string ns = "";
	while(*c!='\0')
	{	
		if(*c !=delim){
			ns += *c;
		}else{
			v.push_back(ns);
			ns="";
		}
		c++;
	}
	v.push_back(ns);

	return v;
}

vector<int> stringToVec(string s)
{
	string ns = s.substr(1,s.length()-2);
	vector<string> v = split(ns,',');
	vector<int> vi;
	for(int i=0;i<v.size();i++)
	{
		vi.push_back(atoi(v[i].c_str()));
	}
	return vi;
}

int main(){
	clock_t start = clock();
	double duration;
	string input = "[-12,-1,4,-14,0,10,7,-7,-6,9,6,-2,7,13,9,-1,4,12,9,4,14,0,-4,0,0,10,2,-7,7,-4,-11,10,2,8,4,-12,-4,-12,-4,-3,12,9,11,4,-1,-3,10,-12,-6,-4,-1,-14,3,2,-7,-11,-3,10,-11,-10,13,-15,7,0,0,-4,-5,11,0,-2,-14,-11,-8,12,1,-1,-14,-12,-6,-5,0,9,-4,-12,-4,4,14,9,-9,10,14,-11,10,6,-3,-4,10,-1,14,-13,13,7,-9,12,4,-1,-4,5,3,6,8,10,0,11,13,11,-7,5,-3,-1,0,-4,-4,-4,10,0]";
	vector<int> num = stringToVec(input);
	vector<vector<int> > ans = threeSum(num);

	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<3;j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	} 

	duration = (std::clock() - start ) / (double) CLOCKS_PER_SEC;

	cout << "time used " << duration <<endl;
	return 0;
}