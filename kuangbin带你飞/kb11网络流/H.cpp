//2017-08-24
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#pragma comment(linker, "/STACK:1024000000,1024000000") 

using namespace std;

const int N = 2010;
const int M = 200010;
const int INF = 0x3f3f3f3f;
int head[N], tot;
struct Edge{
	int next, to, w;
}edge[M];

void add_edge(int u, int v, int w){
	edge[tot].w = w;
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;

	edge[tot].w = 0;
	edge[tot].to = u;
	edge[tot].next = head[v];
	head[v] = tot++;
}

struct Dinic{
	int level[N], S, T;
	void init(int _S, int _T){
		S = _S;
		T = _T;
		tot = 0;
		memset(head, -1, sizeof(head));
	}
	bool bfs(){
		queue<int> que;
		memset(level, -1, sizeof(level));
		level[S] = 0;
		que.push(S);
		while(!que.empty()){
			int u = que.front();
			que.pop();
			for(int i = head[u]; i != -1; i = edge[i].next){
				int v = edge[i].to;
				int w = edge[i].w;
				if(level[v] == -1 && w > 0){
					level[v] = level[u]+1;
					que.push(v);
				}
			}
		}
		return level[T] != -1;
	}
	int dfs(int u, int flow){
		if(u == T)return flow;
		int ans = 0, fw;
		for(int i = head[u]; i != -1; i = edge[i].next){
			int v = edge[i].to, w = edge[i].w;
			if(!w || level[v] != level[u]+1)
			  	continue;
			fw = dfs(v, min(flow-ans, w));
			ans += fw;
			edge[i].w -= fw;
			edge[i^1].w += fw;
			if(ans == flow)return ans;
		}
		if(ans == 0)level[u] = -1;
		return ans;
	}
	int maxflow(){
		int flow = 0, f;
		while(bfs())
		  	while((f = dfs(S, INF)) > 0)
				flow += f;
		return flow;	
	}
}dinic;

char str[N];

int main()
{
	//std::ios::sync_with_stdio(false);	
	//freopen("inputH.txt", "r", stdin);
	int n, f, d, w;
	while(scanf("%d%d%d", &n, &f, &d) != EOF){
		int s = 0, t = 2*n+f+d+2;
		dinic.init(s, t);
		for(int i = 1; i <= n; i++)
		  	add_edge(i, n+i, 1);
		for(int i = 1; i <= f; i++){
			scanf("%d", &w);
		  	add_edge(s, 2*n+i, w);
		}
		for(int i = 1; i <= d; i++){
			scanf("%d", &w);
		  	add_edge(2*n+f+i, t, w);
		}
		for(int i = 1; i <= n; i++){
			scanf("%s", str);
			for(int j = 0; j < f; j++){
				if(str[j] == 'Y')
					add_edge(2*n+j+1, i, 1);
			}
		}
		for(int i = 1; i <= n; i++){
			scanf("%s", str);
			for(int j = 0; j < d; j++){
				if(str[j] == 'Y')
					add_edge(n+i, 2*n+f+j+1, 1);
			}
		}
		printf("%d\n", dinic.maxflow());
	}	
	return 0;
}
