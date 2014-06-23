// Given a linked list, determine if it has a cycle in it.
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

bool hasCycle(ListNode *head) {
      ListNode * fast = head;
      ListNode * slow = head;

      while(fast != NULL && fast->next != NULL){
      	fast= fast->next->next; 
      	slow = slow->next;
      	if (fast == slow)
      	{
      		return true;
      	}
      }

      return false;
}

int main()
{
	ListNode * list = new ListNode(1);
	list->next = new ListNode(2);
	list->next->next = new ListNode(3);
	list->next->next->next = new ListNode(4);
	list->next->next->next->next = new ListNode(5);
	//list->next->next->next->next = list->next; // 4 points to 2
	cout << "has cycle " << hasCycle(list)<<endl;
	return 0;
}