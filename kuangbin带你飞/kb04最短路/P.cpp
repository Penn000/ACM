//2017-08-29
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

const int N = 300100;
const int M = 2500100;
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

int n, m, c;
bool vis[N];
int dis[N], cnt[N];

bool spfa(int s, int n){
	memset(vis, 0, sizeof(vis));
	memset(dis, INF, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	vis[s] = 1;
	dis[s] = 0;
	cnt[s] = 1;
	deque<int> dq;
	dq.push_back(s);
	int sum = 0, len = 1;
	while(!dq.empty()){
		// LLL 优化
		while(dis[dq.front()]*len > sum){
			dq.push_back(dq.front());
			dq.pop_front();
		}
		int u = dq.front();
		sum -= dis[u];
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
					sum += dis[v];
					len++;
					if(++cnt[v] > n)return false;
				}
			}
		}
	}
	return true;
}

bool book[N];
int layer[N];

int main()
{
	//freopen("inputP.txt", "r", stdin);
	int T, kase = 0;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &n, &m, &c);
		init();
		memset(book, 0, sizeof(book));
		for(int i = 1; i <= n; i++){
			scanf("%d", &layer[i]);
			book[layer[i]] = 1;
		}
		for(int i = 1; i <= n; i++){
			add_edge(n+layer[i], i, 0);
			if(layer[i] > 1 && book[layer[i]-1])
			  	add_edge(i, n+layer[i]-1, c);
			if(layer[i] < n && book[layer[i]+1])
			  	add_edge(i, n+layer[i]+1, c);
		}
		for(int i = 1; i < N; i++)
		  if(book[i] && book[i+1]){
			  add_edge(i+n, i+1+n, c);
			  add_edge(i+1+n, i+n, c);
		  }
		int u, v, w;
		while(m--){
			scanf("%d%d%d", &u, &v, &w);
			add_edge(u, v, w);
			add_edge(v, u, w);
		}
		spfa(1, n<<1);
		printf("Case #%d: %d\n", ++kase, dis[n]==INF?-1:dis[n]);
	}

	return 0;
}
