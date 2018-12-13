//2017-08-28
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int N = 5010;
const int M = N*N*2;
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

int n, m;
pair<int, int> key[N], lock[N];

//二分层数
bool check(int deep){
	init();
	for(int i = 0; i < n; i++){
		//add_edge(key[i].first, key[i].second+2*n);
		add_edge(key[i].second+2*n, key[i].first);// NOT v -> u
		//add_edge(key[i].second, key[i].first+2*n);
		add_edge(key[i].first+2*n, key[i].second);// NOT u -> v
	}
	for(int i = 0; i < deep; i++){
		add_edge(lock[i].first, lock[i].second+2*n);// u -> NOT v
		//add_edge(lock[i].second+2*n, lock[i].first);
		add_edge(lock[i].second, lock[i].first+2*n);// v -> NOT u
		//add_edge(lock[i].first+2*n, lock[i].second);
	}
	scc(4*n);
	for(int i = 0; i < 2*n; i++){
		if(cmp[i] == cmp[i+2*n])
		  	return false;
	}
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("inputF.txt", "r", stdin);
	while(cin>>n>>m){
		if(!n && !m)break;
		for(int i = 0; i < n; i++)
		  	cin>>key[i].first>>key[i].second;
		for(int i = 0; i < m; i++)
		  	cin>>lock[i].first>>lock[i].second;
		int l = 0, r = m, mid, ans = 0;
		while(l <= r){
			mid = (l+r)/2;
			if(check(mid)){
				ans = mid;
				l = mid+1;
			}else
			  	r = mid-1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
