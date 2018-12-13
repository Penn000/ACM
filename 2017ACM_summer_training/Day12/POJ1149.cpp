#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 110;
const int inf = 0x3f3f3f3f;
int m, n;

int head[N], tot;
struct Edge{
	int next, to, w;
}edge[N<<4];

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
	int level[N], s, t;
	void init(int _s, int _t){
		s = _s;
		t = _t;
		tot = 0;
		memset(head, -1, sizeof(head));
	}
	bool bfs(){
		queue<int> que;
		memset(level, 0, sizeof(level));
		que.push(s);
		while(!que.empty()){
			int u = que.front();
			que.pop();
			for(int i = head[u]; i != -1; i = edge[i].next){
				int v = edge[i].to;
				int w = edge[i].w;
				if(level[v] == 0 && w > 0){
					level[v] = level[u]+1;
					que.push(v);
				}
			}
		}
		return level[t] != 0;
	}
	int dfs(int u, int flow){
		if(u == t)return flow;
		int ans = 0, fw;
		for(int i = head[u]; i != -1; i = edge[i].next){
			fw = dfs(edge[i].to, min(flow-ans, edge[i].w));
			ans += fw;
			edge[i].w -= fw;
			edge[i^1].w += fw;
			if(ans == flow)return ans;
		}
		if(ans == 0)level[u] = 0;
		return ans;
	}
	int maxflow(){
		int flow = 0;
		while(bfs())
		  	flow += dfs(s, inf);
		return flow;	
	}
};

int main(){
	while(scanf("%d%d", &m, &n)!=EOF){
		for(int i = 0; i < n; i++){

		}
	}

    return 0;
}
