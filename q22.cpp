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

ListNode * reverse(ListNode * head)
{
	ListNode * temp;
	temp = head;
	head = head->next;
	temp->next = NULL;
	ListNode *cur = head;
	while(cur != NULL)
	{
		head = head->next;
		cur->next = temp;
		temp = cur;
		cur = head;
	}
	return temp;
}

ListNode * insertionSortList(ListNode * head){
	ListNode * sorted = head;
	if(head != NULL){
		head = head->next;
		sorted->next = NULL;
		ListNode * cur = head;
		while(cur != NULL)
		{
			int val = cur->val;
			ListNode * cur2 = sorted;
			head= head->next;
			if(val >= cur2->val){
				cur->next = sorted;
				sorted = cur;
				
			}else{
				while(cur2->next != NULL && cur2->next->val > val)
				{
					cur2 = cur2->next;
				}

				cur->next = cur2->next;
				cur2->next = cur;
			}
			cur = head;
		}
		return reverse(sorted);
	}else{
		return head;
	}
}

int main()
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
	root = insertionSortList(root);

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