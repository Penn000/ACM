//2017-08-25
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

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

int n, m;

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("inputF.txt", "r", stdin);
	while(cin>>n>>m && (n||m)){
		int u, v;
		for(int i = 0; i < m; i++){
			cin>>u>>v;
		}
	}
	return 0;
}
