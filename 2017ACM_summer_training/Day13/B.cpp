//2017-09-13
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

const int N = 210000;
const int LOG_N = 22;

int head[N], tot;
struct Edge{
	int v, next;
}edge[N<<1];

void add_edge(int u, int v){
	edge[tot].v = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}

int in[N], out[N], idx, depth[N], father[N][LOG_N];
void dfs(int u, int fa){
	in[u] = ++idx;
	for(int i = head[u]; i != -1; i = edge[i].next){
		int v = edge[i].v;
		if(v == fa)continue;
		depth[v] = depth[u]+1;
		father[v][0]= u;
		for(int j = 1; j < LOG_N; j++)
		  father[v][j] = father[father[v][j-1]][j-1];
		dfs(v, u);
	}
	out[u] = ++idx;
}

int tree[N];

int lowbit(int x){
	return x&(-x);
}

void add(int pos, int val){
	for(int i = pos; i <= N; i+=lowbit(i))
	  tree[i] += val;
}

int query(int l){
	int sum = 0;
	for(int i = l; i > 0; i-=lowbit(i))
	  sum += tree[i];
	return sum;
}

int lca(int u, int v){
	if(depth[u] < depth[v])
	  swap(u, v);
	for(int i = LOG_N-1; i >= 0; i--){
		if(depth[father[u][i]] >= depth[v])
		  u = father[u][i];
	}
	if(u == v)return u;
	for(int i = LOG_N-1; i >= 0; i--){
		if(father[u][i] != father[v][i]){
			u = father[u][i];
			v = father[v][i];
		}
	}
	return father[u][0];
}
struct Chain{
	int u, v, w;
}chain[N];
vector<int> vec[N];

int dp[N], sum[N];
void solve(int u, int fa){
	dp[u] = sum[u] = 0;
	for(int i = head[u]; i != -1; i = edge[i].next){
		int v = edge[i].v;
		if(v == fa)continue;
		solve(v, u);
		sum[u] += dp[v];
	}
	dp[u] = sum[u];
	for(auto &pos: vec[u]){
		int a = chain[pos].u;
		int b = chain[pos].v;
		int c = chain[pos].w;
		dp[u] = max(dp[u], sum[u]+query(in[a])+query(in[b])+c);
	}
	add(in[u], sum[u]-dp[u]);
	add(out[u], dp[u]-sum[u]);
}

int T, n, m;
void init(){
	tot = 0;
	idx = 0;
	depth[1] = 1;
	for(int i = 1; i <= n; i++)
	  vec[i].clear();
	memset(head, -1, sizeof(head));
	memset(dp, 0, sizeof(0));
	memset(sum, 0, sizeof(0));
	memset(tree, 0, sizeof(tree));
}

int main()
{
	freopen("inputB.txt", "r", stdin);
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		init();
		int u, v;
		for(int i = 0; i < n-1; i++){
			scanf("%d%d", &u, &v);
			add_edge(u, v);
			add_edge(v, u);
		}
		dfs(1, 0);
		for(int i = 0; i < m; i++){
			scanf("%d%d%d", &chain[i].u, &chain[i].v, &chain[i].w);
			vec[lca(chain[i].u, chain[i].v)].push_back(i);
		}
		solve(1, 0);
		printf("%d\n", dp[1]);
	}

	return 0;
}
