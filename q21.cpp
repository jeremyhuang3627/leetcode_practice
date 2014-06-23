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

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

nt main()
{
	ListNode * root = new ListNode(2);
	root->next = new ListNode(5);
	root->next->next = new ListNode(5);
	root->next->next->next = new ListNode(4);
	root->next->next->next->next = new ListNode(-3);
	root->next->next->next->next->next = new ListNode(1);
	root->next->next->next->next->next->next = new ListNode(8);
	root->next->next->next->next->next->next->next = new ListNode(5);
	root->next->next->next->next->next->next->next->next = new ListNode(11);
	root->next->next->next->next->next->next->next->next->next = new ListNode(15); 

	cout << "before"<< endl;
	ListNode * p = root;
	while(p!=NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}

	cout << endl;
	root = sortList(root);

	cout << "after"<< endl;

	p = root;

	while(p!=NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}

	cout << endl;
//	root = sortList(root);
	return 0;
}