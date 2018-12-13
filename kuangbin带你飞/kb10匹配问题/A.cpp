//2017-08-21
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 50;
int head[N], tot;
struct Edge{
	int to, next;
}edge[N<<2];

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

int n;
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
	for(int u = 0; u < n*n; u++){
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
	//freopen("inputA.txt", "r", stdin);
	while(cin>>n && n){
		init();
		for(int i = 0; i < n; i++)
		  	cin>>G[i];
		int id = 0, row_id[5][5], col_id[5][5];
		memset(row_id, -1, sizeof(row_id));
		memset(col_id, -1, sizeof(col_id));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(G[i][j] == '.')row_id[i][j] = id;
				else if(G[i][j] == 'X')id++;
			}
			id++;
		}
		id = n*n;
		for(int j = 0; j < n; j++){
			for(int i = 0; i < n; i++){
				if(G[i][j] == '.')col_id[i][j] = id;
				else if(G[i][j] == 'X')id++;
			}
			id++;
		}
		for(int i = 0; i < n; i++)
		  	for(int j = 0; j < n; j++)
			  	if(row_id[i][j] != -1 && col_id[i][j] != -1)
				  	add_edge(row_id[i][j], col_id[i][j]);
		cout<<hungarian()<<endl;
	}

	return 0;
}
