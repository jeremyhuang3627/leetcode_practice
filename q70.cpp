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

vector<int> spiralOrder(vector<vector<int> > &matrix) {
	vector<int> v;
	if(matrix.size()!=0){
		 int m = matrix[0].size();
		 cout << "m " << m <<endl;
		 int n = matrix.size();
		 int c = 0;
		 int i=0;
		 int j=0;
		 
		 while(true){
		 	cout << "t1" << endl;
		 	for(j=c;j<=m-1-c;j++)
		 	{	
		 		cout << "t2 ";
		 		cout << "i "<< i << " j " << j;
		 		cout<< " b " << matrix[i][j] << " " << endl;
		 		v.push_back(matrix[i][j]);
		 	}
		 	j--;

		 	if(v.size()==n*m){
		 		break;
		 	}
		 	cout << "t4 "<<endl;
		 	for(i=c+1;i<=n-1-c;i++)
		 	{
		 		cout << "t3 "<<endl;
		 		cout << "i "<< i << " j " << j;
		 		cout<< " b " << matrix[i][j] << " " << endl;
		 		v.push_back(matrix[i][j]);
		 	}
		 	i--;

		 	if(v.size()==n*m){
		 		break;
		 	}

		 	for(j=m-2-c;j>=c;j--)
		 	{
		 		cout<< matrix[i][j] << " ";
		 		v.push_back(matrix[i][j]);
		 	}
		 	j++;

		 	if(v.size()==n*m){
		 		break;
		 	}

		 	for(i=n-2-c;i>=c+1;i--)
		 	{
		 		cout<< matrix[i][j] << " ";
		 		v.push_back(matrix[i][j]);
		 	}
		 	i++;

		 	if(v.size()==n*m){
		 		break;
		 	}

		 	c++;
		 } 
	}
	return v;
}

int main()
{
	int myints[] = {1,2,3,4,5,6,7,8,9};
	vector<vector<int> > board;
	int m = 3;
	int n = 3;
	for(int row=0;row<n;row++)
	{
		vector<int> r;
		for(int col=0;col<m;col++)
		{
			r.push_back(myints[col+row*m]);
		}
		board.push_back(r);	
	}

	for(int i=0;i<board.size();i++)
	{
		for(int j=0;j<board[i].size();j++)
		{
			cout << board[i][j] << " ";
		}
		cout<< endl;
	}

	vector<int> list = spiralOrder(board);

	for(int i=0;i<list.size(); i++)
	{
		cout << list[i] << ",";
	}
	cout << endl;
	return 0;
}