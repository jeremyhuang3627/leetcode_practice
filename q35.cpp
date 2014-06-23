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

string fillSpace(string s,int l)
{
	int numspaces = l - s.length();
	for(int i=0;i<numspaces;i++)
	{
		s+=" ";
	}
	return s;
}


vector<string> fullJustify(vector<string> &v,int l)
{	

	int c = 0;
	int curi = 0;
	int nexi = curi+1;
	int nc,minLen;
	bool last = false;
	vector<string> ret;
	cout << "t1" <<endl;
	if(v.size()>0){
		string line = "";
		if(v.size() > 1){
			while(!last){
				vector<string> nv;
				cout << "t2" <<endl;
				do{
					cout << "curi "<< curi <<endl;
					c += v[curi].length();
					nv.push_back(v[curi]);
					if(nexi>=v.size()){
						last = true;
						break;
					}
					nc = c + v[nexi].length();
					minLen = nc + nv.size();
					curi++;
					nexi = curi+1;
					
				}while(minLen<=l);

				cout << "t3" <<endl;
				int nspaces = l - c;	
				if(!last){
					if(nv.size()>1){
						int nslots = nv.size()-1;
						vector<string> sv (nslots);
						for(int k=0;k<nspaces;k++)
						{
							int index = k%nslots;
							sv[index] += " ";
						}
						cout << "t4" <<endl;
						for(int k=0;k<nv.size();k++)
						{
							if(k != nv.size()-1)
							{
								line += nv[k] + sv[k];
							}else{	
								line += nv[k];
							}
						}
						ret.push_back(line);
						line = "";
					}else if(nv.size() ==1){
						line = fillSpace(nv[0],l);
						ret.push_back(line);
						line = "";
					}
				}else{
					cout << "t5" <<endl;
					for(int k=0;k<nv.size();k++)
					{
						if(k!=nv.size()-1){
							line += nv[k] + " ";
						}else{
							line += nv[k];
						}
					}

					line = fillSpace(line,l);
					ret.push_back(line);
					line="";
				}
				cout << "t6" <<endl;
				nv.clear();
				c = 0;
			}
			return ret;
		}else{
			line = fillSpace(v[0],l);
			ret.push_back(line);
			return ret;
		}
	}else{
		return ret;
	}
}

int main()
{
	vector<string> v;
	v.push_back("What");
	v.push_back("must");
	v.push_back("be");
	v.push_back("shall");
	v.push_back("be.");
	int l = 12;
	vector<string> ans = fullJustify(v,l);

	for(int i=0;i<ans.size();i++)
	{
		cout << ans[i] << ","<<endl;
	}
	return 0;
}