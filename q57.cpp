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

char * strStr(char *haystack, char *needle)
{
	char * p = haystack;
	while(*p != '\0')
	{
		if(*p == *needle)
		{
			return p;
		}
		p++;
	}

	return (char *)"";
}



int main()
{
	const char * haystack = "";
	char c = "";
	char *needle = &c;
	char * np = strStr((char *)haystack,needle);
	cout << *np <<endl;

	while(*np!='\0')
	{
		cout << *np << endl;
		np++;
	} 

	string c2 = "";
	cout << c2 << endl;

	return 0;
}