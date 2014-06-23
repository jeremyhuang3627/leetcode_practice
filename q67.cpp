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

struct cmp{
	bool operator()(Interval i1,Interval i2){
		return i1.start < i2.start;
	}

};

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
	vector<Interval> v;
	if(intervals.size()==0){
		v.push_back(newInterval);
		return v;
	}

	Interval ni (newInterval.start,newInterval.end);
	for(int i=0;i<intervals.size();i++)
	{
		if(intervals[i].end < newInterval.start){
			v.push_back(intervals[i]);
		}else if(intervals[i].start > newInterval.end){
			v.push_back(intervals[i]);
		}else{
			ni.start = min(intervals[i].start,ni.start);
			ni.end = max(intervals[i].end,ni.end);
		}
	}
	v.push_back(ni);
	sort(v.begin(),v.end(),cmp());
	return v;
}

void printInterval(vector<Interval> v){
	for(int i=0;i<v.size();i++)
	{
		cout << "[" << v[i].start << "," << v[i].end << "]" << endl; 
	}
}

int main(){	
	vector<Interval> v;
	Interval i (1,5);
//	Interval i2 (6,9);

	v.push_back(i);
	//v.push_back(i2);

/*	v.push_back(i);
	i.start = 3;
	i.end = 5;
	v.push_back(i);
	i.start = 6;
	i.end = 7;
	v.push_back(i); 
	i.start = 8;
	i.end = 10;
	v.push_back(i);
	i.start = 12;
	i.end = 16;
	v.push_back(i); */

	cout << "before insertion " << endl;
	printInterval(v);

	Interval toInsert (6,8);
	vector<Interval> nv = insert(v,toInsert);

	cout << "after insertion " << endl;
	printInterval(nv);


	return 0;
}