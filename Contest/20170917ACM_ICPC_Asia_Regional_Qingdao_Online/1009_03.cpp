//2017-09-18
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

const int N = 1500;
const int M = 1000000;
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

void init_edge(){
    tot = 0;
    memset(head, -1, sizeof(head));
}
struct Dinic{
    int level[N], S, T;
    void setST(int _S, int _T){
        S = _S;
        T = _T;
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
        if(ans == 0)level[u] = 0;
        return ans;
    }
    int maxflow(){
        int flow = 0;
        while(bfs())
          flow += dfs(S, INF);
        return flow;    
    }
}dinic;

int main()
{
	int T, n, m, s, t;
	scanf("%d", &T);
    while(T--){
		init_edge();
		scanf("%d%d%d%d", &n, &m, &s, &t);
		dinic.setST(s, t);
		int u, v, w;
		while(m--){
			scanf("%d%d%d", &u, &v, &w);
			add_edge(u, v, w);
		}
		dinic.maxflow();
		for(int i = 0; i < tot; i += 2){
			if(edge[i].w == 0){
				edge[i].w = 1;
				edge[i^1].w = 0;
			}else{
				edge[i].w = INF;
				edge[i^1].w = 0;
			}
		}
		printf("%d\n", dinic.maxflow());
    }
    return 0;
}
