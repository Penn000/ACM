//2017-09-16
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 110000;
int head[N], tot;
struct Edge{
	int v, next;
}edge[N];

void init(){
	tot = 0;
	memset(head, -1, sizeof(head));
}

void add_edge(int u, int v){
	edge[tot].v = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}

int n, q, arr[N];
int ans[N];
vector< pair<int, int> > qy[N];
struct Trie{
	Trie* next[2];
}*root[N];

void insert(Trie* rt, int x){
	for(int i = 31; i >= 0; i--){
		int idx = (x>>i)&1;
		if(rt->next[idx] == NULL){
			Trie *tmp = new Trie();
			rt->next[idx] = tmp;
		}
		rt = rt->next[idx];
	}
}

int query(Trie* rt, int x){
	int ans = 0;
	for(int i = 31; i >= 0; i--){
		int idx = (x>>i)&1;
		if(rt->next[idx^1] != NULL){
			rt = rt->next[idx^1];
			ans |= (1<<i);
		}else rt = rt->next[idx];
	}
	return ans;
}

Trie* merge(Trie* p, Trie* q){
	if(p == NULL)return q;
	if(q == NULL)return p;
	p->next[0] = merge(p->next[0], q->next[0]);
	p->next[1] = merge(p->next[1], q->next[1]);
	free(q);
	return p;
}

void dfs(int u, int fa){
	root[u] = new Trie();
	insert(root[u], arr[u]);
	for(int i = head[u]; i != -1; i = edge[i].next){
		int v = edge[i].v;
		if(v == fa)continue;
		dfs(v, u);
		root[u] = merge(root[u], root[v]);
	}
	for(auto &q: qy[u]){
		ans[q.first] = query(root[u], q.second);
	}
}

void clear(Trie* rt){
	if(rt->next[0]) clear(rt->next[0]);
	if(rt->next[1]) clear(rt->next[1]);
	free(rt);
}

int main()
{
	while(scanf("%d%d", &n, &q) != EOF){
		init();
		for(int i = 1; i <= n; i++){
		  scanf("%d", &arr[i]);
		  qy[i].clear();
		}
		int v;
		for(int i = 2; i <= n; i++){
			scanf("%d", &v);
			add_edge(v, i);
		}
		int u, x;
		for(int i = 0; i < q; i++){
			scanf("%d%d", &u, &x);
			qy[u].push_back(make_pair(i, x));
		}
		dfs(1, -1);
		for(int i = 0; i < q; i++)
		  	printf("%d\n", ans[i]);
		clear(root[1]);
	}

	return 0;
}
