#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <stdlib.h>

using namespace std;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin(); i!=(v).end(); i++)
#define arraysize(ar) (sizeof(ar)/sizeof(ar[0]))

typedef vector<int> VI;

int evalRPN(vector<string> &v){
	string op[] = {"+","-","*","/"};
	stack<int> s;

	for(int i=0;i<v.size();i++)
	{
		
		string* it = find(op,op+arraysize(op),v[i]);
		if(it != op + arraysize(op))
		{
			int num2 = s.top();
			s.pop();
			int num1 = s.top();
			s.pop();
			int val = 0;
			if(*it == "+"){
				val = num1 + num2;
			}else if(*it == "-")
			{
				val = num1 - num2;
			}else if(*it == "*")
			{
				val = num1 * num2;
			}else if(*it == "/")
			{
				val = num1/num2;
			}
			s.push(val);
		}else{
			s.push(atoi(v[i].c_str()));
		}
	} 
	return s.top();
}

int main(){
	vector<string> v;
	v.push_back("2");
	v.push_back("1");
	v.push_back("+");
	v.push_back("3");
	v.push_back("*");
	cout<<"answer is " << evalRPN(v)<<endl;
	return 0;
}