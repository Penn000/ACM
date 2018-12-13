//2018-09-09
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define lson (id<<1)
#define rson ((id<<1)|1)
using namespace std;

const int N = 2000;
const double EPS = 0.0001;

struct Node{
	double sum;
}tree[N<<2];
int cnt[N], len;
double x[N];

void build(){
	memset(tree, 0, sizeof(tree));
}

void update(int id, int L, int R, int pos, int val){
	if(L==R){
		cnt[pos] += val;
		if(cnt[pos]>1)tree[id].sum = x[pos+1]-x[pos];
		else tree[id].sum = 0;
		return;
	}
	int mid = (L+R)/2;
	if(pos <= mid)update(lson, L, mid, pos, val);
	else update(rson, mid+1, R, pos, val);
	tree[id].sum = tree[lson].sum+tree[rson].sum;
}

struct Line{
	double x0, x1, y;
	int fg;
	bool operator<(const Line l) const{
		return y < l.y;
	}
}line[N<<2];

int main()
{
	int T, n, kase = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d", &n);
		double x0, y0, x1, y1;
		len = 0;
		for(int i = 1; i <= n; i++){
			scanf("%lf%lf%lf%lf", &x0, &y0, &x1, &y1);
			int a = i*2-1, b = i*2;
			line[a].x0 = x0, line[a].x1 = x1, line[a].y = y0, line[a].fg = 1;
			line[b].x0 = x0, line[b].x1 = x1, line[b].y = y1, line[b].fg = -1;
			x[++len] = x0, x[++len] = x1;
		}
		n*=2;
		sort(x+1, x+1+n);
		sort(line+1, line+1+n);
		memset(cnt, 0, sizeof(cnt));
		build();
		double ans = 0;
		// 扫面线从下往上扫
		for(int i = 1; i <= n; i++){
			ans += tree[1].sum*(line[i].y-line[i-1].y);
			int l = lower_bound(x+1, x+1+n, line[i].x0)-x;
			int r = lower_bound(x+1, x+1+n, line[i].x1)-x;
			for(int j = l; j < r; j++){
				// 线段树叶子节点表示线段x_i,x_i+1的长度，因此叶子节点共有n-1个，每次只需更新[l,r)的线段
				update(1, 1, n-1, j, line[i].fg);
			}
		}
		printf("%.2lf\n", ans+EPS);
	}

	return 0;
}
