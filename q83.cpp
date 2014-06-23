// Triangle
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

using namespace std;

vector<vector<int> > look;

bool checkInterleave(string s1, string s2, string s3,int i1,int i2,int i3){

	if(i1 == s1.length() && i2 == s2.length() && i3 == s3.length())
	{
		return true;
	}else if(i3 == s3.length()){
		return false;
	}

	if(look[i1][i2]!=-1){
		return look[i1][i2];
	}

	if(s1[i1] != s2[i2]){
   		if(s1[i1]==s3[i3]){
   			look[i1][i2] = checkInterleave(s1, s2, s3, i1+1, i2, i3+1);
   			return look[i1][i2];
   		}else if(s2[i2]==s3[i3]){
   			look[i1][i2] = checkInterleave(s1, s2, s3, i1, i2+1, i3+1);
   			return look[i1][i2];
   		}
   }else{
   		if(s1[i1] == s3[i3]){
   			look[i1][i2] = (checkInterleave(s1, s2, s3, i1, i2+1, i3+1) || checkInterleave(s1, s2, s3, i1+1, i2, i3+1) );
   			return look[i1][i2];
   		}
   }

   return false;
}

bool isInterleave(string s1, string s2, string s3) {
   if(s1.length()==0 && s2.length()==0 && s3.length()==0 ){
   	return true;
   }	

    if(s1.length()==0){
		return s2 == s3;
	}else if(s2.length()==0){
		return s1 == s3;
	}else if(s3.length()==0)
	{
		return false;
	}

  	look.resize(s3.size()+1);
  	for(int i=0;i<look.size();i++)
  	{
  		look[i].resize(s3.size()+1,-1);
  	} 
   return checkInterleave(s1,s2,s3,0,0,0);
}

int main(){
	std::clock_t start;
    double duration;
    start = std::clock();
	string s1 = "a";
	string s2 = "b";

	string s3_true = "ab";
//	string s3_false = "aadbbbaccc";

	cout << "s3 is " << isInterleave(s1,s2,s3_true) << endl;
//	cout << "s3_false is " << isInterleave(s1,s2,s3_false) << endl;

	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	std::cout<<"printf: "<< duration <<'\n';
	return 0;
}