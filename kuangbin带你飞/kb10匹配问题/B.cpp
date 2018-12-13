//2017-08-21
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 210;
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

int n, m;
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
	for(int u = 1; u <= n; u++){
		if(matching[u] == -1){
			memset(check, 0, sizeof(check));
			if(dfs(u))
			  ans++;
		}
	}
	return ans;
}

int col[N];

//color: 黑白染色二分图判定
//output: true 是二分图, false 不是二分图
bool color(int u){
	for(int i = head[u]; i != -1; i = edge[i].next){
		int v = edge[i].to;
		if(!col[v]){
			col[v] = !col[u];
			if(!color(v))return false;
		}else if(col[v] == col[u])
		  	return false;
	}
	return true;
}

int main()
{
	//freopen("inputB.txt", "r", stdin);
	while(scanf("%d%d", &n, &m)!=EOF){
		//考虑只有一个人时的特殊情况
		if(n == 1){
			printf("No\n");
			continue;
		}
		init();
		int u, v;
		for(int i = 0; i < m; i++){
			scanf("%d%d", &u, &v);
			add_edge(u, v);
		}
		memset(col, 0, sizeof(col));
		col[1] = 1;
		if(color(1))
			printf("%d\n", hungarian());
		else
		  	printf("No\n");
	}

	return 0;
}
