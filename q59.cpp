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

class LRUCache{
	
	struct cmp{
		bool operator()(pair<int,int> p1,pair<int,int> p2){
			return p1.second < p2.second;
		}
	};

	struct ListNode{
		int key;
		ListNode * next;
		ListNode * prev;
		ListNode(int k):key(k),next(NULL),prev(NULL){}
	};

	int _c;
	ListNode * rootTop;
	ListNode * rootBut;
	map<int,pair<ListNode *,int> > m;

	public:
		LRUCache(int capacity){
			_c = capacity;
			rootTop = NULL;
			rootBut = NULL;
		}

		int get(int key){
			if(m.count(key)>0){
				ListNode * n = m[key].first;
				if(n!=rootTop){

					if(n==rootBut)
					{
						rootBut= n->prev;
					}

					if(n->prev != NULL)
					{
						n->prev->next = n->next;
					}

					if(n->next != NULL)
					{
						n->next->prev = n->prev;
					}

					n->next = rootTop;
					if(rootTop){
						rootTop->prev = n;
					}
					rootTop = n;
				}
				return m[key].second;
			}

			return -1;
		}

		void set(int key,int value)
		{
			if(m.count(key) != 0){
				get(key);
				m[key].second = value;
				return;
			}

			if(m.size()==_c)  // full
			{
				cout << "full " << endl;
				if(rootBut){// remove last one;
					cout<<"t1"<< endl;
					int keyToRemove = rootBut->key;
					cout<< "t2"<<endl;
					rootBut = rootBut->prev;
					if(rootBut){
						rootBut->next = NULL;
					}
					cout << "removing key " << keyToRemove << endl;
					m.erase(keyToRemove);
				}else{
					cout << "rootBut is null " << endl;
					return;
				} 
			}

			ListNode * node = new ListNode(key);
			node->next = rootTop;
			if(rootTop!= NULL)
			{
				rootTop->prev = node;
			}

			if(rootTop == NULL || rootBut == NULL)
			{
				rootTop = rootBut = node;
			}
			rootTop = node;
			m[key] = make_pair(node,value);
			return;
		}	

};

int main()
{
	LRUCache c (1);
	cout << "set(2,1) " << endl;
	c.set(2,1);

//	cout << "get(1) " << c.get(1) << endl;
	cout << "get(2) " << c.get(2) << endl;
	cout << "set(3,2) " << endl;
	c.set(3,2);
	cout << "get(2) " << c.get(2) << endl;
	cout << "get(3) " << c.get(3) << endl;

	return 0;
}