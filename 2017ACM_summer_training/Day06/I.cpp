//2017-09-05
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
#define lson (id<<1)
#define rson ((id<<1)|1)
#define mid ((tree[id].l+tree[id].r)>>1)
using namespace std;

const int N  = 110000;
const int M = 1020;
int n, m;
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

//dfn记录dfs序，in[u]~out[u]的区间表示以u为根的子树。
int in[N], out[N], idx, dfn[N];
void dfs(int u, int fa){
	in[u] = ++idx;
	dfn[idx] = u;
	for(int i = head[u]; i != -1; i = edge[i].next){
		int v = edge[i].to;
		if(v != fa)	
		  	dfs(v, u);
	}
	out[u] = idx;
}

int arr[N];
bitset<M> prime;
bool is_prime(int x){
	for(int i = 2; i*i <= x; i++)
	  	if(x%i == 0)return false;
	return true;
}

void init_prime(){
	prime.reset();
	for(int i = 2; i < m; i++)
	  	if(is_prime(i))
		  	prime.set(i);
}

struct Node{
	int l, r, lazy;
	bitset<M> value;//value记录该区间内%m的余数的集合
}tree[N<<4];

void push_up(int id){
	tree[id].value = tree[lson].value | tree[rson].value;
}

//循环移位，即value集合的每个数都加上了x。
void cyclic_shift(int id, int x){
	tree[id].value = (tree[id].value<<x) | (tree[id].value>>(m-x));
}

void push_down(int id){
	if(tree[id].lazy){
		tree[lson].lazy += tree[id].lazy;
		tree[lson].lazy %= m;
		tree[rson].lazy += tree[id].lazy;
		tree[rson].lazy %= m;
		cyclic_shift(lson, tree[id].lazy);
		cyclic_shift(rson, tree[id].lazy);
		tree[id].lazy = 0;
	}
}

void build(int id, int l, int r){
	tree[id].l = l;
	tree[id].r = r;
	tree[id].lazy = 0;
	if(l == r){
		tree[id].value.reset();
		tree[id].value.set(arr[dfn[l]]%m);
		return;
	}
	build(lson, l, mid);
	build(rson, mid+1, r);
	push_up(id);
}

void update(int id, int l, int r, int x){
	if(l <= tree[id].l && tree[id].r <= r){
		tree[id].lazy += x;
		tree[id].lazy %= m;
		cyclic_shift(id, x);
		return;
	}
	push_down(id);
	if(l <= mid)update(lson, l, r, x);
	if(r > mid)update(rson, l, r, x);
	push_up(id);
}

bitset<M> query(int id, int l, int r){
	if(l <= tree[id].l && tree[id].r <= r){
		return tree[id].value;
	}
	push_down(id);
	bitset<M> ans;
	if(l <= mid) ans |= query(lson, l, r);
	if(r > mid)ans |= query(rson, l, r);
	return ans;
}

int main()
{
	//freopen("inputI.txt", "r", stdin);
	while(scanf("%d%d", &n, &m) != EOF){
		//由于循环移位会将1移除m的范围，所以每次只求[1,m)之间的素数。
		init_prime();
		for(int i = 1; i <= n; i++)
			scanf("%d", &arr[i]);
		int u, v;
		init();
		for(int i = 1; i < n; i++){
			scanf("%d%d", &u, &v);
			add_edge(u, v);
			add_edge(v, u);
		}
		idx = 0;
		dfs(1, 0);
		build(1, 1, n);
		int q, t, x;
		scanf("%d", &q);
		while(q--){
			scanf("%d%d", &t, &v);
			if(t == 1){
				scanf("%d", &x);
				update(1, in[v], out[v], x%m);
			}else if(t == 2){
				bitset<M> ans = query(1, in[v], out[v]);
				printf("%d\n", (int)((ans&prime).count()));
			}
		}
	}

	return 0;
}
