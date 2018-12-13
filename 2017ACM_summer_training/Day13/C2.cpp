//2017-08-16
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;
const int INF = 0x3f3f3f3f;

//链式前向星存图
int head[N], tot;
struct Edge{
	int to, next, w;

}edge[N<<2];

void add_edge(int u, int v, int w){
	edge[tot].w = w;
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}

void init(){
	tot = 0;
	memset(head, -1, sizeof(head));
}

//dp[u]记录以u为根的子树，过u往下的最长路径。
//cnt[u]记录子树u上最长路径的数目。
int dp[N], cnt[N], ans, num;

void dfs(int u, int fa){
	dp[u] = 0;
	cnt[u] = 1;
	for(int i = head[u]; i != -1; i = edge[i].next){
		int v = edge[i].to;
		int w = edge[i].w;
		if(v == fa)continue;
		dfs(v, u);
		if(dp[u]+dp[v]+w > ans){
			ans = dp[u]+dp[v]+w;
			num = cnt[u]*cnt[v];
		}else if(dp[u]+dp[v]+w == ans)
		  	num += cnt[u]*cnt[v];
		if(dp[u] < dp[v]+w){
			dp[u] = dp[v]+w;
			cnt[u] = cnt[v];
		}else if(dp[u] == dp[v]+w)
		  	cnt[u] += cnt[v];
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int n;
	while(scanf("%d", &n)!=EOF){
		int u, v, w;
		init();
		for(int i = 0; i < n-1; i++){
			scanf("%d%d%d", &u, &v, &w);
			add_edge(u, v, w);
			add_edge(v, u, w);

		}
		ans = -INF;
		num = 0;
		dfs(1, 0);
		printf("%d %d\n", ans, num);
	}

	return 0;

}

