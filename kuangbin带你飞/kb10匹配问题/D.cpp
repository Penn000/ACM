//2017-08-21
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 500;
int head[N], tot;
struct Edge{
	int to, next;
	bool fg;//标记该边是否被删除
}edge[N<<2];

void init(){
	tot = 0;
	memset(head, -1, sizeof(head));
}

void add_edge(int u, int v){
	edge[tot].to = v;
	edge[tot].next = head[u];
	edge[tot].fg = 1;
	head[u] = tot++;

	edge[tot].to = u;
	edge[tot].next = head[v];
	edge[tot].fg = 1;
	head[v] = tot++;
}

int n, m, k;
string G[N];
int matching[N];
int check[N];

bool dfs(int u){
	for(int i =  head[u]; i != -1; i = edge[i].next){
		if(!edge[i].fg)continue;
		int v = edge[i].to;
		if(!check[v]){//要求不在交替路
			check[v] = 1;//放入交替路
			if(matching[v] == -1 || dfs(matching[v])){
				//如果是未匹配点，说明交替路为增广路，则交换路径，并返回成功
				matching[u] = v;
				matching[v] = u;
				return true;
			}
		}
	}
	return false;//不存在增广路
}

//hungarian: 二分图最大匹配匈牙利算法
//input: null
//output: ans 最大匹配数
int hungarian(){
	int ans = 0;
	memset(matching, -1, sizeof(matching));
	for(int u = 1; u <= n; u++){
		if(matching[u] == -1){
			memset(check, 0, sizeof(check));
			if(dfs(u))
			  	ans++;
		}
	}
	return ans;
}

int main()
{
	//freopen("inputD.txt", "r", stdin);
	int kase = 0;
	while(scanf("%d%d%d", &n, &m, &k)!=EOF){
		init();
		int u, v;
		while(k--){
			scanf("%d%d", &u, &v);
			add_edge(u, n+v+1);
		}
		int chessmen = hungarian();
		int important = 0;
		for(int u = 1; u <= n; u++){
			for(int i = head[u]; i != -1; i = edge[i].next){
				edge[i].fg = 0;
				edge[i^1].fg = 0;
				if(chessmen != hungarian())	
				  	important++;
				edge[i].fg = 1;
				edge[i^1].fg = 1;
			}
		}
		printf("Board %d have %d important blanks for %d chessmen.\n", ++kase, important, chessmen);
	}

	return 0;
}
