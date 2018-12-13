#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
#define mid ((tree[id].l+tree[id].r)>>1)
#define lson (id<<1)
#define rson ((id<<1)|1)

using namespace std;

const int N = 510000;
int arr[N];

using namespace std;

struct Node{
    ll l, r, min, lazy;
}tree[N<<2];

void build(int id, int l, int r)
{
    tree[id].l = l; tree[id].r = r; tree[id].lazy = 0;
    if(l == r){
        tree[id].min = arr[l];
        return;
    }
    build(lson, l, mid);
    build(rson, mid+1, r);
    tree[id].min = min(tree[lson].min, tree[rson].min);
}

void push_down(int id)
{
    if(tree[id].lazy != 0){
        tree[lson].lazy += tree[id].lazy;
        tree[rson].lazy += tree[id].lazy;
        tree[id].min += tree[id].lazy;
        tree[id].lazy = 0;
    }
    return;
}

ll query(int id, int l, int r)
{
    if(tree[id].l == l && tree[id].r == r)return tree[id].min+tree[id].lazy;
    push_down(id);
    if(r <= mid)return query(lson, l, r);
    else if(l > mid)return query(rson, l, r);
    else return min(query(lson, l, mid), query(rson, mid+1, r));
}

void update(int id, int l, int r, int w)
{
    if(tree[id].l == l && tree[id].r == r){
        tree[id].lazy += w;
        return;
    }
    if(r <= mid)update(lson, l, r, w);
    else if(l > mid)update(rson, l, r, w);
    else{
        update(lson, l, mid, w);
        update(rson, mid+1, r, w);
    }
	tree[id].min = min(tree[lson].min+tree[lson].lazy, tree[rson].min+tree[rson].lazy);
}

int main()
{
	int n, k;
	while(~scanf("%d%d", &n, &k)){
		for(int i = 1; i <= n; i++)
		  scanf("%d", &arr[i]);
		ll ans = 0;
		build(1, 1, n);
		for(int i = 1; i+k-1 <= n; i++){
			ll mininum = query(1, i, i+k-1);
			if(mininum > 0){
				ans += mininum;
				update(1, i, i+k-1, -mininum);
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}
