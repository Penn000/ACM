#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 55000;
const int M = 120000;

struct Edge{
	int u, v, w;
	bool operator<(const Edge& e) const{
		return w < e.w;
	}
}edge[M];

int n, m;
int fa[N], rk[N], wig[N], vis[N];

int getfa(int x){
	return fa[x] == x ? x : getfa(fa[x]);
}

void merge(int a, int b, int w){
	int af = getfa(a);
	int bf = getfa(b);
	if(af != bf){
		if(rk[af] < rk[bf]){
			fa[af] = bf;
			wig[af] = w;
		}else{
			fa[bf] = af;
			wig[bf] = w;
		}
		if(rk[af] == rk[bf])
		  	rk[af]++;
	}
}

void init(){
	for(int i = 1; i <= n; i++){
		fa[i] = i;
		rk[i] = 0;
		vis[i] = -1;
	}
	for(int i = 0; i < m; i++)
	  	merge(edge[i].u, edge[i].v, edge[i].w);
}

int query(int u, int v){
	int tmp = 0, ans = -1;
	for(int ptr = u; ; ptr = fa[ptr]){
		vis[ptr] = tmp;
		tmp = max(tmp, wig[ptr]);
		if(ptr == fa[ptr])break;
	}
	for(int ptr = v; ; ptr = fa[ptr]){
		if(vis[ptr] >= 0){
			ans = max(ans, vis[ptr]);
			break;
		}
		if(ptr == fa[ptr])break;
		ans = max(ans, wig[ptr]);
	}
	for(int ptr = u; ; ptr = fa[ptr]){
	  	vis[ptr] = -1;
		if(ptr == fa[ptr])break;
	}
	return ans;
}

int main()
{
	int q, u, v;
	while(~scanf("%d%d", &n, &m)){
		for(int i = 0; i < m; i++)
		  	scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
		sort(edge, edge+m);
		init();
		scanf("%d", &q);
		while(q--){
			scanf("%d%d", &u, &v);
			printf("%d\n", query(u, v));
		}
	}

	return 0;
}
