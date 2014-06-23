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

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

vector<vector<TreeLinkNode *> > n;
map<TreeLinkNode *,int> l;

void connect(TreeLinkNode * root)
{
	if(root != NULL){
		vector<TreeLinkNode *> v;
		v.push_back(root);
		n.push_back(v);
		l[root] = 0;

		queue<TreeLinkNode *> q;
		q.push(root);

		while(!q.empty())
		{
			TreeLinkNode * node = q.front();
		//	cout <<"node val " <<node->val << endl;
			q.pop();
			int level = l[node];
			if(node->left != NULL && l[node->left] == 0){

				vector<TreeLinkNode *> k;
				k.push_back(node->left);
			//	cout << "left node " << node->left->val<<endl;
				if(n.size()-1 < level + 1){
					n.push_back(k);
				}else{
					n[level+1].push_back(node->left);
				}
				l[node->left] = level + 1;
				q.push(node->left);
			}

			if(node->right != NULL && l[node->right] == 0)
			{
				vector<TreeLinkNode *> k;
				k.push_back(node->right);
			//	cout << "right node " << node->right->val<<endl;
				if(n.size()-1 < level + 1){
					n.push_back(k);
				}else{
					n[level+1].push_back(node->right);
				}
				l[node->right] = level + 1;
				q.push(node->right);
			
			}

		}

	//	cout << "n size " << n.size()<< endl;
		
		for(int i=0;i<n.size();i++)
		{
			
			cout << "level " << i << " ";
			v = n[i];
			TreeLinkNode * prev;
			TreeLinkNode * cur;
			if(v.size() > 1){
				for(int j=1;j<v.size();j++)
				{
					cur = v[j];
					prev = v[j-1];
					cout << cur->val << " ";
					prev->next = cur;
				}
				cout << endl;
			}else{
				root->next = NULL;
			}
		}
	}
}


int main(){
	TreeLinkNode * root = new TreeLinkNode(0);

/*	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	root->left->left = new TreeLinkNode(4);

	root->left->right = new TreeLinkNode(5);
	root->right->left = new TreeLinkNode(6);
	root->right->right = new TreeLinkNode(7); */
	//TreeLinkNode * root;
	connect(root);
	return 0;
}

