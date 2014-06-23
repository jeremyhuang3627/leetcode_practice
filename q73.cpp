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
#include <tr1/unordered_set>
#include <ctime>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
vector<int> postorderTraversal(TreeNode *root) {
 	stack<TreeNode *> s;
 	vector<int> v;
 	s.push(root);

 	while(!s.empty() && root != NULL){
 		TreeNode * n = s.top();
 		s.pop();
 		v.insert(v.begin(),n->val);
 		if(n->right != NULL){
 			s.push(n->right);
 		}

 		if(n->left != NULL){
 			s.push(n->left);
 		}
 	}

 	return v;
}*/

vector<int> postorderTraversal(TreeNode *root) {
    stack<TreeNode*> s;
    vector<int> vec;
    if(root == NULL)
        return vec;

    s.push(root);
    while(!s.empty())
    {
        TreeNode* n = s.top();
        if(n->right)
            s.push(n->right);
        if(n->left)
            s.push(n->left);
        n->left = NULL;
        n->right = NULL;

        n = s.top();
        if(n->left == NULL && n->right == NULL)
        {
            vec.push_back(n->val);
            s.pop();
        }
    }
    return vec;
}

int main(){
	TreeNode * r = new TreeNode(3);
	r->left = new TreeNode(1);
	r->left->left = new TreeNode(2);

	vector<int> ans = postorderTraversal(r);

	for(int i=0;i<ans.size();i++){
		cout << ans[i] << endl;
	}

	return 0;
}