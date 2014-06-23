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
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode * detectCycle(ListNode *head)
{
	ListNode *p1;
	ListNode *p2;
	ListNode *p3;

	p1 = p2 = head;

	if(p1!=NULL){
		while(p1!=NULL && p1->next!=NULL){
			p1= p1->next->next;
			p2 = p2->next;

			if(p2==p1){
				// there is cycle
				p3 = head;
				while(p3!=NULL){
					if(p2==p3){
						return p3;
					}
					p3 = p3->next;
					p2 = p2->next;
				}
			}
		}
	}

	return NULL;
}

int main()
{
	ListNode * root = new ListNode(1);
	ListNode * node2 = root->next = new ListNode(2);
/*	root->next->next = new ListNode(3);
	root->next->next->next = new ListNode(4);
	root->next->next->next->next = node2; */

	ListNode * startNode = detectCycle(root);
	if(startNode!=NULL){
		cout << "start node is " << startNode->val <<endl;
	}else{
		cout << "there is no cycle" <<endl;
	}

	return 0;
}