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

struct Interval{
	int start;
	int end;
	Interval():start(0),end(0){}
	Interval(int s,int e):start(s),end(e){}
};

vector<Interval> merge(vector<Interval> &intervals) {
    int i=0;
    vector<Interval> v;
    while(i<intervals.size())
    {
    	int j= i+1;
    	Interval ni (intervals[i].start,intervals[i].end);
    	while(j < intervals.size() && intervals[j].start < intervals[i].end){	
    		ni.start = min(intervals[j].start,ni.start);
    		ni.end = max(intervals[j].end,ni.end);
    		j++;
    	}
    	v.push_back(ni);
    	i = j;
    }

    return v;
}

int main()
{
	vector<Interval> v;
	Interval in (1,3);
	v.push_back(in);
	in.start = 2; 
	in.end = 6;
	v.push_back(in);
	in.start = 8;
	in.end = 10;
	v.push_back(in);
	in.start = 15;
	in.end = 18;
 
	cout << "before"<< endl;

	for(int i=0;i<v.size();i++)
	{
	 	cout << "[" << v[i].start <<","<<v[i].end << "]" <<endl;
	}

	vector<Interval> nv = merge(v);

	cout<< "after" << endl;

	for(int i=0;i<nv.size();i++)
	{
	 	cout << "[" << nv[i].start <<","<<nv[i].end << "]" <<endl;
	}

	return 0;
}