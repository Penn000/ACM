//2017-08-24
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#pragma comment(linker, "/STACK:1024000000,1024000000") 

using namespace std;

const int N = 100010;
const int INF = 0x3f3f3f3f;
int head[N], tot;
int que[N];
struct Edge{
    int next, to, w;
}edge[N<<4];

void add_edge(int u, int v, int w){
    edge[tot].w = w;
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
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
        //queue<int> que;
		int front = 0, tail = 0;
        memset(level, -1, sizeof(level));
        level[S] = 0;
        //que.push(S);
		que[tail++] = S;
        while(front < tail){
            //int u = que.front();
            //que.pop();
			int u = que[front++];
			if(u == T)return true;
            for(int i = head[u]; i != -1; i = edge[i].next){
                int v = edge[i].to;
                int w = edge[i].w;
                if(level[v] == -1 && w > 0){
                    level[v] = level[u]+1;
                    //que.push(v);
					que[tail++] = v;
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
        if(ans == 0)level[u] = -2;
        return ans;
    }
    int maxflow(){
        int flow = 0, tmp;
        while(bfs())
              while((tmp = dfs(S, INF)) > 0)
                  flow += tmp;
        return flow;    
    }
}dinic;

int main()
{
    int T, n, m;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        int x, y, s = 1, t = 1, mininum = INF, maxinum = -INF;
        for(int i = 1; i <= n; i++){
            scanf("%d%d", &x, &y);
            if(x < mininum){
                mininum = x;
                s = i;
            }
            if(x > maxinum){
                maxinum = x;
                t = i;
            }
        }
        dinic.init(s, t);
        int u, v, w;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w);
            add_edge(v, u, w);
        }
        printf("%d\n", dinic.maxflow());
    }    
    return 0;
}
