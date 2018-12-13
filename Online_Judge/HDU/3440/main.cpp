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

struct Node{
	int id, height;
	bool operator<(const Node a) const{
		return height < a.height;
	}
}house[N];

int main()
{
    std::ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int T, n, d, kase = 0;
    cin>>T;
    while(T--){
        init();
		cin>>n>>d;
		for(int i = 0; i < n; i++){
		  	cin>>house[i].height;
			house[i].id = i;
		}
		sort(house, house+n);
		//令d[i]表示i到最左边点的距离。
		for(int i = 0; i < n-1; i++){
			// d[i+1] - d[i] >= 1 约束1
			// d[i] - d[i+1] <= -1
			// i+1 -> i : -1
			add_edge(i+1, i, -1);
			// d[v] - d[u] <= d | v > u 约束2
			if(house[i+1].id < house[i].id)
				add_edge(house[i+1].id, house[i].id, d);
			else
			  	add_edge(house[i].id, house[i+1].id, d);
		}
		int s, t;
		//有向边都是 标号小的点  --->  标号大的点（除开边权为-1的边），所以找最短路的时候也要约定从标号小的点到标号大的点
		if(house[0].id < house[n-1].id){
			s = house[0].id;
			t = house[n-1].id;
		}else{
			s = house[n-1].id;
			t = house[0].id;
		}
		cout<<"Case "<<++kase<<": ";
		if(spfa(s, n))
			cout<<dis[t]<<endl;
		else cout<<-1<<endl;
	}

    return 0;
}
