//2017-08-27
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

const int N = 5010;
const int M = N*N;
const double EPS = 1e-6;
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

int n;
struct Point{
	int x, y;
}point[N];

//input: 两个点
//output: 两点间距离
double distance(Point a, Point b){
	return sqrt((double)(a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

//input：radius 半径
//output：true 通过选取某些点可以得到radius的分数，false 无法得到radius的分数
bool check(double radius){
	init();
	for(int i = 0; i < 2*n; i++){
		for(int j = i+1; j < 2*n; j++){
			if((i^1) == j)continue;
			if(distance(point[i], point[j]) < 2*radius){//i与j存在矛盾
				add_edge(i^1, j);// NOT i -> j
				add_edge(j^1, i);// NOT j -> i
			}
		}
	}
	scc(2*n);
	for(int i = 0; i < 2*n; i += 2){
		if(cmp[i] == cmp[i^1])
		  	return false;
	}
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("inputC.txt", "r", stdin);
	while(cin>>n){
		for(int i = 0; i < n; i++){
			cin>>point[2*i].x>>point[2*i].y>>point[2*i+1].x>>point[2*i+1].y;
		}
		double l = 0.0, r = 40000.0, mid, ans = 0;
		while(r-l > EPS){
			mid = (l+r)/2;
			if(check(mid)){
				ans = mid;
				l = mid;
			}else
			  	r = mid;
		}
		cout.setf(ios::fixed);
		cout<<setprecision(2)<<ans<<endl;
	}

	return 0;
}
