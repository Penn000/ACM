//2017-08-20
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 10010;
vector<int> G[N];//邻接表存图
vector<int> rG[N];//存反向图
vector<int> vs;//后序遍历顺序的顶点列表
bool vis[N];
int cmp[N];//所属强连通分量的拓扑序

void add_edge(int u, int v){
	G[u].push_back(v);
	rG[v].push_back(u);
}

//input: u 顶点
//output: vs 后序遍历顺序的顶点列表
void dfs(int u){
	vis[u] = true;
	for(int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		if(!vis[v])
		  	dfs(v);
	}
	vs.push_back(u);
}

//input: u 顶点编号; k 拓扑序号
//output: cmp[] 强连通分量拓扑序
void rdfs(int u, int k){
	vis[u] = true;
	cmp[u] = k;
	for(int i = 0; i < rG[u].size(); i++){
		int v = rG[u][i];
		if(!vis[v])
		  	rdfs(v, k);
	}
}

//Strongly Connected Component 强连通分量
//input: n 顶点个数
//output: k 强连通分量数;
int scc(int n){
	memset(vis, 0, sizeof(vis));
	vs.clear();
	for(int u = 0; u < n; u++)
		if(!vis[u])
		  	dfs(u);
	int k = 0;
	memset(vis, 0, sizeof(vis));
	for(int i = vs.size()-1; i >= 0; i--)
	  	if(!vis[vs[i]])
		  	rdfs(vs[i], k++);
	return k;
}

void solve(int n){
	int k = scc(n);
	int u = 0, ans = 0;
	for(int v = 0; v < n; v++){
		if(cmp[v] == k-1){
			u = v;
			ans++;
		}
	}
	memset(vis, 0, sizeof(vis));
	rdfs(u, 0);
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			ans = 0;
			break;
		}
	}
	printf("%d\n", ans);
}

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m)!=EOF){
		int u, v;
		for(int i = 0; i < n; i++){
			G[i].clear();
			rG[i].clear();
		}
		while(m--){
			scanf("%d%d", &u, &v);
			u--; v--;
			add_edge(u, v);
		}
		solve(n);
	}

	return 0;
}
