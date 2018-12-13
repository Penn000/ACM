//2017-08-20
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;
const int M = 200010;
int head[N], tot;
struct Edge{
	int to, next;
}edge[M<<1];

void init(){
	tot = 0;
	memset(head, -1, sizeof(head));
}

void add_edge(int u, int v){
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;

	edge[tot].to = u;
	edge[tot].next = head[v];
	head[v] = tot++;
}

int n, m, deep, ans;
int dfn[N];//dfn[u]记录节点u在DFS过程中被遍历到的次序号
int low[N]; //low[u]记录节点u或u的子树通过非父子边追溯到最早的祖先节点(即DFS次序号最小)
int fa[N];//保存dfs树的信息
int level[N];//记录节点在dfs树中的深度
int bridge[N];//记录割边，若bridge[u] == 1, 则<u, fa[u]>为一条割边

void tarjan(int u, int father){
	fa[u] = father;
	dfn[u] = low[u] = deep++;
	level[u] = level[father]+1;
	for(int i = head[u]; i != -1; i = edge[i].next){
		int v = edge[i].to;
		if(dfn[v] == -1){
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] > dfn[u]){
				bridge[v] = 1;
				ans++;
			}
		}else if(v != father)
		  	low[u] = min(low[u], dfn[v]);
	}
}

void lca(int a, int b){
	while(level[a] > level[b]){
		if(bridge[a]){
			ans--;
			bridge[a] = 0;
		}
		a = fa[a];
	}
	while(level[b] > level[a]){
		if(bridge[b]){
			ans--;
			bridge[b] = 0;
		}
		b = fa[b];
	}
	while(a != b){
		if(bridge[a]){
			ans--;
			bridge[a] = 0;
		}
		if(bridge[b]){
			ans--;
			bridge[b] = 0;
		}
		a = fa[a];
		b = fa[b];
	}
}

void debug(){
	cout<<"fa: ";
	for(int i = 0; i <= n; i++){
		cout<<fa[i]<<" ";
	}
	cout<<endl;
	cout<<"dfn: ";
	for(int i = 0; i <= n; i++){
		cout<<dfn[i]<<" ";
	}
	cout<<endl;
	cout<<"low: ";
	for(int i = 0; i <= n; i++){
		cout<<low[i]<<" ";
	}
	cout<<endl;
	cout<<"bg: ";
	for(int i = 0; i <= n; i++){
		cout<<bridge[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	freopen("inputD.txt", "r", stdin);
	int kase = 0;
	while(scanf("%d%d", &n, &m)!=EOF && (n || m)){
		printf("Case %d:\n", ++kase);
		init();
		int u, v;
		for(int i = 0; i < m; i++){
			scanf("%d%d", &u, &v);
			add_edge(u, v);
		}
		memset(bridge, 0, sizeof(bridge));
		memset(dfn, -1, sizeof(dfn));
		memset(low, 0, sizeof(low));
		level[0] = 0;
		deep = 0;
		tarjan(1, 0);
		debug();
		int q;
		scanf("%d", &q);
		while(q--){
			scanf("%d%d", &u, &v);
			if(ans)lca(u, v);
			printf("%d\n", ans);
		}
		printf("\n");
	}

	return 0;
}
