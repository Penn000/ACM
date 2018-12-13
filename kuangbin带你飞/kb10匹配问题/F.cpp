//2017-08-26
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100000;
const int M = 20000000;
const int INF = 0x3f3f3f3f;
int head[N], tot;
struct Edge{
	int to, next;
}edge[M];


void add_edge(int u, int v){
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}

//xlink[i]表示左集合顶点i匹配的右集合的点，ylink[i]表示右集合顶点i匹配的左集合的点
int xlink[N], ylink[N];
//xlevel[i]表示左集合顶点i的所在层数，ylevel[i]表示右集合顶点i的所在层数
int xlevel[N], ylevel[N];
bool vis[N];
struct Hopcroft_Karp{
	int dis, xn, yn;//xn表示左集合顶点个数，yn表示右集合顶点个数
	void init(int _xn, int _yn){
		tot = 0;
		xn = _xn;
		yn = _yn;
		memset(head, -1, sizeof(head));
		memset(xlink, -1, sizeof(xlink));
		memset(ylink, -1, sizeof(ylink));
	}
	bool bfs(){
		queue<int> que;
		dis = INF;
		memset(xlevel, -1, sizeof(xlevel));
		memset(ylevel, -1, sizeof(ylevel));
		for(int i = 0; i < xn; i++)
			if(xlink[i] == -1){
				que.push(i);
				xlevel[i] = 0;
			}
		while(!que.empty()){
			int u = que.front();
			que.pop();
			if(xlevel[u] > dis)break;
			for(int i = head[u]; i != -1; i = edge[i].next){
				int v = edge[i].to;
				if(ylevel[v] == -1){
					ylevel[v] = xlevel[u] + 1;
					if(ylink[v] == -1)
					  	dis = ylevel[v];
					else{
						xlevel[ylink[v]] = ylevel[v]+1;
						que.push(ylink[v]);
					}
				}
			}
		}
		return dis != INF;
	}
	int dfs(int u){
		for(int i = head[u]; i != -1; i = edge[i].next){
			int v = edge[i].to;
			if(!vis[v] && ylevel[v] == xlevel[u]+1){
				vis[v] = 1;
				if(ylink[v] != -1 && ylevel[v] == dis)
				  	continue;
				if(ylink[v] == -1 || dfs(ylink[v])){
					xlink[u] = v;
					ylink[v] = u;
					return 1;
				}
			}
		}
		return 0;
	}
	//二分图最大匹配
	//input：建好的二分图
	//output：ans 最大匹配数
	int max_match(){
		int ans = 0;
		while(bfs()){
			memset(vis, 0, sizeof(vis));
			for(int i = 0; i < xn; i++)
			  	if(xlink[i] == -1)
				  	ans += dfs(i);
		}
		return ans;
	}
}hk_match;

int n, m, pour_time;
struct Guests{
	int x, y, speed;
}guests[N];

struct Umbrella{
	int x, y;
}umbrella[N];

bool getUmbrella(int i, int j){
	return (guests[i].x-umbrella[j].x)*(guests[i].x-umbrella[j].x)
		+ (guests[i].y-umbrella[j].y)*(guests[i].y-umbrella[j].y)
		<= guests[i].speed*guests[i].speed*pour_time*pour_time;
}

int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("inputF.txt", "r", stdin);
	int T, kase = 0;
	cin>>T;
	while(T--){
		cin>>pour_time>>m;
		for(int i = 0; i < m; i++)
		  cin>>guests[i].x>>guests[i].y>>guests[i].speed;
		cin>>n;
		for(int i = 0; i < n; i++)
		  cin>>umbrella[i].x>>umbrella[i].y;
		hk_match.init(m, n);
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				if(getUmbrella(i, j))
					add_edge(i, j);
		cout<<"Scenario #"<<++kase<<":"<<endl<<hk_match.max_match()<<endl<<endl;
	}

	return 0;
}
