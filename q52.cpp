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
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

pair<TreeNode *,TreeNode *> preOrder(TreeNode * root)
{
	if(root != NULL)
	{
		pair<TreeNode *,TreeNode *> pl = preOrder(root->left);
		pair<TreeNode *,TreeNode *> pr = preOrder(root->right);
		if(pl.second != NULL || pl.first != NULL){
			pl.second->right = pr.first;
			root->right = pl.first;
		}else{
			root->right = pr.first;
		}

		if(pr.second != NULL){
			return make_pair(root,pr.second);
		}else{
			return make_pair(root,root);
		}
	}

	return make_pair(root,root);
}

void flatten(TreeNode * root)
{
	preOrder(root);
}

int main()
{	
	TreeNode * root = new TreeNode(1);
	root->left = new TreeNode();
	root->right = new TreeNode(2);
	flatten(root);
	TreeNode * cur = root;
	while(cur!=NULL)
	{
		cout<<cur->val<<endl;
		cur=cur->right;
	}

	return 0;
}