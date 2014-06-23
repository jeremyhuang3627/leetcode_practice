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


struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
    if(head==NULL)
    {
    	return head;
    }	

    map<RandomListNode *,int> m;
    vector<RandomListNode *> w;
    RandomListNode * cur = head;
    int c = 0;
    while(cur!=NULL)
    {
    	m[cur] = c;
    	int val = cur->label;
    	RandomListNode * n = new RandomListNode(val);
    	w.push_back(n);
    	cur = cur->next;
    	c++;
    }

    map<RandomListNode *,int>::iterator it;

    c = 0;
    for(it=m.begin();it!=m.end();++it)
    {
    	RandomListNode * rp = it->first->random;
    	if(rp){
	    	int rIndex = m[rp];
	    	w[c]->random = w[rIndex];
	    }
    	if(c < w.size()-1)
    	{
    		w[c]->next = w[c+1];
    	}
    	c++;
    } 
    
    RandomListNode * t = w[0];

    return t;
}

int main(){
	RandomListNode * r = new RandomListNode(1);
	r->next = new RandomListNode(2);
	r->next->next = new RandomListNode(3);
	r->next->next->next = new RandomListNode(4);
	r->next->next->next->next = new RandomListNode(5);

	r->random = r->next->next;
	r->next->random = r->next->next->next;
	r->next->next->next->random = r->next;
	r->next->next->next->next->random = r->next->next->next->next->random;

	cout << "before " << endl;
	RandomListNode * p = r;
	while(p!=NULL)
	{
		int ran;
		if(p->random){
			ran = p->random->label;
		}else{
			ran = 0;
		}
		cout << "label " << p->label << " random " << ran << endl;
		p=p->next;
	}

	RandomListNode * c = copyRandomList(r);

	cout << "after " << endl; 

	p = c;
	while(p!=NULL)
	{
		int ran;
		if(p->random){
			ran = p->random->label;
		}else{
			ran = 0;
		}
		cout << "label " << p->label << " random " << ran << endl;
		p=p->next;
	}

	return 0;
}



