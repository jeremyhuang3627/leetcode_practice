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

vector<vector<int> > threeSum(vector<int> &num)
{
	vector<vector<int> > v;
	if(num.size()<3)
	{
		return v;
	}
	sort(num.begin(),num.end());
	for(int i=0;i<num.size();i++)
	{
		if(i==0 || num[i] > num[i-1])
		{
			int start = i + 1;
			int end = num.size()-1;
			while(start<end){
				int diff = 0 - (num[i]+num[end]);
				//cout << "diff " << diff << endl;
				if(num[start] == diff){
					//cout << "same num[start] "<<num[start] << endl;
					vector<int> nv;
					nv.push_back(num[i]);
					nv.push_back(num[start]);
					nv.push_back(num[end]);
					v.push_back(nv);
					start++;
					end--;
				}else if(num[start] > diff){
					end--;
					//cout << "end " << end << endl;
				}else{
					start++;
					//cout << "start " << start << endl;
				}
			}
		}
	}
	return v;
}

/*
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
} */


int main()
{
	std::clock_t start;
	double duration;
	start = clock();
	int myints[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	vector<int> num (myints,myints + sizeof(myints)/sizeof(int));	
	vector<vector<int> > ans = threeSum(num);
	duration = (clock()-start)/(double) CLOCKS_PER_SEC;
	std::cout << "time is " <<duration << std::endl;

	for(int i=0;i<ans.size(); i++)
	{
		cout << "[";
		for(int j=0;j<ans[i].size();j++)
		{
			cout << ans[i][j] << ",";
		}

		cout <<"]"<< endl;
	}	

	return 0;
}