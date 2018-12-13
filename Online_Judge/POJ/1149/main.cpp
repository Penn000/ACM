//2017-08-23
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int N = 510;
const int M = 1010;
const int INF = 0x3f3f3f3f;
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

int house[M];

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	int n, m;
	while(cin>>m>>n){
		int s = 0, t = n+1;
		dinic.init(s, t);
		for(int i = 1; i <= m; i++)
		  cin>>house[i];
		int k, v;
		int book[M];
		memset(book, 0, sizeof(book));
		for(int i = 1; i <= n; i++){
			cin>>k;
			int weight = 0;
			while(k--){
				cin>>v;
				if(!book[v]){
					book[v] = i;
					weight += house[v];
				}else{
					add_edge(book[v], i, INF);
				}
			}
			if(weight)add_edge(s, i, weight);
			cin>>v;
			add_edge(i, t, v);
		}
		cout<<dinic.maxflow()<<endl;
	}
	return 0;

}

