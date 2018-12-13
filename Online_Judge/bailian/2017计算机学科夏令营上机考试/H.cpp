#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const N = 500;

struct Edge{
	int to, next;
	double w;
}edges[N*N];

int head[N], tot, cnt;

void init(){
	tot = 0;
	memset(head, -1, sizeof(head));
}

void add_edge(int u , int v, double w){
	edges[tot].to = v;
	edges[tot].w = w;
	edges[tot].next = head[u];
	head[u] = tot++;
}

int xx[2], yy[2];
void read_a_line(){
	bool fg = 0, begin = false;
	while(scanf("%d%d", &xx[fg], &yy[fg])){
		if(xx[fg] == -1 && yy[fg] == -1)break;
		if(!begin)begin = true;
		else{
			double dist = sqrt((xx[fg]-xx[!fg])*(xx[fg]-xx[!fg]) + (yy[fg]-yy[!fg])*(yy[fg]-yy[!fg]));
			add_edge(cnt, cnt+1, dist);
			add_edge(cnt+1, cnt, dist);
			cnt++;
			fg = !fg;
		}
	}
}

const int INF = 0x3f3f3f3f;
double dist[N];
bool vis[N];
void dijkstra(int s, int t){
	for(int i = 0; i < cnt; i++){
		dist[i] = INF*1.0;
	}
	memset(vis, 0, sizeo(vis));
	dist[s] = 0;
	vis[s] = 1;
	
	int mindist;
	for(int i = 0; i < cnt-1; i++){

	}

}

int main()
{
	int sx, sy, ex, ey;
	while(~scanf("%d%d%d%d", &sx, &sy, &ex, &ey)){
		init();
		cnt = 0;
		
	}

	return 0;
}
