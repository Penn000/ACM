//2017-08-30
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 110;
const double EPS = 1e-8;

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
	void set_a_b(const Point &_a, const Point &_b){
		a = _a;
		b = _b;
	}
}seg[N];

//三态函数
int sgn(double x){
	if(fabs(x) < EPS)return 0;
	if(x < 0)return -1;
	else return 1;
}

//input：Point a；Point b
//output：distance a、b两点间的距离
//note：该函数取名distance会编译错误
double dist(Point a, Point b){
	return sqrt((a-b)*(a-b));
}

//input：l1 直线l1；l2 线段l2
//output：true 直线l1与线段l2相交；false 直线l1与线段l2不想交
bool seg_inter_line(Line l1, Line l2){
	return sgn((l2.a-l1.b)^(l1.a-l1.b))*sgn((l2.b-l1.b)^(l1.a-l1.b)) <= 0;
}

int n;
//input：直线line
//output：true 直线与所有线段都相交
bool all_inter(Line line){
	for(int i = 0; i < n; i++)
	  	if(!seg_inter_line(line, seg[i]))
		  	return false;
	return true;
}

bool check(){
	Line line;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j)continue;
			if(dist(seg[i].a, seg[j].a) > EPS){
				line.set_a_b(seg[i].a, seg[j].a);
				if(all_inter(line))return true;
			}
			if(dist(seg[i].a, seg[j].b) > EPS){
				line.set_a_b(seg[i].a, seg[j].b);
				if(all_inter(line))return true;
			}
			if(dist(seg[i].b, seg[j].a) > EPS){
				line.set_a_b(seg[i].b, seg[j].a);
				if(all_inter(line))return true;
			}
			if(dist(seg[i].b, seg[j].b) > EPS){
				line.set_a_b(seg[i].b, seg[j].b);
				if(all_inter(line))return true;
			}
		}
	}
	return false;
}

int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("inputC.txt", "r", stdin);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>seg[i].a.x>>seg[i].a.y>>seg[i].b.x>>seg[i].b.y;
		}
		if(check() || n == 1 || n == 2)cout<<"Yes!"<<endl;
		else cout<<"No!"<<endl;
	}

	return 0;
}
