//2017-08-26
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100000;
const int M = 5000000;
int head[N], tot;
struct Edge{
	int to, next;
}edge[M];

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

const int MAXID = 100;
int a[N], b[N], cnt;

int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("inputE.txt", "r", stdin);
	while(cin>>n){
		init();
		int v;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cin>>v;
				if(v){
					add_edge(i, j+MAXID);
				}
			}
		}
		int match = hungarian();
		if(match != n)cout<<-1<<endl;
		else{
			for(int i = 1; i <= n; i++)
			  	matching[i]-=100;
			cnt = 0;
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					if(i == j)continue;
					if(matching[j] == i){
						swap(matching[i], matching[j]);
						a[cnt] = i;
						b[cnt++] = j;
					}
				}
			}
			cout<<cnt<<endl;
			for(int i = 0; i < cnt; i++)
			  	cout<<"R "<<a[i]<<" "<<b[i]<<endl;
		}
	}

	return 0;
}
