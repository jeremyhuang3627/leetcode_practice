#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <stdlib.h>
#include <tr1/unordered_set>
#include <queue>
#include <set>
#include <map>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL),right(NULL){}
};

int maxDepth(TreeNode *root)
{	
	if(root == NULL){
		return 0;
	}

	int rightMax = maxDepth(root->right);
	int leftMax = maxDepth(root->left);
	if(rightMax >leftMax)
	{
		return rightMax + 1;
	}
	
	return leftMax + 1;
}

int main()
{
	TreeNode *root = new TreeNode(0);
	root->right = new TreeNode(0);
	root->left = new TreeNode(3);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(5);

	int depth = maxDepth(root);
	cout<<"max depth is " << depth <<endl;
	return 0;
}