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

using namespace std;

void BFS(pair<int,int> p,vector<vector<char> > &board)
{
	int rows = board.size();
	int cols = board[0].size();

	queue<pair<int,int> > q;
	map<pair<int,int> ,bool> m;
	m[p] = true;
	q.push(p);

	while(!q.empty())
	{
		p = q.front();
		q.pop();

		int r,c;
		for(int i=0;i<4;i++)
		{
			switch(i){
				case 0:
					r = p.first-1;
					c = p.second;
					break;
				case 1:
					r = p.first;
					c = p.second-1;
					break;
				case 2:
					r = p.first+1;
					c = p.second;
					break;
				case 3:
					r = p.first;
					c = p.second+1;
					break;
			}

			if(r >=0 && c >=0 && r < rows && c < cols)
			{	
				if(!m[make_pair(r,c)] && board[r][c] == 'O')
				{
					board[r][c] = 'V';
					m[make_pair(r,c)] = true;
					q.push(make_pair(r,c));
				}
			}
		}		
	}

}

void solve(vector<vector<char> > &board)
{	
	if(board.size() != 0){
		int rows = board.size();
		int cols = board[0].size();

		for(int r=0;r<rows;r++)
		{

			if(board[r][0] == 'O')
			{	
				board[r][0] = 'V';
			//	cout << "board[r][0]" << board[r][0] << endl;
				pair<int,int> p = make_pair(r,0);
				BFS(p,board);
			}


			if(board[r][cols-1] == 'O')
			{	
				board[r][cols-1] = 'V';
			//	cout << "board[r][cols-1]" << board[r][cols-1] << endl;
				pair<int,int> p = make_pair(r,cols-1);
				BFS(p,board);
			}

		}

		for(int c=0;c<cols;c++)
		{
			if(board[rows-1][c] == 'O')
			{	
				board[rows-1][c] = 'V';
			//	cout << "board[rows-1][c]" << board[rows-1][c] << endl;
				pair<int,int> p = make_pair(rows-1,c);
				BFS(p,board);
			}
			if(board[0][c] == 'O')
			{	
				board[0][c] = 'V';
				//cout << "board[0][c]" << board[0][c] << endl;
				pair<int,int> p = make_pair(0,c);
				BFS(p,board);
			}
		}

		for(int r=0;r<rows;r++)
		{
			for(int c=0;c<cols;c++)
			{
				if(board[r][c] == 'V')
				{
					board[r][c] = 'O';
				}else if(board[r][c] == 'O')
				{
					board[r][c] = 'X';
				}
			}
		}  
	}
}

int main(){
	vector<vector<char> > m (20);

	for(int i=0;i<m.size();i++)
	{	
		for(int j=0;j<20;j++){
			if(rand()%2){
				m[i].push_back('O');
			}else{
				m[i].push_back('X');
			}
		}
	} 

	cout<< "before" <<endl;
	for(int i=0;i<m.size();i++)
	{
		for(int j=0;j<m[0].size();j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

	solve(m);
	cout<< "after" <<endl;

	for(int i=0;i<m.size();i++)
	{
		for(int j=0;j<m[0].size();j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}