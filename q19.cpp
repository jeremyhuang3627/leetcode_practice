#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <stdlib.h>
#include <tr1/unordered_set>
#include <queue>
#include <set>
#include <map>
#include <sstream> 

using namespace std;

void trim(string &s)
{
	size_t p = s.find_first_not_of(" \t");
	s.erase(0,p);

	p = s.find_last_not_of(" \t");
	s.erase(p+1);
}

vector<string> split(string &s, char delim)
{
	trim(s);
	istringstream iss(s);
	vector<string> v;
	do{
		string sub;
		iss >> sub;
		v.push_back(sub);
	}while(iss);

	return v;
}

void reverseWords(string &s)
{
	vector<string> arr = split(s,' ');
	int mid = arr.size()/2;
	for(int i=0;i<mid;i++)
	{	
		string temp = arr[i];
		int end = arr.size()-i-1;
		arr[i] = arr[end];
		arr[end] = temp;
	}
	string res = "";
	int end = arr.size()-1;
	for(int i=0;i<end;i++)
	{	
		res += arr[i] + " "; 
	}
	if(arr.size()>0){
		res += arr[arr.size()-1];
	}
	trim(res);
	s = res;
}

int main()
{
	string s = "  a  b";
	reverseWords(s);
	cout << "output" <<endl;
	cout << s <<endl;
	cout << s.size() <<endl;
	return 0;
}