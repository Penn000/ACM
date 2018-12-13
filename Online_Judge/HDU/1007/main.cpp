//2017-08-09
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define mid ((l+r)>>1)

using namespace std;

const int N = 100010;
struct Point{
	double x, y;
}P[N], p1[N], p2[N];
int n;

bool cmp_x(Point a, Point b){
	return a.x < b.x;
}

bool cmp_y(Point a, Point b){
	return a.y < b.y;
}

double distance(Point *a, Point *b){
	return sqrt((a->x - b->x)*(a->x - b->x) + (a->y - b->y)*(a->y - b->y));
}

//分治，solve(l, r)表示区间[l, r]内的最近点对，solve(l, r) = min(solve(l, mid), solve(mid+1, r), 跨左右子区间的最近点对)
double solve(int l, int r){
	if(l >= r)return 0;
	if(r - l == 1)return distance(&P[l], &P[r]);
	if(r - l == 2)return min(distance(&P[l], &P[l+1]), distance(&P[l+1], &P[r]));
	double ans = min(solve(l, mid), solve(mid+1, r));
	//暴力x坐标与mid的x坐标相差不超过当前最优解ans的点
	int m = 0;
	for(int i = l; i <= r; i++){
		if(fabs(P[mid].x - P[i].x) <= ans){
			p1[m++] = P[i];
		}
	}
	sort(p1, p1+m, cmp_y);
	for(int i = 0; i < m; i++){
		for(int j = i+1; j < m; j++){
			if(p1[j].y - p1[i].y > ans)break;
			ans = min(ans, distance(&p1[i], &p1[j]));
		}
	}
	return ans;
}

int main()
{
	//freopen("dataIn.txt", "r", stdin);
	while(scanf("%d", &n)!=EOF && n){
		for(int i = 0; i < n; i++)
		  	scanf("%lf%lf", &P[i].x, &P[i].y);
		sort(P, P+n, cmp_x);
		printf("%.2lf\n", solve(0, n-1)/2);
	}

	return 0;
}
