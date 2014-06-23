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

int s = 0;

void printList(ListNode * head,string space)
{
	ListNode * p = head;
	cout << space << "res ";
	while(p!= NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

pair<ListNode *,ListNode *> quickSort(ListNode * head)
{
	s++;
	pair<ListNode *,ListNode *> equal (head,head);
	pair<ListNode *,ListNode *> large ;
	pair<ListNode *,ListNode *> small ;
	
	string space = "";
	for(int i=0;i<s;i++)
	{
		space += "    ";
	}

	

	if(head != NULL){
		ListNode * cur = head->next;
		int pval = head->val;
		cout << space <<"pivot " << pval << endl;
		while(cur!=NULL)
		{
			cout<< space <<cur->val <<endl;
			
			if(cur->val > pval){
				cout << space << "pushing " << cur->val << " to large " <<endl;
				equal.second->next = cur->next;
				if(large.first == NULL){
					large.first = large.second = cur;
				}else{
					large.second->next = cur;
					large.second = cur;
				}
			}else if(cur->val < pval)
			{
				cout << space << "pushing " << cur->val << " to small " <<endl;
				equal.second->next = cur->next;
				if(small.first == NULL){
				//	cout << space << "initializing small " << endl;
					small.first = small.second = cur;
				}else{
				//	cout << space << " appending to small " << endl;
					small.second->next = cur;
					small.second = cur;

				}
			}else{
				equal.second = cur;
			}
			cout << space << "equal.first"<<endl;
			cout << space << equal.first<<endl;
			cout << space << "equal.first->next"<<endl;
			cout << space << equal.first->next<<endl;
			cout << space << "equal.second"<<endl;
			cout << space << equal.second<<endl;
			cout << space << "equal.second->next"<<endl;
			cout << space << equal.second->next<<endl;

			cur = cur->next;
		}

		cout<< space <<"equal"<<endl;
		printList(equal.first,space);
		cout<< space <<"equal.second"<<endl;
		cout<< space <<equal.second<<endl;
		cout<< space <<"equal.first->next"<<endl;
		cout<< space <<equal.first->next<<endl;
		if(equal.first->next != NULL){
			cout<< space <<"equal.first->next->val"<<endl;
			cout<< space <<equal.first->next->val<<endl;
		}

		if(small.second != NULL){small.second->next = NULL;}
		if(large.second != NULL){large.second->next = NULL;}
		if(equal.second != NULL){equal.second->next = NULL;}

		cout<< space <<"sort small"<<endl;
		small = quickSort(small.first);
		cout<< space <<"print small"<<endl; 
		printList(small.first, space);
		cout<< space <<"sort large"<<endl;
		large = quickSort(large.first);
		cout<< space <<"print large"<<endl;
		printList(large.first, space);
		pair<ListNode *,ListNode *> res;
		if(small.first != NULL){
		    small.second->next = equal.first;
		}else{
			cout<< space <<"small.first = equal.first"<<endl;
			small.first = equal.first;
		}
		res.first = small.first;
		cout<< space <<"appending small to res"<<endl;
		cout<< space <<"res.first " << res.first->val<<endl;

		if(res.first->next != NULL){
			cout<< space <<"res.first->next " << res.first->next->val<<endl;
		}

		if(large.first != NULL){
			equal.second->next = large.first;
			cout<< space <<"appending large to equal"<<endl;
			cout<< space <<"large first val " << large.first->val<<endl;
			cout<< space <<"large second val " << large.second->val<<endl;
			res.second = large.second;
			cout<< space <<"res second val " << res.second->val<<endl;
		}else{
			res.second = equal.second;
		}
		printList(res.first, space);
		s--;
		return res;
	}else{
		s--;
		return equal;
	}
}

ListNode * sortList(ListNode * head)
{

	pair<ListNode *,ListNode *> ans = quickSort(head);

	return ans.first;
}

int main()
{
	ListNode * root = new ListNode(2);
	root->next = new ListNode(5);
	root->next->next = new ListNode(5);
	root->next->next->next = new ListNode(4);
/*	root->next->next->next->next = new ListNode(-3);
	root->next->next->next->next->next = new ListNode(1);
	root->next->next->next->next->next->next = new ListNode(8);
	root->next->next->next->next->next->next->next = new ListNode(5);
	root->next->next->next->next->next->next->next->next = new ListNode(11);
	root->next->next->next->next->next->next->next->next->next = new ListNode(15); */

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

