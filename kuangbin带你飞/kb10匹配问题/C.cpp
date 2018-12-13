//2017-08-21
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int p, n;
const int N = 1010;
int head[N], tot;
struct Edge{
	int to, next;
}edge[N*N];

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

string G[N];
int matching[N];
int check[N];

bool dfs(int u){
	for(int i =  head[u]; i != -1; i = edge[i].next){
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
	for(int u = 0; u < p; u++){
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
	//freopen("inputC.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &p, &n);
		init();
		int m, v;
		for(int i = 0; i < p; i++){
			scanf("%d", &m);
			while(m--){
				scanf("%d", &v);
				add_edge(i, p+v);
			}
		}
		int ans = hungarian();
		if(ans < p)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
