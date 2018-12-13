//2017-08-24
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 110000;
const int M = 5100100;
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
int status[1<<12];//status[S]表示状态为S的人数，例如S=1010，表示可以在2号和4号星球上生存(从低位标号)

int main()
{
	std::ios::sync_with_stdio(false);	
	//freopen("inputM.txt", "r", stdin);
	int n, m;
	while(cin>>n>>m){
		int s = 0, t = n+m+1;
		dinic.init(s, t);
		int w;
		memset(status, 0, sizeof(status));
		for(int i = 1; i <= n; i++){
			int tmp = 0;
			for(int j = 1; j <= m; j++){
				tmp <<= 1;
				cin>>w;
				tmp |= w;
			}
			status[tmp]++;
		}
		for(int i = 1; i <= (1<<10); i++){
			if(status[i]){
				add_edge(s, i, status[i]);
				for(int j = 1; j <= m; j++){
					if(i & (1<<(j-1)))
					  	add_edge(i, n+j, status[i]);
				}
			}
		}
		int sum = 0;
		for(int i = 1; i <= m; i++){
			cin>>w;
			sum += w;
			add_edge(n+i, t, w);
		}
		if(sum < n){
			cout<<"NO"<<endl;
			continue;
		}
		if(dinic.maxflow() == n)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}	
	return 0;
}
