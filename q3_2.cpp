/* Sort a linked list in O(n log n) time using constant space complexity. */
#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <stdlib.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

pair<ListNode *,ListNode *> addNode(pair<ListNode *,ListNode *> node,ListNode * newNode)
{	
	if(node.first == NULL || node.second == NULL)
	{
		node.first = newNode;
		node.second = newNode;
		return node;
	}

	newNode->next = node.first;
	node.first = newNode;
	return node; 
}	

pair<ListNode *,ListNode *> quickSort(pair<ListNode *, ListNode*> list)
{
	if(list.first != NULL){
		ListNode * pivot = list.first;
		ListNode * cur = list.first;

		pair<ListNode *,ListNode *> large;
		large.first = NULL;
		large.second = NULL;

		pair<ListNode *,ListNode *> small;
		small.first = NULL;
		small.second = NULL;

		while(cur->next != NULL){
			cur->next = cur->next->next;
			cout << cur->next <<endl;
			if(cur->next->val <= pivot->val){
				small = addNode(small,cur->next);
			}else{
				large = addNode(large,cur->next);
			}
		}

		large = addNode(large,cur);
		small = quickSort(small);
		large = quickSort(large);
		small.second->next = large.first;
		return small;
	}
	return list;
}

ListNode *sortList(ListNode *head){
	pair<ListNode *,ListNode *> list;
	list.first = head;
	while(head->next != NULL)
	{
		head = head->next;
	}
	list.second = head;
	list = quickSort(list);
	return list.first;
}


int main(){
 	ListNode *head = new ListNode(11);
 	ListNode *temp = head;
 	for(int i=10;i>=0;i--)
 	{
 		(*temp).next = new ListNode(i);
 		temp = (*temp).next;
 	}

 	cout << "before sort" << endl;
 	temp = head;
 	while(temp != NULL)
 	{
 		cout << (*temp).val << endl;
 		temp = (*temp).next;
 	}

 	ListNode *newNode = sortList(head);

 	cout <<"after sort " << endl;

 	temp = newNode;
 	while(temp != NULL)
 	{
 		cout << (*temp).val << endl;
 		temp = (*temp).next;
 	}  

 	return 0;
 };