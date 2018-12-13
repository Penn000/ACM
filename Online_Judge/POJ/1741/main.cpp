//2017-08-09
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 10010;
int n, k, MAX, root, cnt, answer;

//链式前向星
int head[N], tot;
struct Edge{
	int next, to, w;
}edge[N<<4];

void add_edge(int u, int v, int w){
	edge[tot].w = w;
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}

int size[N];//size[i]表示以i为根的子树的大小，包括i。
int maxson[N];//maxson[i]表示以i为根的子树的最大儿子的大小。
int dis[N];//dis[i]表示i到根的距离。
bool vis[N];//vis[i]用来标记i点是否被删除。

void init(int n){
	answer = 0;
	tot = 0;
	memset(vis, 0, sizeof(vis));
	memset(head, -1, sizeof(head));
}

//计算出子树的大小
void dfs_size(int u, int fa){
	size[u] = 1;
	maxson[u] = 0;
	for(int i = head[u]; ~i; i = edge[i].next){
		int v = edge[i].to;
		if(vis[v] || v == fa)continue;
		dfs_size(v, u);
		size[u] += size[v];
		if(size[v] > maxson[u])
		  	maxson[u] = size[v];
	}
}

//找子树的重心。最大子树最小的点即为树的重心。
void dfs_root(int r, int u, int fa){
	if(size[r] - size[u] > maxson[u])//size[r]-size[u]为u上面的树的尺寸
	  	maxson[u] = size[r] - size[u];
	if(maxson[u] < MAX){
		MAX = maxson[u];
		root = u;
	}
	for(int i = head[u]; ~i; i = edge[i].next){
		int v = edge[i].to;
		if(vis[v] || v == fa)continue;
		dfs_root(r, v, u);
	}
}

//计算出子树中每个点距离重心的距离
void dfs_dis(int u, int d, int fa){
	dis[cnt++] = d;
	for(int i = head[u]; ~i; i = edge[i].next){
		int v = edge[i].to;
		if(vis[v] || v == fa)continue;
		dfs_dis(v, d+edge[i].w, u);
	}
}

//计算出以u为根的子树中距离和小于k的点对数
int cal(int u, int d){
	int ans = 0;
	cnt = 0;
	dfs_dis(u, d, 0);
	sort(dis, dis+cnt);
	for(int i = 0, j = cnt-1; i < j; i++){
		while(dis[i]+dis[j] > k && i < j)//双指针
		  	j--;
		ans += j-i;
	}
	return ans;
}

//分治，找到树的重心，分为经过重心的点对和不经过重心的点对。
void solve(int u){
	MAX = n;
	dfs_size(u, 0);
	dfs_root(u, u, 0);
	answer += cal(root, 0);
	vis[root] = 1;
	for(int i = head[root]; ~i; i = edge[i].next){
		int v = edge[i].to;
		if(vis[v])continue;
		answer -= cal(v, edge[i].w);
		solve(v);
	}
}

int main()
{
	//freopen("dataIn.txt", "r", stdin);
	while(scanf("%d%d", &n, &k)!=EOF){
		if(!n && !k)break;
		int u, v, w;
		init(n);
		for(int i = 0; i < n-1; i++){
			scanf("%d%d%d", &u, &v, &w);
			add_edge(u, v, w);
			add_edge(v, u, w);
		}
		solve(1);
		printf("%d\n", answer);
	}

	return 0;
}
