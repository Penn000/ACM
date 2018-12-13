//2017-11-16
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110000;
const int M = 220000;

namespace DSU{
	int fa[N];
	void init(){
		for(int i = 1; i < N; i++)fa[i] = i;
	}
	int getfa(int x){
		return fa[x] = x == fa[x] ? x : getfa(fa[x]);
	}
	void merge(int a, int b){
		int af = getfa(a);
		int bf = getfa(b);
		if(af != bf){
			fa[bf] = af;
		}
	}
}

struct Edge{
	int u, v, w;
	bool operator< (const Edge e) const {
		return w > e.w;
	}
}edge[M];

int main()
{
	freopen("input.txt", "r", stdin);
	int n, m, x, y;
	while(~scanf("%d%d", &n, &m)){
		for(int i = 0; i < n; i++)
		  scanf("%d%d", &x, &y);
		int ans = 0;
		for(int i = 0; i < m; i++){
		  scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
		  ans += edge[i].w;
		}
		DSU::init();
		sort(edge, edge+m);
		int cnt = 0;
		for(int i = 0; i < m; i++){
			int u = edge[i].u;
			int v = edge[i].v;
			if(DSU::getfa(u) != DSU::getfa(v)){
				ans -= edge[i].w;
				DSU::merge(u, v);
				cnt++;
			}
		}
		printf("%d %d\n", m-cnt, ans);
	}

	return 0;
}
