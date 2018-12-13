//2017-08-26
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 5010;
const int M = N*N;
int head[N], rhead[N], tot, rtot;
struct Edge{
	int to, next;
}edge[M], redge[M];

void init(){
	tot = 0;
	rtot = 0;
	memset(head, -1, sizeof(head));
	memset(rhead, -1, sizeof(rhead));
}

void add_edge(int u, int v){
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;

	redge[rtot].to = u;
	redge[rtot].next = rhead[v];
	rhead[v] = rtot++;
}

vector<int> vs;//后序遍历顺序的顶点列表
bool vis[N];
int cmp[N];//所属强连通分量的拓扑序

//input: u 顶点
//output: vs 后序遍历顺序的顶点列表
void dfs(int u){
	vis[u] = true;
	for(int i = head[u]; i != -1; i = edge[i].next){
		int v = edge[i].to;
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
	for(int i = rhead[u]; i != -1; i = redge[i].next){
		int v = redge[i].to;
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
	for(int i = 0; i < n; i++){
		if(cmp[i] == cmp[i+n]){//a和NOT a在同一个强连通分量中，布尔方程无解
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;//布尔方程有解
	return;
}

int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("inputA.txt", "r", stdin);
	int n, m;
	while(cin>>n>>m){
		init();
		int u, v, a, b;
		for(int i = 0; i < m; i++){
			cin>>u>>v>>a>>b;
			if(a == 0 && b == 0){// u && v
				add_edge(u+n, v);// NOT u -> v
				add_edge(v+n, u);// NOT v -> u
			}else if(a == 0 && b == 1){// u && NOT v
				add_edge(u+n, v+n);// NOT u -> NOT v
				add_edge(v, u);// v -> u
			}else if(a == 1 && b == 0){// NOT u && v
				add_edge(u, v);// u -> v
				add_edge(v+n, u+n);// NOT v -> NOT u
			}else if(a == 1 && b == 1){// NOT u && NOT v
				add_edge(u, v+n);// u -> NOT v
				add_edge(v, u+n);// v -> NOT u
			}
		}
		scc(n<<1);
		solve(n);
	}

	return 0;
}
