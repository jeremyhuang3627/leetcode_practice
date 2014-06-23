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

struct ListNode{
	int val;
	ListNode * next;
	ListNode(int x) : val(x),next(NULL){}
};

pair<ListNode *,ListNode *> reverse(ListNode * root){
	ListNode * nodeTop = NULL;
	ListNode * nodeBut = NULL;
	ListNode * cur = root;
	ListNode * temp;
	while(cur!=NULL){
		temp = cur;
		cur = cur->next;
		if(nodeTop == NULL || nodeBut == NULL)
		{
			nodeTop = nodeBut = temp;
			temp->next = NULL;
		}else{
			temp->next = nodeTop;
			nodeTop = temp;
		}
	}

	return make_pair(nodeTop,nodeBut);
}

ListNode * reverseGroup(ListNode * root, int k)
{
	vector<pair<ListNode *,ListNode *> > v;
	int count = 0;
	ListNode * cur = root;
	ListNode * top = root;
	pair<ListNode *,ListNode *> p;
	while(cur!=NULL)
	{	
		count ++;
		if(count%k==0)
		{
			root = cur->next;
			cur->next = NULL;
			p = reverse(top);
			v.push_back(p);
			top = cur = root;
		}else{
			cur = cur->next;
		}
	}

	if(count>0 && count >= k){
		for(int i=0;i<v.size()-1;i++)
		{
			v[i].second->next = v[i+1].first;
		}
		
		v[v.size()-1].second->next = root;
		root = v[0].first;
	}

	return root;
}

int main()
{
	ListNode * root = new ListNode(1);
/*	root->next = new ListNode(2);
	root->next->next = new ListNode(3);
	root->next->next->next = new ListNode(4);
	root->next->next->next->next = new ListNode(5); */
	int k = 2;

	//pair<ListNode *,ListNode *> p = reverse(root);
	root = reverseGroup(root,k);

	ListNode * cur =root;
	while(cur!=NULL)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout<<endl;

	return 0;
}