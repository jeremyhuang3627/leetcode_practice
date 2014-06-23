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


struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
	 	if(head == NULL) return NULL;
	    vector<RandomListNode *> v_original;
	    vector<RandomListNode *> v_new;
	    map<RandomListNode *,int> m;

	    RandomListNode * curr = head;
	    RandomListNode * n;
	    RandomListNode * r;
	    int index = 0;
	    while(curr){	
	    	v_original.push_back(curr);
	    	m[curr] = index;
	    	index ++;
	    	n = new RandomListNode(curr->label);
	    	v_new.push_back(n);
	    	curr = curr->next;
	    }

	    for(int i=0;i<v_original.size();i++){
	    	if(i<v_original.size()-1){
	    		v_new[i]->next = v_new[i+1];
	    	}
	    	
	    	if(v_original[i]->random){
		    	r = v_original[i]->random;
		    	index = m[r];
		    	v_new[i]->random = v_new[index];
		    }
	    }

	    return v_new[0];
}

int main(){
	RandomListNode * r = new RandomListNode(1);
	r->next = new RandomListNode(2);
	r->next->next = new RandomListNode(3);
	r->random = r->next;
	r->next->random = r;  

	RandomListNode * curr = copyRandomList(r);

	while(curr){
		cout << "node is " << curr->label;
		if(curr->random)
			cout << " random is " << curr->random->label;
		cout << endl;
		curr = curr->next;
	}

	return 0;
}