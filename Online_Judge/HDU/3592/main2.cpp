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
    while(!dq.empty()){
        int u = dq.front();
        dq.pop_front();
        vis[u] = 0;
        for(int i = head[u]; i != -1; i = edge[i].next){
            int v = edge[i].to;
            if(dis[v] > dis[u] + edge[i].w){
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

int main()
{
	std::ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    int T, n, x, y;
    cin>>T;
    while(T--){
		init();
		cin>>n>>x>>y;
		int u, v, w;
		while(x--){
			cin>>u>>v>>w;
			add_edge(u, v, w);
		}
		while(y--){
			cin>>u>>v>>w;
			add_edge(v, u, -w);
		}
		if(spfa(1, n)){
			if(dis[n] == INF)cout<<-2<<endl;
			else cout<<dis[n]<<endl;
		}else cout<<-1<<endl;
    }

    return 0;
}
