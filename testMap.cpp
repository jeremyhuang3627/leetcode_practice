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

int main()
{
	map<int,int> m;

	m[1] = 10;
	cout << "m[1]" << m[1] << endl;
	m.erase(1);
	cout << "m[1]" << m[1] << endl;

	return 0;
}