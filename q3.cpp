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


pair<ListNode *,ListNode *> appendList(pair<ListNode *,ListNode *> list1, pair<ListNode *,ListNode *> list2)
{
	(*list1.second).next = list2.first;
	return list1;
}

pair<ListNode *,ListNode *> addANode(pair<ListNode *, ListNode *> node,ListNode *newNode)
{
	if(node.first == NULL || node.second == NULL){
		node.first = newNode;
		node.second = newNode;
		return node;
	}

	(*newNode).next = node.first;
	node.first = newNode;
	return node;
}

pair<ListNode *,ListNode *> quickSort(pair<ListNode *,ListNode *> list)
{
	if(list.first != NULL){
		pair<ListNode *,ListNode *> pivot;
		pivot.first = NULL;
		pivot.second = NULL;

	 	pair<ListNode *,ListNode *> small;
	 	small.first = NULL;
	 	small.second = NULL;

	 	pair<ListNode *,ListNode *> large;
	 	large.first=NULL;
	 	large.second=NULL;

	 	ListNode * temp;
	 	cout << "test 1" << endl;
		while( (*list.first).next != list.second)
		{	
			temp = (*list.first).next;
			cout << (*temp).val << endl;
			(*list.first).next = (*temp).next;
	 		if((*temp).val < (*list.first).val){
	 			small = addANode(small,temp);
	 		}else if((*temp).val > (*list.first).val){
	 			large = addANode(large,temp);
	 		}else{	
	 			pivot = addANode(pivot,temp);
	 		}
		}

		if((*list.second).val < (*list.first).val){
	 			small = addANode(small,list.second);
	 	}else if((*list.second).val > (*list.first).val){
	 			large = addANode(large,list.second);
	 	}else{	
	 			pivot = addANode(pivot,list.second);
	 	}
		
		pivot = addANode(pivot,list.first);
		cout << "calling small"<< endl;
		small = quickSort(small);
		cout << "calling large"<<endl;
		large = quickSort(large);
		cout << "test 2" << endl;
		small = appendList(small,pivot);
		small = appendList(small,large);
		return small;
	}
	return list;
}


ListNode *sortList(ListNode *head){
 	pair<ListNode *,ListNode *> list;
 	list.first = head;
 	while((*head).next != NULL)
 	{
 		head = (*head).next;
 	}
 	list.second = head;
 	list = quickSort(list);

 	return list.first;
 };

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

