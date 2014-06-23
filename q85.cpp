//Path Sum II
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

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x),left(NULL),right(NULL){};
};

int total = 0;
vector<int> v;
vector<vector<int> > allVs;

void traverse(TreeNode *root,int sum)
{
	if(root != NULL){
		total += root->val;
		v.push_back(root->val);
		if(total == sum && root->left == NULL  && root->right == NULL){
			allVs.push_back(v);
		}
		traverse(root->left,sum);
		traverse(root->right,sum);
		v.pop_back();
		total -= root->val;
	}
}

vector<vector<int> > pathSum(TreeNode *root, int sum) {
    traverse(root,sum);
    return allVs;
}

int main(){



	return 0;
}