//2017-08-28
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int N = 5010;
const int M = N*N*2;
int head[N], rhead[N], tot, rtot;
struct Edge{
	int to, next;
}edge[M], redge[M];

void init(){
	tot = 0;
	rtot = 0;
	memset(head, -1, sizeof(head));
	memset(rhead, -1, sizeof(rhead));
}

void add_edge(int u, int v){
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;

	redge[rtot].to = u;
	redge[rtot].next = rhead[v];
	rhead[v] = rtot++;
}

vector<int> vs;//后序遍历顺序的顶点列表
bool vis[N];
int cmp[N];//所属强连通分量的拓扑序

//input: u 顶点
//output: vs 后序遍历顺序的顶点列表
void dfs(int u){
	vis[u] = true;
	for(int i = head[u]; i != -1; i = edge[i].next){
		int v = edge[i].to;
		if(!vis[v])
		  dfs(v);
	}
	vs.push_back(u);
}

//input: u 顶点编号; k 拓扑序号
//output: cmp[] 强连通分量拓扑序
void rdfs(int u, int k){
	vis[u] = true;
	cmp[u] = k;
	for(int i = rhead[u]; i != -1; i = redge[i].next){
		int v = redge[i].to;
		if(!vis[v])
		  rdfs(v, k);
	}
}

//Strongly Connected Component 强连通分量
//input: n 顶点个数
//output: k 强连通分量数;
int scc(int n){
	memset(vis, 0, sizeof(vis));
	vs.clear();
	for(int u = 0; u < n; u++)
	  if(!vis[u])
		dfs(u);
	int k = 0;
	memset(vis, 0, sizeof(vis));
	for(int i = vs.size()-1; i >= 0; i--)
	  if(!vis[vs[i]])
		rdfs(vs[i], k++);
	return k;
}

int n, A, B, dis_s1[N], dis_s2[N], dis_s1_s2;
struct Point{
	int x, y;
}point[N], s1, s2, hate[N], friends[N];

//input: 两个点
//output: 两点间距离
double distance(Point a, Point b){
	return abs(a.x-b.x) + abs(a.y-b.y);
}

bool check(int limit){
	init();
	// i 表示 i 连 s1， NOT i 表示 i 连 s2
	for(int i = 0; i < n; i++){
		bool fg = true;
		if(distance(point[i], s1) > limit){
		  	add_edge(i, i+n);
			fg = false;
		}
		if(distance(point[i], s2) > limit){
			if(!fg)return false;
		  	add_edge(i+n, i);
		}
		for(int j = i+1; j < n; j++){
			if(dis_s1[i] + dis_s1[j] > limit){
				add_edge(i, j+n);// i -> s1, j -> s2
				add_edge(j, i+n);// j -> s1, i -> s2
			}
			if(dis_s2[i] + dis_s2[j] > limit){
				add_edge(i+n, j);// i -> s2, j -> s1
				add_edge(j+n, i);// j -> s2, i -> s1
			}
			if(dis_s1[i] + dis_s1_s2 + dis_s2[j] > limit){
				add_edge(i, j);// i -> s1, j -> s1
				add_edge(j+n, i+n);// j -> s2, i -> s2
			}
			if(dis_s2[i] + dis_s1_s2 + dis_s1[j] > limit){
				add_edge(i+n, j+n);// i -> s2, j -> s2
				add_edge(j, i);// j -> s1, i -> s1
			}
		}
	}
	for(int i = 0; i < A; i++){
		int u = hate[i].x, v = hate[i].y;
		add_edge(u, v+n);
		add_edge(v+n, u);
		add_edge(v, u+n);
		add_edge(u+n, v);
	}
	for(int i = 0; i < B; i++){
		int u = friends[i].x, v = friends[i].y;
		add_edge(u, v);
		add_edge(v, u);
		add_edge(u+n, v+n);
		add_edge(v+n, u+n);
	}
	scc(2*n);
	for(int i = 0; i < n; i++){
		if(cmp[i] == cmp[i+n])
		  	return false;
	}
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("inputE.txt", "r", stdin);
	while(cin>>n>>A>>B){
		cin>>s1.x>>s1.y>>s2.x>>s2.y;
		dis_s1_s2 = distance(s1, s2);
		for(int i = 0; i < n; i++){
		  	cin>>point[i].x>>point[i].y;
			dis_s1[i] = distance(point[i], s1);
			dis_s2[i] = distance(point[i], s2);
		}
		for(int i = 0; i < A; i++){
		  	cin>>hate[i].x>>hate[i].y;
			hate[i].x--;
			hate[i].y--;
		}
		for(int i = 0; i < B; i++){
			cin>>friends[i].x>>friends[i].y;
			friends[i].x--;
			friends[i].y--;
		}
		//r 开小了HDU会TLE，ORZ。。。
		int l = 0, r = 8000000, mid, ans = -1;
		while(l <= r){
			mid = (l+r)/2;
			if(check(mid)){
				ans = mid;
				r = mid-1;
			}else l = mid+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
