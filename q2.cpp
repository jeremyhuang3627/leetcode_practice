/* Given n points on a 2D plane, find the maximum number of points that lie on the same straight line. */
#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <stdlib.h>

using namespace std;

struct Point
{
	int x;
	int y;
	Point(): x(0),y(0) {}
	Point(int a,int b) : x(a),y(b) {}
};

int equalPoint(Point p1, Point p2){
	return p1.x == p2.x && p1.y == p2.y;
}

int threePointInLine(Point p1, Point p2, Point p3)
{
	if (equalPoint(p1,p2) || equalPoint(p2, p3) || equalPoint(p1,p3)){
		return 1;
	}  

	return (p1.y - p2.y)*(p3.x - p2.x) == (p3.y - p2.y)*(p1.x - p2.x);
}

void printPoint(Point p){
	cout<< "(" << p.x << "," << p.y<<")" << endl;
}

int maxPoints(vector<Point> &p)
{
	if(p.size()<2){
		return p.size();
	}

	int maxNum = 0;
	for(int i=0;i<p.size();i++)
	{
		for(int j=i+1;j<p.size();j++)
		{ 
			int maxNumForOneLine = 0;
			if(equalPoint(p[i],p[j])){
				continue;
			}
			for(int k=0;k<p.size();k++)
			{
					if(threePointInLine(p[i],p[j],p[k])){
						maxNumForOneLine ++;
					}
			}
			if(maxNumForOneLine > maxNum){
				maxNum = maxNumForOneLine;
			}
		}
	}

	if(maxNum == 0){
		return p.size();
	}
	return maxNum;
}

int main(){
	vector<Point> points;
	points.push_back(Point(0,9));
	points.push_back(Point(138,429));
	points.push_back(Point(115,359));
	points.push_back(Point(115,359));
	points.push_back(Point(-30,-102));
	points.push_back(Point(230,709));
	points.push_back(Point(-150,-686));
	points.push_back(Point(-135,-613));
	points.push_back(Point(-60,-248));
	points.push_back(Point(-161,-481));
	points.push_back(Point(207,639));
	points.push_back(Point(23,79));
	points.push_back(Point(-230,-691));
	points.push_back(Point(-115,-341));
	points.push_back(Point(92,289));
	points.push_back(Point(60,336));
	points.push_back(Point(-105,-467));
	points.push_back(Point(135,701));
	points.push_back(Point(-90,-394));
	points.push_back(Point(-184,-551));
	points.push_back(Point(150,774));

	cout << "max num of points on a line " << maxPoints(points) << endl; 

	return 0;
}