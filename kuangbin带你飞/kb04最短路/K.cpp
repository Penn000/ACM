//2017-08-29
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

const int N = 50010;
const int M = 250010;
const int INF = 0x3f3f3f3f;

int head[N], tot;
struct Edge{
	int to, next, w;
}edge[M];

void init(){
	tot = 0;
	memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int w){
	edge[tot].w = w;
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}

int n, m;
bool vis[N];
int dis[N], cnt[N];
/*
bool spfa(int s, int n){
	memset(vis, 0, sizeof(vis));
	memset(dis, INF, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	vis[s] = 1;
	dis[s] = 0;
	cnt[s] = 1;
	deque<int> dq;
	dq.push_back(s);
	int avg = 0, len = 1;
	while(!dq.empty()){
		// LLL 优化
		while(dis[dq.front()] > avg){
			dq.push_back(dq.front());
			dq.pop_front();
		}
		int u = dq.front();
		avg = len == 1 ? 0 : (avg*len-dis[u])/(len-1);
		len--;
		dq.pop_front();
		vis[u] = 0;
		for(int i = head[u]; i != -1; i = edge[i].next){
			int v = edge[i].to;
			if(dis[v] > dis[u] + edge[i].w){
				dis[v] = dis[u] + edge[i].w;
				if(!vis[v]){
					vis[v] = 1;
					// SLF 优化
					if(!dq.empty() && dis[v] < dis[dq.front()])
					  	dq.push_front(v);
					else dq.push_back(v);
					avg = (avg*len+dis[v])/(len+1);
					len++;
					if(++cnt[v] > n)return false;
				}
			}
		}
	}
	return true;
}
*/
int sk[N], top;
bool spfa(int s, int n){
	for(int i = 1; i <= n; i++){
		vis[i] = 0;
		cnt[i] = 0;
		dis[i] = INF;
	}
	vis[s] = 1;
	dis[s] = 0;
	cnt[s] = 1;
	top = 0;
	sk[top++] = s;
	while(top){
		int u = sk[--top];
		vis[u] = 0;
		for(int i = head[u]; i != -1; i = edge[i].next){
			int v = edge[i].to;
			if(dis[v] > dis[u] + edge[i].w){
				dis[v] = dis[u] + edge[i].w;
				if(!vis[v]){
					vis[v] = 1;
					sk[top++] = v;
					if(++cnt[v] > n)return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	//freopen("inputK.txt", "r", stdin);
	while(scanf("%d%d", &n, &m)!=EOF){
		init();
		int u, v, w;
		while(m--){
			scanf("%d%d%d", &u, &v, &w);
			add_edge(u, v, w);
		}
		spfa(1, n);
		printf("%d\n", dis[n]);
	}

	return 0;
}
