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
#include <sstream> 

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode * root)
{
	ListNode * cur = root;
	ListNode * th = NULL;
	ListNode * tt = NULL;
	vector<ListNode *> v;
	while(cur!= NULL)
	{	
		v.push_back(cur);
		cur = cur->next;
	}
	int mid;
	bool even;
	if(v.size()%2 == 1){
		mid = v.size()/2 + 1;
		even = false;
	}else{
		mid = v.size()/2;
		even = true;
	}

	for(int i=0;i<mid;i++)
	{
		v[i]->next = NULL;
		if(th == NULL && tt == NULL)
		{
			th = tt = v[i];
		}else{
			tt->next = v[i];
			tt = v[i];
		}

		if(even){
			v[v.size()-i-1]->next = NULL;
			tt->next = v[v.size()-i-1];
			tt = v[v.size()-i-1];
		}else{
			if(i<mid-1){
				v[v.size()-i-1]->next = NULL;
				tt->next = v[v.size()-i-1];
				tt = v[v.size()-i-1];
			}
		}
	}
}


int main()
{	
	ListNode * root = new ListNode(1);
	root->next = new ListNode(2);
	root->next->next = new ListNode(3);
	root->next->next->next = new ListNode(4);

	reorderList(root);

	cout << "after reordering " << endl;
	ListNode * p = root;
	while(p!=NULL)
	{
		cout << p->val << " ";
		p=p->next;
	}
	cout << endl;

	return 0;
}