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
	struct entry{
		int _k;
		int _v;
		int _u;
		entry(int k,int v) : _k(k),_v(v),_u(0){}
	};

	struct ListNode{
		entry * _e;
		ListNode * next;
		ListNode * prev;
		ListNode(entry * e) : _e(e),next(NULL),prev(NULL){}
	};

	tr1::unordered_map<int,ListNode *> m;
	ListNode * qh ;
	ListNode * qt ;

	int _capacity;

	public:
	    LRUCache(int capacity) {
	       _capacity = capacity;
	       qh= NULL;
	       qt= NULL;
	    }
	    
	    int get(int key) {
	    	cout << "getting " << key << endl;
	    	if(m.find(key) == m.end())
	    	{
	    		return -1;
	    	}

	    	if(m[key]->prev !=NULL)
	    	{
	    		if(qt == m[key])
	    		{
	    			qt = qt->prev;
	    		}
	    		m[key]->prev->next = m[key]->next;
	    	}

	    	if(m[key]->next != NULL && m[key] != qh)
	    	{
	    		m[key]->next->prev = m[key]->prev;
	    	}

	    	if(qh != m[key]){
	    		qh->prev = m[key];
	    		m[key]->next = qh;
	    		qh = m[key];
	    	}
	    	return qh->_e->_v;
	    }

	    void set(int key, int value) {
	    	cout << "setting " << key << " with value " << value << endl;
	    	if(m.size() == _capacity && m.find(key) == m.end())
	    	{
	    		entry * e = qt->_e;
	    		
	    		qt = qt->prev;
	    		
	    		if(qt!=NULL){
	    			qt->next = NULL;
	    		}
	    		
	    		tr1::unordered_map<int,ListNode *>::iterator it;
	    		int key = e->_k;
	    		
	    		it = m.find(key);
	    		m.erase(it);
	    	}
	  
	    	entry * ne = new entry(key,value);
	    	ListNode * n = new ListNode(ne);
	    	
	    	m[key] = n;
	    	
	    	if(qh!=NULL){
	    	 qh->prev = n;

	   	 	}	
	    	n->next = qh;
	    	
	    	qh = n;
	    	if(qt == NULL)
	    	{
	    		qt = qh;
	    	}
	    }
};


int main()
{
	LRUCache testClass (2);
	cout<<"setting " <<endl;
	testClass.set(2,1);
	testClass.set(3,2);
	cout << testClass.get(3) <<endl;
	cout << testClass.get(2) <<endl;
	testClass.set(4,3);
	cout << testClass.get(2) <<endl;
	cout << testClass.get(3) <<endl;
	cout << testClass.get(4) <<endl;
	testClass.set(5,78);
	testClass.set(6,66);
	testClass.set(7,12);
	testClass.set(8,0);
	cout << testClass.get(8) <<endl;
	cout << testClass.get(7) <<endl;
	cout << testClass.get(9) <<endl;
	return 0;
}




