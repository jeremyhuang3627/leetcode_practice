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

void printBoard(vector<vector<char> > &board){
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

vector<int> getPosVal(vector<vector<char> > &board, int i, int j){
	vector<int> val;
	if(board[i][j] != '.' || i>=9 || i < 0 || j>=9 || j <0 ){
		return val;
	}

	vector<int> allVal (9,false);
	// check col
	for(int row=0;row<9;row++){
		if(board[row][j] != '.'){
			allVal[board[row][j]-'0'-1] = true;
		}
	}

	//check row
	for(int col=0;col<9;col++){
		if(board[i][col] !='.'){
			allVal[board[i][col]-'0'-1] = true;
		}
	}

	//check 3*3 box


	//find which 3*3 box i, j is in:
	int si,sj;
	si = i/3*3;
	sj = j/3*3;

	for(int row=si;row<si+3;row++)
	{
		for(int col=sj;col<sj+3;col++)
		{
			if(board[row][col]!='.'){
				//cout << "t1 " << endl;
				allVal[board[row][col]-'0'-1] = true;
				//cout << " allVal[board[row][col]-1] " << allVal[board[row][col]-1]<<endl; 
			}
		}
	}

	vector<int> ret;
	for(int pos=0;pos<10;pos++)
	{
		if(!allVal[pos]){
			//cout << "pushing " << pos + 1 << endl; 
			ret.push_back(pos+1);
		}
	}

	return ret;
}	

pair<int,int> findFirstEmpty(vector<vector<char> > &board)
{
	for(int row=0;row<9;row++)
		for(int col=0;col<9;col++)
			if(board[row][col]=='.') return make_pair(row,col);
	return make_pair(-1,-1);
}

bool solved = false;

int l = 0;

void solveSudoku(vector<vector<char> > &board) {
    pair<int,int> p = findFirstEmpty(board);
    //cout << "first empty " << p.first <<", " <<p.second <<endl;
    l++;
    string s = "";
    for(int i=0;i<l;i++)
    {
    	s += " ";
    }
    //cout  << s ;
    //printBoard(board);

    if(p.first == -1 && p.second == -1){
    	solved = true;
    	return;
    }

    vector<int> allPosVal = getPosVal(board,p.first,p.second);
    for(int i=0;i<allPosVal.size();i++){
    	//cout << s <<"val is " << allPosVal[i] << " i "<< p.first <<" j " <<p.second;
    	board[p.first][p.second] = allPosVal[i]+'0';
    	printBoard(board);
    	solveSudoku(board);
    	if(!solved){
    		board[p.first][p.second] = '.';
    	}else{
    		l--;
    		return;
    	}
    }
    l--;
}	

vector<vector<char> > initBoard(string strArr[]){
	vector<vector<char> > board;
	for(int i =0;i<9;i++)
	{
		vector<char> line;
		const char * sp = strArr[i].c_str();
		for(int j=0;j<9;j++)
		{
			line.push_back(sp[j]);
		}
		board.push_back(line);
	}
	return board;
}

int main(){
	string strArr[] = {"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};
	vector<vector<char> > board = initBoard(strArr);

/*	printBoard(board);

	vector<int> allPosVal = getPosVal(board,0,2);
	for(int i=0;i<allPosVal.size();i++)
	{
		cout << allPosVal[i] << " ";
	}

	cout << endl; */
	cout<< "Before solve board is " << endl;

	printBoard(board);

	solveSudoku(board);

	cout<< "After solve board is " << endl; 

	printBoard(board); 

	return 0;
}