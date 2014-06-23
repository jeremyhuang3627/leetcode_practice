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
#include <ctime>

using namespace std;

bool found;
map<pair<int,int> , bool> m; 

/*
   bool search(vector<vector<char> > &board, int i,int j,string str,vector<vector<bool> > &mask){
        if (str.size()==0){return true;}
        else{
            if ((i>0)&&(board[i-1][j]==str[0])&&(mask[i-1][j]==false)){
                mask[i-1][j]=true;
                if (search(board,i-1,j,str.substr(1),mask)){
                    return true;
                }
                mask[i-1][j]=false;
            }
            if ((i<board.size()-1)&&(board[i+1][j]==str[0])&&(mask[i+1][j]==false)){
                mask[i+1][j]=true;
                if (search(board,i+1,j,str.substr(1),mask)){
                    return true;
                }
                mask[i+1][j]=false;
            }
            if ((j>0)&&(board[i][j-1]==str[0])&&(mask[i][j-1]==false)){
                mask[i][j-1]=true;
                if (search(board,i,j-1,str.substr(1),mask)){
                    return true;
                }
                mask[i][j-1]=false;
            }
            if ((j<board[0].size()-1)&&(board[i][j+1]==str[0])&&(mask[i][j+1]==false)){
                mask[i][j+1]=true;
                if (search(board,i,j+1,str.substr(1),mask)){
                    return true;
                }
                mask[i][j+1]=false;
            }
        }
        return false;
    }
 
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (word.size()==0) {return false;}
             
        for (int i=0;i<board.size();i++){
            for (int j=0;j<board[0].size();j++){
                if (word[0]==board[i][j]){
                    if (word.size()==1) {return true;}
                    else{
                        vector<vector<bool> > mask(board.size(),vector<bool>(board[0].size(),false));
                        mask[i][j]=true;
                        if (search(board,i,j,word.substr(1),mask)){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
*/

bool search(int i,int j, vector<vector<char> > &board , string str, vector<vector<bool> > &mask)
{
	if(str.length() == 0){
		return true;
	}else{
		int r,c;
		for(int k=0;k<4;k++)
		{
			switch(k)
			{
				case 0:
					r = i - 1;
					c = j;
					break;
				case 1:
					r = i +1;
					c = j;
					break; 
				case 2:
					r = i;
					c = j + 1;
					break;
				case 3:
					r = i ;
					c = j - 1;
					break;
			}

			if(r >=0 && c >= 0 && r < board.size() && c < board[0].size())
			{
				if(str[0] == board[r][c])
				{	
					mask[r][c] = true;
					if(search(r,c,board,str.substr(1),mask)){
						return true;
					}
				}
			}
		}

		return false;
	}
}

bool exist(vector<vector<char> > &board,string word)
{
	if(word.length()==0){
		return true;
	}

	if(board.empty()){
		return false;
	}

	for(int i=0;i<board.size();i++)
	{
		for(int j=0;j<board[0].size();j++)
		{
			if(board[i][j] == word[0])
			{
				vector<vector<bool> > mask (board.size(), vector<bool> (board[0].size(),false) );
				mask[i][j] = true;
				if(search(i,j,board,word.substr(1),mask))
				{
					return true;
				}
			}
		}
	}

	return false;
}

int main()
{	
	clock_t start;
	double duration;
	start = clock();

	vector<vector<char> > b;
	vector<char> cv;

	vector<string> sv;
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	sv.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaab");

	for(int i=0;i<sv.size();i++)
	{
		string s = sv[i];
		const char * cp = s.c_str();	
		while(*cp!='\0')
		{	
			cv.push_back(*cp); 
			cp++;
		}
		b.push_back(cv);
		cv.clear();
	}
	
	cout << "["<<endl;

	for(int i=0;i<b.size();i++)
	{	
		cout<<"[";
		for(int j=0;j<b[i].size();j++){
			cout << b[i][j];
		}
		cout << "]" << endl;
	}
	cout << "]"<<endl;
	
	string t1 = "baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	bool ans = exist(b,t1);
	cout << "word " << t1 << " "<< ans << endl;
/*		
	string t2 = "SEE";
	ans = exist(b,t2);
	cout << "word " << t2 << " "<< ans << endl;

	string t3 = "ABCB";
	ans = exist(b,t3);
	cout << "word " << t3 << " "<< ans << endl; */

	duration = (clock()- start)/(double)CLOCKS_PER_SEC;
	cout << "time used " << duration << endl;
	return 0;
}