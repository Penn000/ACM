//2017-05-17
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
#define mid ((st[id].l+st[id].r)>>1)
#define lson (id<<1)
#define rson ((id<<1)|1)

using namespace std;

const ll N = 100005;
ll arr[N];
struct Node{
	ll l, r, sum, lazy;
}st[N<<2];

void build(int id, int l, int r)
{
	st[id].l = l; st[id].r = r; st[id].lazy = 0;
	if(l == r){
		st[id].sum = arr[l];
		return;
	}
	build(lson, l, mid);
	build(rson, mid+1, r);
	st[id].sum = st[lson].sum+st[rson].sum;
}

void push_down(int id)
{
	if(st[id].lazy != 0){
		st[lson].lazy += st[id].lazy;
		st[rson].lazy += st[id].lazy;
		st[id].sum += (st[id].r-st[id].l+1)*st[id].lazy;
		st[id].lazy = 0;
	}
	return;
}

ll query(int id, int l, int r)
{
	if(st[id].l == l && st[id].r == r)return st[id].sum+(r-l+1)*st[id].lazy;
	push_down(id);
	if(r <= mid)return query(lson, l, r);
	else if(l > mid)return query(rson, l, r);
	else return query(lson, l, mid)+query(rson, mid+1, r);
}

void update(int id, int l, int r, int w)
{
	if(st[id].l == l && st[id].r == r){
		st[id].lazy += w;
		return;
	}
	st[id].sum += (r-l+1)*w;
	if(r <= mid)update(lson, l, r, w);
	else if(l > mid)update(rson, l, r, w);
	else{
		update(lson, l, mid, w);
		update(rson, mid+1, r, w);
	}
}

int main()
{
	ll n, q;
	while(scanf("%lld%lld", &n, &q)!=EOF){
		for(int i = 1; i <= n; i++)
		  scanf("%lld", &arr[i]);
		build(1, 1, n);
		char op[5];
		ll a, b, c;
		while(q--){
			scanf("%s", op);
			if(op[0] == 'Q'){
				scanf("%lld%lld", &a, &b);
				printf("%lld\n", query(1, a, b));
			}else if(op[0] == 'C'){
				scanf("%lld%lld%lld", &a, &b, &c);
				update(1, a, b, c);
			}
		}
	}

	return 0;
}
