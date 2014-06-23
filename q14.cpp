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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> *v = new vector<int>();

void preorder(TreeNode * root){
	if(root != NULL){
		preorder(root->left);
		(*v).push_back(root->val);
		preorder(root->right);
	}
}

vector<int> preorderTraversal(TreeNode * root){
	preorder(root);
	return (*v);
}

int main(){
	TreeNode * root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);

	vector<int> ans = preorderTraversal(root);

	for(int i=0;i<ans.size();i++){
		cout << ans[i]<<endl;
	}

	return 0;
}
