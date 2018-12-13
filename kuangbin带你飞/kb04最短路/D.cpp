//2017-08-08
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 1010;
const int INF = 0x3f3f3f3f;
struct Edge{
	int v, w;
	Edge(int _v = 0, int _w = 0):v(_v), w(_w){}
};
vector<Edge> E[2][N];
bool vis[N];
int dis[2][N], cnt[N], n, m, x;

bool spfa(int s, int n, int time){
	memset(vis, false, sizeof(vis));
	memset(dis[time], INF, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	vis[s] = true;
	dis[time][s] = 0;
	cnt[s] = 1;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = false;
		for(int i = 0; i < E[time][u].size(); i++){
			int v = E[time][u][i].v;
			int w = E[time][u][i].w;
			if(dis[time][v] > dis[time][u] + w){
				dis[time][v] = dis[time][u] + w;
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

int main()
{
	while(scanf("%d%d%d", &n, &m, &x)!=EOF){
		int a, b, c;
		while(m--){
			scanf("%d%d%d", &a, &b, &c);
			E[0][a].push_back(Edge(b, c));
			E[1][b].push_back(Edge(a, c));
		}
		spfa(x, n, 0);
		spfa(x, n, 1);
		int ans = 0;
		for(int i = 1; i <= n; i++)
			ans = max(ans, dis[0][i]+dis[1][i]);
		printf("%d\n", ans);
	}

	return 0;
}
