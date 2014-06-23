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

struct UndirectedGraphNode{
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x):label(x){}
};

UndirectedGraphNode * cloneGraph(UndirectedGraphNode * node)
{
	if(node != NULL){
		map<int, UndirectedGraphNode *> m1;
		vector<UndirectedGraphNode *> nodeVector;
		queue<UndirectedGraphNode *> q;
		q.push(node);
		map<UndirectedGraphNode *,bool> visited;
		visited[node] = true;
		int val = node->label;
		UndirectedGraphNode * newNode = new UndirectedGraphNode(val);
		m1[val] = newNode;
		nodeVector.push_back(node);

		while(!q.empty())
		{
			UndirectedGraphNode * n = q.front();
			q.pop();
			vector<UndirectedGraphNode *> v = n->neighbors;
			for(int i=0; i<v.size();i++)
			{
				if(!visited[v[i]]){
					val = v[i]->label;
					newNode = new UndirectedGraphNode(val);
					m1[val] = newNode;
					nodeVector.push_back(v[i]);
					q.push(v[i]);
					visited[v[i]] = true;	
				}
			}
		}

		for(int i=0;i<nodeVector.size();i++)
		{
			val = nodeVector[i]->label;
			//cout << "val "<< val << endl;
			vector<UndirectedGraphNode *> neighbors = nodeVector[i]->neighbors;
			for(int j=0;j<neighbors.size();j ++)
			{
				int nVal = neighbors[j]->label;
				m1[val]->neighbors.push_back(m1[nVal]);
			}
		}

		return m1[node->label];
	}

	return node;
}

int main(){

	UndirectedGraphNode * root = new UndirectedGraphNode(0);
	UndirectedGraphNode * n1 = new UndirectedGraphNode(1);
	UndirectedGraphNode * n2 = new UndirectedGraphNode(2);
	root->neighbors.push_back(n1);
	root->neighbors.push_back(n2);
	n1->neighbors.push_back(n2);
	n2->neighbors.push_back(n2);

	UndirectedGraphNode * newGraph = cloneGraph(root);

	return 0;
}