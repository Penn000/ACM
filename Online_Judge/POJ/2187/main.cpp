//2016.10.2
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define N 50005
#define eps 1e-8

using namespace std;

int n;

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
	double len2(){//向量模的平方
		return x*x+y*y;
	}
}p[N];

struct polygon
{
	int n;
	point p[N];
}pg;

double cp(point o, point a, point b)//向量oa，ob叉积
{
	return (a-o)*(b-o);
}

int sign(double x)//三态函数，大于eps为1，小于-eps为-1，其余为0
{
	return (x>eps)?1:((x<-eps)?-1:0);
}

bool cmp_angle(const point a, const point b)//按极角排序
{
	int tmp = sign(cp(p[0], a, b));
	if(tmp>0 || (tmp==0&&(p[0]-a).len2()<(p[0]-b).len2()))return true;
	else return false;
}

void Convex(int &n)//Graham扫描法
{
	sort(p, p+n);
	int top, m;
	pg.p[0] = p[0]; pg.p[1] = p[1]; top = 1;
	for(int i = 2; i < n; i++)//从前往后扫
	{
		while(top>0 && cp(p[i], pg.p[top], pg.p[top-1])>=0)top--;
		pg.p[++top] = p[i];
	}
	m = top;
	pg.p[++top] = p[n-2];
	for(int i = n-3; i >= 0; i--)//从后往前扫
	{
		while(top>m && cp(p[i], pg.p[top], pg.p[top-1])>=0)top--;
		pg.p[++top] = p[i];
	}
	pg.n = top;
}

int rotating_calipers()//旋转卡壳
{
	int v = 1;n = pg.n;
	double ans = 0;
	pg.p[n] = pg.p[0];
	for(int u = 0; u < n; u++)//旋转
	{
		while(cp(pg.p[u],pg.p[u+1],pg.p[v+1])>cp(pg.p[u],pg.p[u+1],pg.p[v]))v = (v+1)%n;
		ans = max(ans, max((pg.p[u]-pg.p[v]).len2(), (pg.p[u+1]-pg.p[v+1]).len2()));
	}
	return ans;
}

int main()
{
	int n;
	while(scanf("%d", &n)!=EOF && n)
	{
		for(int i = 0; i < n; i++)
		  	scanf("%lf%lf", &p[i].x, &p[i].y);
		Convex(n);
//		for(int i = 0; i<pg.n; i++)
//		  printf("%lf %lf\n", pg.p[i].x, pg.p[i].y);
		int ans = rotating_calipers();
		printf("%d\n", ans);
	}

    return 0;
}
