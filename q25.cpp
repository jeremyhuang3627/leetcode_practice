#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <stdlib.h>
#include <tr1/unordered_set>
#include <tr1/unordered_map>
#include <queue>
#include <set>
#include <map>
#include <sstream> 

using namespace std;

class LRUCache{
	struct ListNode
	{
		int _k;
		int _v;
		ListNode * prev;
		ListNode * next;
		ListNode(int k,int v) :  _k(k),_v(v){}
	};

	int _capacity;
	tr1::unordered_map<int,ListNode *> m;
	ListNode * h;
	ListNode * t;
	public:
		LRUCache(int capacity)
		{
			_capacity = capacity;
			h = t = NULL;
		}

		int get(int key)
		{
		//	cout  << "getting " << key << " ";
			if(m.find(key) == m.end())
			{
				return -1;
			}

			ListNode * n = m[key];
		//	cout << "n->prev " << n->prev << " n->next " << n->next <<endl;
			if(n->prev != NULL && n->next != NULL)
			{
				n->prev->next = n->next;
				n->next->prev = n->prev;

				n->next = h;
				if(h!=NULL)
				{
					h->prev = n;
				}
				h = n;
			}else if(n->prev != NULL && n->next == NULL)
			{
				if(t!=NULL){
					t=t->prev;
				}
				n->prev->next = n->next;
				n->prev = NULL;
				n->next = h;
				if(h!=NULL)
				{
					h->prev = n;
				}
				h = n;
			}
			return n->_v;
		}

		void set(int key,int value)
		{
			if(m.size() == _capacity && m.find(key) == m.end())
			{

				int k = t->_k;
		//		cout << "poping " << k << " with " << t->_v <<endl;
				t = t->prev;
				if(t!=NULL)
				{
					t->next = NULL;
				}
				tr1::unordered_map<int,ListNode *>::iterator it;
				it = m.find(k);
				m.erase(it);
			}

			ListNode * n = new ListNode(key,value);
			n->next = h;
			if(h!=NULL)
			{
				h->prev = n;
			}

			h = n;

			if(t == NULL)
			{
				t = n;
			}
		//	cout << "setting " << key <<" with " << n->_v <<endl;
			m[key] = n;
		}
};

int main()
{
	LRUCache testClass (1);
	cout<<"setting " <<endl;
	testClass.set(2,1);
	cout << testClass.get(2) <<endl;
	return 0;
}
