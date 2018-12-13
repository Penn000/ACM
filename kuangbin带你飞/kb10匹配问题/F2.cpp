//2017-08-26
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 10000;
const int M = 10000000;
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

//	edge[tot].w = 0;
//	edge[tot].to = u;
//	edge[tot].next = head[v];
//	head[v] = tot++;
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
			//edge[i^1].w += fw;
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

int n, m, pour_time;

struct Guests{
	int x, y, speed;
}guests[3010];

struct Umbrella{
	int x, y;
}umbrella[3010];

bool getUmbrella(int i, int j){
	return (guests[i].x-umbrella[j].x)*(guests[i].x-umbrella[j].x)
		+ (guests[i].y-umbrella[j].y)*(guests[i].y-umbrella[j].y)
		<= guests[i].speed*guests[i].speed*pour_time*pour_time;
}

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("inputF.txt", "r", stdin);
	int T, kase = 0;
	cin>>T;
	while(T--){
		cin>>pour_time>>m;
		int s = 0, t = n+m+1;
		dinic.init(s, t);
		for(int i = 1; i <= m; i++){
		  cin>>guests[i].x>>guests[i].y>>guests[i].speed;
		  add_edge(s, i, 1);
		}
		cin>>n;
		for(int i = 1; i <= n; i++){
		  cin>>umbrella[i].x>>umbrella[i].y;
		  add_edge(m+i, t, 1);
		}
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= n; j++){
				if(getUmbrella(i, j)){
					add_edge(i, m+j, 1);
				}
			}
		}
		//cout<<"graph ok"<<endl;
		cout<<"Scenario #"<<++kase<<":"<<endl<<dinic.maxflow()<<endl<<endl;
	}
	return 0;
}
