#include <bits/stdc++.h>
using namespace std;
#define maxm 400010
#define maxn 1010
#define inf 1<<30
int head[maxm], tot;
int n, m;
int que[maxn], Layer[maxn];
struct node{
	int to, next, cap;
}G[maxm];
void add(int u, int v, int cap){
	G[tot].to = v, G[tot].cap = cap, G[tot].next = head[u], head[u] = tot++;
	G[tot].to = u, G[tot].cap = 0, G[tot].next = head[v], head[v] = tot++;
}
bool bfs(){
	int rear = 0;
	memset(Layer, -1, sizeof Layer);
	que[rear++] = 0;
	Layer[0] = 0;
	for(int i = 0;i < rear;i++){
		int u = que[i];
		for(int j = head[u];j != -1;j = G[j].next){
			int v = G[j].to;
			if(G[j].cap>0&&Layer[v]==-1){
				Layer[v] = Layer[u] + 1;
				que[rear++] = v;
				if(v == n-1) return 1;
			}
		}
	}
	return 0;
}
int dfs(int u, int maxflow){
	if(u == n-1||maxflow==0) return maxflow;
	int sum = 0;
	for(int i = head[u];i != -1;i = G[i].next){
		int v = G[i].to;
		if(G[i].cap>0&&Layer[v]==Layer[u]+1){
			int t = dfs(v, min(maxflow, G[i].cap));
			G[i].cap -= t;
			G[i^1].cap += t;
			sum += t;
			maxflow -= t;
		}
	}
	return sum;
}
int dinic()
{
	int ans = 0;
	while(bfs()){
		ans += dfs(0, inf);
	}
	return ans;
}
int main()
{
	int u, v, c, d, i, j, T, k = 1;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &n, &m);
		memset(head, -1, sizeof head);
		tot = 0;
		for(i = 0;i < m;i++){
			scanf("%d%d%d", &u, &v, &c);
			add(u, v, c);
		}
		dinic();
		for(i = 0;i < tot;i+=2){
			if(G[i].cap==0){
				G[i].cap = 1;
				G[i^1].cap = 0;
			}else{
				G[i].cap = inf;
				G[i^1].cap = 0;
			}
		}
		printf("%d\n", dinic());
	}
}

