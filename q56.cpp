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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode * deleteDuplicates(ListNode * head)
{	
	if(head != NULL){
		ListNode * cur1;
		ListNode * cur2 = NULL;
		bool f = false;
		cur1 = head;
		while(cur1->next != NULL)
		{
			if(!f){
				if(cur1->val == cur1->next->val)
				{
					f = true;
				}else{
					cur2 = cur1;
				}
				cur1 = cur1->next;
			}else{
				if(cur1->val != cur1->next->val)
				{
					if(cur2 != NULL)
					{
						cur2->next = cur1->next;
						cur1 = cur2->next;
					}else{
						head = cur1->next;
						cur1 = head;
					}
					f = false;
				}else{
					cur1 = cur1->next;
				}
			}
		}

		if(f)
		{
			if(cur2 != NULL )
			{
				cur2->next = cur1->next;
				cur1 = cur2->next;
			}else{
				head = cur1->next;
				cur1 = head;
			}
		}
	}
	return head;
}


int main()
{
	ListNode * root = new ListNode(1);
	root->next = new ListNode(2);
	root->next->next = new ListNode(2);
	root->next->next->next = new ListNode(3);
	root->next->next->next->next = new ListNode(4);
	root->next->next->next->next->next = new ListNode(4);
	root->next->next->next->next->next->next = new ListNode(5);  

	root = deleteDuplicates(root);

	ListNode * cur = root;
	while(cur!= NULL)
	{
		cout << cur->val << endl;
		cur = cur->next;
	}
	return 0;
}