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

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode *deleteDuplicates(ListNode *head)
{
	if(head != NULL){
		ListNode * prev = head;
		ListNode * cur = head->next;

		while(cur != NULL){
			if(prev->val == cur->val)
			{
				prev->next = prev->next->next;
				cur = prev->next;
			}else{
				prev = prev->next;
				cur = prev->next;
			}
		}
	}

	return head;
}

int main()
{


 	ListNode * root = new ListNode(1);
 	root->next = new ListNode(1);
 	root->next->next = new ListNode(2);
 	root->next->next->next = new ListNode(3);
 	root->next->next->next->next = new ListNode(3);

 	cout << "before" << endl;

 	ListNode * p = NULL;
 	p=root;
 	while(p!= NULL){
 		cout << p->val << " ";
 		p = p->next;
 	}

 	cout << "after" << endl;

    p = deleteDuplicates(root);
 	while(p!=NULL)
 	{
 		cout << p->val << " ";
 		p = p->next;
 	}

 	cout<<endl;
 	return 0;
 }