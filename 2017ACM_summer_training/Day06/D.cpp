//2017-09-04
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
#define lson (id<<1)
#define rson ((id<<1)|1)

using namespace std;

const int N = 110000;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int head[N<<4], tot;
struct Edge{
	int to, w, next;
}edge[N<<7];

void init(){
	tot = 0;
	memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int w){
	edge[tot].w = w;
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}

vector<int> vec;
int tree[2][N<<4], idx;
//k为0表示从顶向下的线段树
//k为1表示从底向上的线段树
void build(int id, int l, int r, int k){
	tree[k][id] = ++idx;
	if(l == r){
		if(k == 0)
		  add_edge(tree[k][id], l, 0);
		else 
		  add_edge(l, tree[k][id], 0);
		return;
	}
	int mid = (l+r)>>1;
	build(lson, l, mid, k);
	build(rson, mid+1, r, k);
	if(k == 0){
		add_edge(tree[k][id], tree[k][lson], 0);
		add_edge(tree[k][id], tree[k][rson], 0);
	}else{
		add_edge(tree[k][lson], tree[k][id], 0);
		add_edge(tree[k][rson], tree[k][id], 0);
	}
}

//获得[L, R]区间对应的节点集合
//l，r为辅助变量，k表示操作第k棵线段树
void get_interval(int id, int l, int r, int L, int R, int k){
	if(L <= l && r <= R){
		vec.push_back(tree[k][id]);
		return;
	}
	int mid = (l+r)>>1;
	if(mid >= L)
	  get_interval(lson, l, mid, L, R, k);
	if(mid < R)
	  get_interval(rson, mid+1, r, L, R, k);
}

bool vis[N<<4];
ll dis[N<<4];
int cnt[N<<4];
deque<int> dq;

bool spfa(int s, int n){
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; i++)
	  	dis[i] = INF;
	vis[s] = 1;
	dis[s] = 0;
	cnt[s] = 1;
	deque<int> dq;
	dq.push_back(s);
	while(!dq.empty()){
		int u = dq.front();
		dq.pop_front();
		vis[u] = 0;
		for(int i = head[u]; i != -1; i = edge[i].next){
			int v = edge[i].to;
			if(dis[v] > dis[u] + edge[i].w){
				dis[v] = dis[u] + edge[i].w;
				if(!vis[v]){
					vis[v] = 1;
					dq.push_back(v);
					if(++cnt[v] > n)return false;
				}
			}
		}
	}
	return true;
}
int main()
{
	freopen("inputD.txt", "r", stdin);
	int n, q, s;
	while(scanf("%d%d%d", &n, &q, &s) != EOF){
		init();
		idx = n;//线段树上表示区间的点从n+1开始
		build(1, 1, n, 0);
		build(1, 1, n, 1);
		int l, r, v, w, u, t;
		while(q--){
			scanf("%d", &t);
			if(t == 1){
				scanf("%d%d%d", &v, &u, &w);
				add_edge(v, u, w);
			}else if(t == 2){
				scanf("%d%d%d%d", &v, &l, &r, &w);
				vec.clear();
				get_interval(1, 1, n, l, r, 0);
				for(auto &u : vec)
				  add_edge(v, u, w);
			}else if(t == 3){
				scanf("%d%d%d%d", &v, &l, &r, &w);
				vec.clear();
				get_interval(1, 1, n, l, r, 1);
				for(auto &u : vec)
				  add_edge(u, v, w);
			}
		}
		spfa(s, 5*n);
		for(int i = 1; i <= n; i++)
		  	if(dis[i] == INF)
			  	printf("-1 ");
			else printf("%I64d ", dis[i]);
		printf("\n");
	}

	return 0;
}
