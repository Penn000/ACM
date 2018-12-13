//2017-09-01
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define lson (id<<1)
#define rson ((id<<1)|1)

using namespace std;

const int N = 510000;

int head[N], tot;
struct Edge{
	int to, next;
}edge[N<<2];

void init(){
	tot = 0;
	memset(head, -1, sizeof(head));
}

void add_edge(int u, int v){
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}

int in[N], out[N], fa[N], cnt;
void dfs(int u, int father){
	in[u] = ++cnt;
	for(int i = head[u]; i != -1; i = edge[i].next){
		int v = edge[i].to;
		if(v != father){
			fa[v] = u;
			dfs(v, u);
		}
	}
	out[u] = cnt;
}

bool flag;
struct Node{
	int l, r, value, lazy;
}tree[N<<2];

void build(int id, int l, int r){
	tree[id].l = l;
	tree[id].r = r;
	tree[id].value = 0;
	tree[id].lazy = 0;
	if(l == r)return;
	int mid = (tree[id].l+tree[id].r)>>1;
	build(lson, l, mid);
	build(rson, mid+1, r);
}

void push_up(int id){
	if(tree[lson].value && tree[rson].value)tree[id].value = 1;
	else tree[id].value = 0;
}

void push_down(int id){
	if(tree[id].lazy){
		tree[lson].value = tree[rson].value = tree[id].lazy;
		tree[lson].lazy = tree[rson].lazy = tree[id].lazy;
		tree[id].lazy = 0;
	}
}

void update(int id, int l, int r, int op){
	if(l == 0)return;
	if(l <= tree[id].l && tree[id].r <= r){
		if(tree[id].value == 0)flag = 0;
		tree[id].value = op;
		if(op == 1)tree[id].lazy = op;
		return;
	}
	push_down(id);
	int mid = (tree[id].l+tree[id].r)>>1;
	if(l <= mid)update(lson, l, r, op);
	if(r > mid)update(rson, l, r, op);
	push_up(id);
}

void query(int id, int l, int r){
	if(l <= tree[id].l && tree[id].r <= r){
		if(tree[id].value == 0)flag = 0;
		return;
	}
	push_down(id);
	int mid = (tree[id].l+tree[id].r)>>1;
	if(l <= mid)query(lson, l, r);
	if(r > mid)query(rson, l, r);
}

int n, q;

int main()
{
	freopen("inputF.txt", "r", stdin);
	while(scanf("%d", &n) != EOF){
		init();
		int u, v;
		for(int i = 0; i < n-1; i++){
			scanf("%d%d", &u, &v);
			add_edge(u, v);
			add_edge(v, u);
		}
		fa[1] = 0;
		cnt = 0;
		dfs(1, 0);
		build(1, 1, n);
		scanf("%d", &q);
		while(q--){
			scanf("%d%d", &u, &v);
			if(u == 1){
				flag = 1;
				update(1, in[v], out[v], 1);
				if(!flag)update(1, in[fa[v]], in[fa[v]], 0);
			}else if(u == 2){
				update(1, in[v], in[v], 0);
			}else{
				flag = 1;
				query(1, in[v], out[v]);
				if(flag)printf("1\n");
				else printf("0\n");
			}
		}
	}

	return 0;
}
