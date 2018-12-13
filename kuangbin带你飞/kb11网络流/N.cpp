//2017-08-25
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define mid ((l+r)>>1)

using namespace std;

const int N = 510;
const int M = 100000;
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

bool G[N][N];
int T, n, m, f;
int never_quarreled[M][2], friends[M][2];
void build_graph(int cap){
	int s = 0, t = 2*n+1;
	dinic.init(s, t);
	memset(G, 0, sizeof(G));
	int a, b;
	for(int i = 0; i < m; i++){
		a = never_quarreled[i][0];
		b = never_quarreled[i][1];
		add_edge(a, n+b, 1);
		G[a][b] = 1;
	}
	for(int i = 0; i < f; i++){
		a = friends[i][0];
		b = friends[i][1];
		for(int i = head[a]; i != -1; i = edge[i].next){
			int v = edge[i].to;
			if(!G[b][v-n] && v != s && v != t){
				add_edge(b, v, 1);
				G[b][v-n] = 1;
			}
		}
		for(int i = head[b]; i != -1; i = edge[i].next){
			int v = edge[i].to;
			if(!G[a][v-n] && v != s && v != t){
				add_edge(a, v, 1);
				G[a][v-n] = 1;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		add_edge(s, i, cap);
		add_edge(n+i, t, cap);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("inputN.txt", "r", stdin);
	cin>>T;
	while(T--){
		cin>>n>>m>>f;
		for(int i = 0; i < m; i++)
		  	cin>>never_quarreled[i][0]>>never_quarreled[i][1];
		for(int i = 0; i < f; i++)
		  	cin>>friends[i][0]>>friends[i][1];
		int l = 0, r = n, ans = 0;
		while(l <= r){
			build_graph(mid);
			int flow = dinic.maxflow();
			if(flow == mid*n){
				ans = mid;
				l = mid+1;
			}else{
				r = mid-1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
