#include <iostream>
#include <cstdio>
#include <cstring>
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
	ListNode(int x):val(x),next(NULL){}
};

ListNode *rotateRight(ListNode *head,int k)
{
	int num = 0;
	ListNode * cur = head;
	ListNode * cur2 = NULL;
	if(head != NULL){
		while(cur!= NULL){
			cur=cur->next;
			num++;
		}

		if(num == 1 || k==0 ){
			return head;
		}

		k = k % num;

		cur = head;
		int c = 0;
		while(cur->next != NULL){
			cur = cur->next;
			c++;
			if(c==k){
				cur2 = head;
			}else if(c > k){
				cur2 = cur2->next;
			}
		}

		cur->next = head;
		head = cur2->next;
		cur2->next = NULL;
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

	root = rotateRight(root,2);

	ListNode * cur = root;
	while(cur != NULL){
		cout << cur->val << " ";
		cur = cur->next;
	}

	return 0;
}