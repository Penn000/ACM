//2016.10.2
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define N 105
#define eps 1e-8

using namespace std;

struct point
{
	double x, y;
	point(){}
	point(double a, double b):x(a), y(b){}
	point operator-(point a){//向量减法
		return point(x-a.x, y-a.y);
	}
	point operator+(point a){//向量加法
		return point(x+a.x, y+a.y);
	}
	double operator*(point a){//向量叉积
		return x*a.y-y*a.x;
	}
	bool operator<(const point a)const{
		if(fabs(x-a.x)<eps)return y<a.y;//浮点数的判等不能直接用‘==’直接比较
		return x<a.x;
	}
	double len(){//向量的模
		return sqrt(x*x+y*y);
	}
}p[N], s[N];//p为点，s为栈

double cp(point a, point b, point o)//向量oa，ob叉积
{
	return (a-o)*(b-o);
}

void Convex(point *p, int &n)//Graham扫描法，栈内为所有凸包点
{
	sort(p, p+n);
	int top, m;
	s[0] = p[0]; s[1] = p[1]; top = 1;
	for(int i = 2; i < n; i++)//从前往后扫
	{
		while(top>0 && cp(p[i], s[top], s[top-1])>=0)top--;
		s[++top] = p[i];
	}
	m = top;
	s[++top] = p[n-2];
	for(int i = n-3; i >= 0; i--)//从后往前扫
	{
		while(top>m && cp(p[i], s[top], s[top-1])>=0)top--;
		s[++top] = p[i];
	}
	n = top;
}

int main()
{
	int n;
	while(scanf("%d", &n)!=EOF && n)
	{
		for(int i = 0; i < n; i++)
		  	scanf("%lf%lf", &p[i].x, &p[i].y);
		sort(p, p+n);
		int cnt = 0;
		for(int i = 1; i < n; i++)//去掉重复的点
		  	if(fabs(p[i].x-p[cnt].x)>eps || fabs(p[i].y-p[cnt].y)>eps)
			  	p[++cnt] = p[i];
		cnt++;
		if(cnt == 1){
			printf("0.00\n");continue;
		}else if(cnt==2){
			printf("%.2lf\n", (p[1]-p[0]).len());continue;
		}
		Convex(p, cnt);
		double ans = 0;
		s[cnt] = s[0];
		for(int i = 0; i < cnt; i++)ans+=(s[i+1]-s[i]).len();
		printf("%.2lf\n", ans);
	}

    return 0;
}
