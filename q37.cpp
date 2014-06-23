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

struct TreeNode{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x) : val(x),left(NULL),right(NULL) {}
};

int maxPath;

int findMax(TreeNode * root){
	if(root!=NULL){
		int rightMax = max(findMax(root->right),0);
		int leftMax = max(findMax(root->left),0);
		maxPath = max(root->val + rightMax + leftMax, maxPath);
		return root->val + max(rightMax,leftMax);
	}
	return 0;
}


int maxPathSum(TreeNode * root)
{
	maxPath = (root == NULL) ? 0 : root->val;
	findMax(root);
	return maxPath;
}


int main()
{	
	clock_t start;
	double duration;
	start = clock();
	TreeNode * root = new TreeNode(-3);
/*	root->left = new TreeNode(2);
	root->right = new TreeNode(3); */

	int ans = maxPathSum(root);
	cout << "ans " << ans << endl;

	duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	cout << "time used " << duration << endl;
	return 0;
}