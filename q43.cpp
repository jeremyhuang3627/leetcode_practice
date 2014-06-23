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
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode * buildBST(int buttom,int top,vector<int> &num)
{
	if(top >= buttom){
		int mid = (top + buttom)/2;
		TreeNode * node = new TreeNode(num[mid]);
		node->left = buildBST(buttom,mid-1,num);
		node->right = buildBST(mid+1,top,num);
		return node;
	}
	return NULL;
}

TreeNode * sortedArrayToBST(vector<int> &num)
{
	int mid,top,buttom;
	top = num.size()-1;
	buttom = 0;
	TreeNode * root = buildBST(buttom,top,num);
	return root;
}

void postOrder(TreeNode * root)
{
	if(root != NULL){
		postOrder(root->left);
		cout << root->val << " ";
		postOrder(root->right);
	}
}

int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	num.push_back(4);
	num.push_back(5);

	TreeNode * root = sortedArrayToBST(num);
	
	postOrder(root);

	return 0;
}