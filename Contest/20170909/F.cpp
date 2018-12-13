//2017-08-20
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int N = 11000;
int n, m, in_degree[N], out_degree[N];
bool vis[N];
vector<int> G[N];
vector<int> rG[N];
vector<int> vs;
int cmp[N];

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
int scc(){
	memset(vis, 0, sizeof(vis));
	vs.clear();
	for(int u = 1; u <= n; u++)
	  if(!vis[u]){
		  dfs(u);

	  }
	int k = 0;
	memset(vis, 0, sizeof(vis));
	for(int i = vs.size()-1; i >= 0; i--)
	  if(!vis[vs[i]])
		rdfs(vs[i], k++);
	return k;

}

void solve(){
	int k = scc();
	int ans = 0;
	memset(in_degree, 0, sizeof(in_degree));
	memset(out_degree, 0, sizeof(out_degree));
	for(int u = 1; u <= n; u++){
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i];
			if(vis[v])continue;
			vis[v] = 1;
			if(cmp[u] != cmp[v]){
				out_degree[cmp[u]]++;
				in_degree[cmp[v]]++;

			}

		}

	}
	int a = 0, b = 0;
	for(int i = 0; i < k; i++){
		if(in_degree[i] == 0)a++;
		if(out_degree[i] == 0)b++;

	}
	ans = max(a, b);
	if(k == 1)ans = 0;
	printf("%d\n", ans);

}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		for(int u = 1; u <= n; u++){
			G[u].clear();
			rG[u].clear();

		}
		int u, v;
		for(int i = 0; i < m; i++){
				scanf("%d%d", &u, &v);
				add_edge(u, v);
		}
		solve();
	}

	return 0;
}
