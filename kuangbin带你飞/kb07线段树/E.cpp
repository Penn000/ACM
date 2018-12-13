//2017-08-11
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define lson (id<<1)
#define rson ((id<<1)|1)
#define mid ((tree[id].l+tree[id].r)>>1)

using namespace std;

const int N = 100010;
struct Node{
	int l, r, sum, lazy;
}tree[N<<4];

void build(int id, int l, int r){
	tree[id].l = l;
	tree[id].r = r;
	tree[id].lazy = 0;
	if(l == r){
		tree[id].sum = 1;
		return;
	}
	build(lson, l, mid);
	build(rson, mid+1, r);
	tree[id].sum = tree[lson].sum + tree[rson].sum;
}

void push_down(int id){
	tree[id].sum = (tree[id].r-tree[id].l+1)*tree[id].lazy;
	tree[lson].lazy = tree[id].lazy;
	tree[rson].lazy = tree[id].lazy;
	tree[id].lazy = 0;
}

void update(int id, int l, int r, int val){
	if(tree[id].lazy)push_down(id);
	if(tree[id].l == l && tree[id].r == r){
		tree[id].sum = (r-l+1)*val;
		tree[id].lazy = 0;
		tree[lson].lazy = val;
		tree[rson].lazy = val;
		return;
	}
	if(l > mid)update(rson, l, r, val);
	else if(r <= mid)update(lson, l, r, val);
	else{
		update(lson, l, mid, val);
		update(rson, mid+1, r, val);
	}
	if(tree[lson].lazy)push_down(lson);
	if(tree[rson].lazy)push_down(rson);
	tree[id].sum = tree[lson].sum + tree[rson].sum;
}

int query(int id, int l, int r){
	if(tree[id].l == l && tree[id].r == r){
		return tree[id].sum;
	}
	if(l > mid)return query(rson, l, r);
	else if(r <= mid)return query(lson, l, r);
	else return query(lson, l, mid)+query(rson, mid+1, r);
}

int main()
{
    int T, n, kase = 0;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		build(1, 1, n);
		int m, l, r, z;
		scanf("%d", &m);
		while(m--){
			scanf("%d%d%d", &l, &r, &z);
			update(1, l, r, z);
		}
		printf("Case %d: The total value of the hook is %d.\n", ++kase, query(1, 1, n));
	}

	return 0;
}
