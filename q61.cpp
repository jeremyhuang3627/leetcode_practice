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

//using namespace std;
/*
 double powAbs(double x,int n)
  {
    	if(n==1){
    			return x;
    	}
    	return x*pow(x,n-1);
    
  } */


double powAbs(double x,int n)
{
	if(n==0)
	{
		return 1;
	}

	if(n==1)
	{
		return x;
	}

	double v = pow(x,n/2);

	if(n%2==0){
		return  v * v;
	}else{
		return  v * v * x;
	}

} 

double pow(double x, int n)
{
	return (n>0) ? powAbs(x,n) : 1/powAbs(x,-n) ;
}

int main(){
	std::clock_t start;
	double duration;
	start = clock();
	double x = 2;
	int n = 100;
	std::cout << "ans " << pow(x,n) <<std::endl;
	duration = (clock()-start)/(double) CLOCKS_PER_SEC;
	std::cout << "time is " <<duration << std::endl;
	std::cout << "correct ans is " << std::pow(x,n)<<std::endl;
	return 0;
}