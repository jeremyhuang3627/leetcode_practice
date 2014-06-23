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

struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x): val(x),left(NULL),right(NULL){}
};	

int vecToInt(vector<int> &v)
{
	int sum = 0;
	for(int i=0;i<v.size();i++)
	{
		sum += v[i] * (int)pow(10.0,(double)v.size()-1-i);
	}
	return sum;
}

vector<int> v;
int sum;

void DFS(TreeNode * root)
{
	if(root!=NULL)
	{
		if(root->left == NULL && root->right == NULL)
		{	
			// this must be leaf
			v.push_back(root->val);
			sum += vecToInt(v);
			v.pop_back();
		}else{
			v.push_back(root->val);
			DFS(root->left);
			v.pop_back();

			v.push_back(root->val);
			DFS(root->right);
			v.pop_back();
		}
	}
}

int sumNumbers(TreeNode * root)
{
	sum = 0;
	DFS(root);
	return sum;
}

int main()
{
	TreeNode * root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);

	int ans = sumNumbers(root);
	cout << "ans " <<ans <<endl;
	return 0;
}