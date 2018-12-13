//2017-08-30
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

const int N = 110;
const double EPS = 1e-8;

//三态函数
int sgn(double x){
	if(fabs(x) < EPS)return 0;
	if(x < 0)return -1;
	else return 1;
}

struct Point{
	double x, y;
	Point(){}
	Point(double _x, double _y):x(_x), y(_y){}
	Point(const Point &p):x(p.x), y(p.y){}
	//a-b为向量ba
	Point operator- (const Point &b) const {
		return Point(x-b.x, y-b.y);
	}
	//向量叉积
	double operator^ (const Point &b) const {
		return x*b.y - y*b.x;
	}
	//向量点积
	double operator* (const Point &b) const {
		return x*b.x + y*b.y;
	}
};

struct Line{
	Point a, b;
	Line(){}
	Line(Point _a, Point _b):a(_a), b(_b){}
	//判断两直线关系
	//input：两直线
	//output：pair<int, Point> first == 0 表示直线重合
	//                         first == 1 表示两直线平行
	//                         first == 2 表示两直线相交，second 为交点
	pair<int, Point> operator & (const Line &line) const{
		Point res = a;
		if(sgn((a-b)^(line.a-line.b)) == 0){
			if(sgn((a-line.b)^(line.a-line.b)) == 0)
			  	return make_pair(0, res);
			else return make_pair(1, res);
		}
		double t = ((a-line.a)^(line.a-line.b))/((a-b)^(line.a-line.b));
		res.x += (b.x-a.x)*t;
		res.y += (b.y-a.y)*t;
		return make_pair(2, res);
	}
}seg[N];


int n;
int main()
{
	std::ios::sync_with_stdio(false);
	freopen("inputE.txt", "r", stdin);

	return 0;
}
