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

vector<int> preOrderV;
vector<int> postOrderV;
vector<int> inOrderV;

void preOrder(TreeNode *root)
{
	if(root != NULL){
		preOrderV.push_back(root->val);
		preOrder(root->left);
		preOrder(root->right);
	}else{
		preOrderV.push_back(-1);
	}
}

void postOrder(TreeNode *root)
{
	if(root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		postOrderV.push_back(root->val);
	}else{
		postOrderV.push_back(-1);
	}
}


void inOrder(TreeNode *root)
{
	if(root != NULL)
	{
		inOrder(root->left);
		inOrderV.push_back(root->val);
		inOrder(root->right);
	}else{
		inOrderV.push_back(-1);
	}
}

bool isSameTree(TreeNode *p,TreeNode *q)
{	
	preOrder(p);
	vector<int> pre1 = preOrderV;
	postOrder(p);
	vector<int> post1 = postOrderV;
	inOrder(p);
	vector<int> in1 = inOrderV;

	preOrderV.clear();
	postOrderV.clear();
	inOrderV.clear();

	preOrder(q);
	vector<int> pre2 = preOrderV;
	postOrder(q);
	vector<int> post2 = postOrderV;
	inOrder(q);
	vector<int> in2 = inOrderV;

	if(pre1.size() != pre2.size() || post1.size() != post2.size() || in1.size() != in2.size()){
		cout <<  "not same ! pre1.size() " << pre1.size() << " pre2.size() "<< pre2.size() <<endl;
		cout <<  "not same ! post1.size() " << post1.size() << " post2.size() "<< post2.size() <<endl;
		cout <<  "not same ! in1.size() " << in1.size() << " in2.size() "<< in2.size() <<endl;

		return false;
	}

	for(int i=0;i<pre1.size();i++){
		if(pre1[i] != pre2[i])
		{
			cout <<  "not same ! pre1[i]" << pre1[i] << " pre2[i] "<< pre2[i] <<endl; 
			return false;
		}
	}

	for(int i=0;i<post1.size();i++){
		if(post1[i] != post2[i])
		{
			cout <<  "not same ! post1[i]" << post1[i] << " post2[i] "<< post2[i] <<endl; 
			return false;
		}
	}

	for(int i=0;i<in1.size();i++){
		if(in1[i] != in2[i])
		{
			cout <<  "not same ! in1[i]" << in1[i] << " in2[i] "<< in2[i] <<endl; 
			return false;
		}
	}

	return true;
}

int main()
{
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(1);

	TreeNode *root2 = new TreeNode(1);
	root2->right = new TreeNode(1);

	int same = isSameTree(root,root2);
	cout << "is same : " << same << endl;

	return 0;
}
