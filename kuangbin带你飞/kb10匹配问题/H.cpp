//2017-08-26
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5000;
const int M = 1000000;
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
	for(int u = 0; u < n; u++){
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
	std::ios::sync_with_stdio(false);
	//freopen("inputH.txt", "r", stdin);
	string str;
	while(cin>>n){
		init();
		int u, k, v;
		for(int i = 0; i < n; i++){
			cin>>str;
			u = 0, k = 0;
			int ptr = 0;
			while(str[ptr] != ':'){
				u *= 10;
				u += str[ptr]-'0';
				ptr++;
			}
			ptr+=2;
			while(str[ptr] != ')'){
				k *= 10;
				k += str[ptr]-'0';
				ptr++;
			}
			for(int j = 0; j < k; j++){
				cin>>v;
				add_edge(u, n+v);
				add_edge(v, n+u);
			}
		}
		cout<<hungarian()/2<<endl;
	}

	return 0;
}
