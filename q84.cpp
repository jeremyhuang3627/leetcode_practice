//Path Sum
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
bool equalPathSum = false;

void traverse(TreeNode *root,int sum)
{
	if(root != NULL){
		total += root->val;
		if(total == sum && root->left == NULL  && root->right == NULL){
			equalPathSum = true;
		}
		traverse(root->left,sum);
		traverse(root->right,sum);
		total -= root->val;
	}
}

bool hasPathSum(TreeNode *root, int sum) {
	traverse(root,sum);
	return equalPathSum;
}

int main(){



	return 0;
}

