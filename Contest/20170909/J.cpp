#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>

using namespace std;

const int N = 50000;
const int INF = 0x3f3f3f3f;

int head[N], tot;
struct Edge{
	int v, w, next;
}edge[N];

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

map<string, int> mp;
map<string, int>::iterator iter;

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
			int v = edge[i].v;
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

struct Node{
	int v, w, dis;
	Node(int _v, int _w, int _dis):v(_v), w(_w), dis(_dis){}
	bool operator<(const Node& x) const {
		return dis < x.dis;
	}
};
int dl, sh, xa, ans;
bool fg, ok;
vector<Node> vec[N];
void dfs(int u){
	if(ok)return;
	if(u == xa && fg){
		ok = 1;
		cout<<ans<<endl;
		return;
	}
	while(!vec[u].empty())vec[u].pop_back();
	for(int i = head[u]; i != -1; i = edge[i].next){
		int v = edge[i].v, w = edge[i].w;
		if(vis[v])continue;
		vec[u].push_back(Node(v, w, dis[v]));
	}
	sort(vec[u].begin(), vec[u].end());
	for(auto &node: vec[u]){
		int v = node.v, w = node.w;
		vis[v] = 1;
		if(v == sh)fg = true;
		ans += w;
		dfs(v);
		ans -= w;
		vis[v] = 0;
		fg = false;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int m;
		cin>>m;
		string str1, str2;
		int idx = 0;
		mp.clear();
		init();
		int u, v, w;
		int sh_du = 0;
		while(m--){
			cin>>str1>>str2>>w;
			if(str1 == "Shanghai")sh_du++;
			if(str2 == "Shanghai")sh_du++;
			iter = mp.find(str1);
			if(iter == mp.end()){
				u = idx;
				mp[str1] = idx++;
			}else u = iter->second;
			iter = mp.find(str2);
			if(iter == mp.end()){
				v = idx;
				mp[str2] = idx++;
			}else v = iter->second;
			add_edge(u, v, w);
			add_edge(v, u, w);
			//cout<<u<<" -> "<<v<<" "<<w<<endl;
		}	
		if(sh_du <= 1){
			cout<<-1<<endl;
			continue;
		}
		sh = mp["Shanghai"];
		dl = mp["Dalian"];
		xa = mp["Xian"];
		spfa(dl, idx);
		ans = 0;
		ok = false;
		fg = false;
		memset(vis, 0, sizeof(vis));
		vis[dl] = 1;
		dfs(dl);
		if(!ok)cout<<-1<<endl;
	}

	return 0;
}
