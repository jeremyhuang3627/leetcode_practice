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

struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x):val(x),next(NULL){}
};

ListNode * removeNthFromEnd(ListNode *head, int n)
{
	//cout << "t1" << endl;
	ListNode * cur;
	ListNode * cur2 = cur = head;
	if(head != NULL){
		int c = 0;
		//cout << "t2" << endl;
		while(cur->next !=NULL && cur2->next != NULL)
		{	
			c++;
			if(c>=n+1)
			{
				cur2 = cur2->next;
			}
			cur=cur->next;
		}
		c++;
		//cout << "t3" << endl;
		if(cur2 == head && c == n)
		{
			head = head->next;
			return head;
		}

		//cout << "t4" << endl;
		if(cur2 != NULL && cur2->next != NULL){
			//cout << "cur2 val " << cur2->val << endl;
			cur2->next = cur2->next->next;
		}
	}
	return head;
}

int main()
{
	ListNode * root = new ListNode(1);
	root->next = new ListNode(2);
	root->next->next = new ListNode(3);
	root->next->next->next = new ListNode(4);
	root->next->next->next->next = new ListNode(5);

	int n = 5;
	root = removeNthFromEnd(root,n);
	ListNode * cur = root;

	while(cur != NULL)
	{
		cout << cur->val << "->";
		cur=cur->next;
	}
	cout << endl;
	return 0;
}
