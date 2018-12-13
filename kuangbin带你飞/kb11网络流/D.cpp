//2017-08-24
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

const int N = 1000;
const int M = 100000;
const int INF = 0x3f3f3f3f;
int head[N], tot;
struct Edge{
	int to, next, c, w;//c为容量，w为单位费用
}edge[M];

void add_edge(int u, int v, int c, int w){
	edge[tot].c = c;
	edge[tot].w = w;
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;

	edge[tot].c = 0;
	edge[tot].w = -w;
	edge[tot].to = u;
	edge[tot].next = head[v];
	head[v] = tot++;
}

bool vis[N];
int pre[N], dis[N];//pre记录路径，dis记录到源点的最小花费
struct MinCostMaxFlow{
	int S, T;
	int flow, cost;
	void init(int _S, int _T){
		S = _S;
		T = _T;
		tot = 0;
		memset(head, -1, sizeof(head));
	}
	bool spfa(){
		memset(vis, 0, sizeof(vis));
		memset(dis, INF, sizeof(dis));
		dis[S] = 0;
		vis[S] = 1;
		queue<int> que;
		que.push(S);
		while(!que.empty()){
			int u = que.front();
			que.pop();
			for(int i = head[u]; i != -1; i = edge[i].next){
				int v = edge[i].to;
				if(edge[i].c > 0 && dis[v] > dis[u]+edge[i].w){
					dis[v] = dis[u] + edge[i].w;
					pre[v] = i;
					if(!vis[v]){
						vis[v] = true;
						que.push(v);
					}
				}
			}
			vis[u] = 0;
		}
		return dis[T] != INF;
	}
	int dfs(int &flow){
		int u, p, sum = INF, ans = 0;
		for(u = T; u != S; u = edge[p^1].to){
			//记录路径上的最小流值
			p = pre[u];
			sum = min(sum, edge[p].c);
		}
		for(u = T; u != S; u = edge[p^1].to){
			p = pre[u];
			edge[p].c -= sum;
			edge[p^1].c += sum;
			ans += sum*edge[p].w;
		}
		flow += sum;
		return ans;
	}
	int maxflow(){
		cost = 0, flow = 0;
		while(spfa()){//寻找增广路并增广
			cost += dfs(flow);
		}
		return cost;
	}
}mcmf;

string grid[N];
int x[N], y[N];

int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("inputD.txt", "r", stdin);
	int n, m;
	while(cin>>n>>m && (n || m)){
		int cnt_m = 0, cnt_h = 0;
		int s = N-2, t = N-3;
		mcmf.init(s, t);
		for(int i = 0; i < n; i++){
			cin>>grid[i];
			for(int j = 0; j < m; j++){
				if(grid[i][j] == 'H'){
					add_edge(s, cnt_h, 1, 0);
					x[cnt_h] = i;
					y[cnt_h++] = j;
				}
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(grid[i][j] == 'm'){
					add_edge(cnt_h+cnt_m, t, 1, 0);
					for(int k = 0; k < cnt_h; k++){
						add_edge(k, cnt_h+cnt_m, 1, abs(i-x[k])+abs(j-y[k]));
					}
					cnt_m++;
				}
			}
		}
		cout<<mcmf.maxflow()<<endl;
	}

	return 0;
}
