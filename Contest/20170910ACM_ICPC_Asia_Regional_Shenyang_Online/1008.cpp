//2017-09-11
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 110000;
const int INF = 0x3f3f3f3f;
int head[N], tot;
struct Edge{
	int v, w, next;
}edge[N<<2];

void init(){
	tot = 0;
	memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int w){
	edge[tot].v = v;
	edge[tot].w = w;
	edge[tot].next = head[u];
	head[u] = tot++;
}

bool vis[N];
int dis[N];
int cnt[N];
deque<int> dq;
bool spfa(int s, int n){
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i <= n+1; i++)
	  	dis[i] = -INF;
	vis[s] = 1;
	dis[s] = 0;
	cnt[s] = 1;
	deque<int> dq;
	dq.push_back(s);
	while(!dq.empty()){
		int u = dq.front();
		dq.pop_front();
		vis[u] = 0;
		for(int i = head[u]; i != -1; i = edge[i].next){
			int v = edge[i].v;
			if(dis[v] < dis[u] + edge[i].w){
				dis[v] = dis[u] + edge[i].w;
				if(!vis[v]){
					vis[v] = 1;
					dq.push_back(v);
					if(++cnt[v] > n)return false;
				}
			}
		}
	}
	return true;
}

int arr[N], n;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		init();
		int s = 0, t = n+1;
		for(int i = 1; i <= n; i++){
			scanf("%d", &arr[i]);
			add_edge(s, i, -arr[i]);
			add_edge(i, t, arr[i]);
		}
		int u, v, w;
		for(int i = 0; i < n-1; i++){
			scanf("%d%d%d", &u, &v, &w);
			add_edge(u, v, -w);
			add_edge(v, u, -w);
		}
		spfa(s, n);
		printf("%d\n", dis[t]);
	}

	return 0;
}
