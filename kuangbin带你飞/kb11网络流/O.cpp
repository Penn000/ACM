//2017-08-25
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 5010;
const int M = 500000;
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
}

struct Dinic{
	int level[N], S, T;
	void init(){
		tot = 0;
		memset(head, -1, sizeof(head));
	}
	void set_s_t(int _S, int _T){
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

//dis[0][u]表示从起点到u的最短距离，dis[1][u]表示从终点到u的最短距离，cnt[u]记录u入队次数，判负环用
int dis[2][N], cnt[N];
bool vis[N];
bool spfa(int s, int n, int op){
	memset(vis, false, sizeof(vis));
	memset(dis[op], INF, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	vis[s] = true;
	dis[op][s] = 0;
	cnt[s] = 1;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = false;
		for(int i = head[u]; i != -1; i = edge[i].next){
			int v = edge[i].to;
			int w = edge[i].w;
			if(dis[op][v] > dis[op][u] + w){
				dis[op][v] = dis[op][u] + w;
				if(!vis[v]){
					vis[v] = true;
					q.push(v);
					if(++cnt[v] > n)return false;
				}
			}
		}
	}
	return true;
}

struct Line{
	int u, v, w;
}line[M];

int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("inputO.txt", "r", stdin);
	int T, n, m, A, B;
	cin>>T;
	while(T--){
		cin>>n>>m;
		int u, v, w;
		for(int i = 0; i < m; i++)
		  cin>>line[i].u>>line[i].v>>line[i].w;
		cin>>A>>B;
		dinic.init();
		for(int i = 0; i < m; i++)
		  add_edge(line[i].u, line[i].v, line[i].w);
		spfa(A, n, 0);//求从起点开始到各个点的最短路
		dinic.init();
		for(int i = 0; i < m; i++)
		  add_edge(line[i].v, line[i].u, line[i].w);
		spfa(B, n, 1);//求从终点开始到各个点的最短路
		dinic.init();
		dinic.set_s_t(A, B);
		for(int i = 0; i < m; i++){
			u = line[i].u;
			v = line[i].v;
			w = line[i].w;
			//只有最短路上的边才加入网络
			if(dis[0][u]+dis[1][v]+w == dis[0][B]){
				add_edge(u, v, 1);
				add_edge(v, u, 0);
			}
		}
		cout<<dinic.maxflow()<<endl;
	}
	return 0;
}
