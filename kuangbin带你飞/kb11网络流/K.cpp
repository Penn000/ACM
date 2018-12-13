//2017-08-25
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

const int N = 2000;
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

int T, n, m, d;
string G1[30], G2[30];

int getId(int x, int y, int op){
	if(op == 0)
	  	return x*m+y+1;//柱子入点编号
	else if(op == 1)
	  	return n*m+x*m+y+1;//柱子出点编号
	else
	  	return 2*n*m+x*m+y+1;//蜥蜴编号
}

int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("inputK.txt", "r", stdin);
	cin>>T;
	int kase = 0;
	while(T--){
		cin>>n>>d;
		for(int i = 0; i < n; i++)
		  	cin>>G1[i];
		for(int i = 0; i < n; i++)
		  	cin>>G2[i];
		m = G1[0].length();
		int s = 0, t = 3*n*m+1;
		dinic.init(s, t);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(G1[i][j] != '0'){
					add_edge(getId(i, j, 0), getId(i, j, 1), G1[i][j]-'0');
					for(int dx = -d; dx <= d; dx++){
						for(int dy = -d; dy <= d; dy++){
							if(!dx && !dy)continue;
							int nx = i + dx;
							int ny = j + dy;
							if(abs(dx)+abs(dy) > d)continue;
							if(nx<0 || nx>=n || ny<0 || ny>=m){
								add_edge(getId(i, j, 1), t, INF);//跳出边界，与汇点连边
								continue;
							}
							if(G1[nx][ny]!='0'){
								add_edge(getId(i, j, 1), getId(nx, ny, 0), INF);//跳到下一根柱子，本跳出点与下跳入点连边
							}
						}
					}
				}
			}
		}
		int cnt = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(G2[i][j] == 'L'){
					cnt++;
					add_edge(s, getId(i, j, 2), INF);
					add_edge(getId(i, j, 2), getId(i, j, 0), 1);//蜥蜴向所在柱子入点连边，容量为1，INF则WA
				}
			}
		}
		int ans = dinic.maxflow();
		if(cnt-ans > 1)
		  	cout<<"Case #"<<++kase<<": "<<cnt-ans<<" lizards were left behind."<<endl;
		else if(cnt-ans == 1)
		  	cout<<"Case #"<<++kase<<": "<<cnt-ans<<" lizard was left behind."<<endl;
		else
		  	cout<<"Case #"<<++kase<<": no lizard was left behind."<<endl;

	}
	return 0;
}
