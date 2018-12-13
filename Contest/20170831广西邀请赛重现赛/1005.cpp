//2017-08-31
#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define mid ((st[id].l+st[id].r)>>1)
#define lson (id<<1)
#define rson ((id<<1)|1)

using namespace std;

const int N = 150000;
int arr[N];
struct Node{
	int l, r, OR, XOR, AND;
}st[N<<3];

void build(int id, int l, int r)
{
	st[id].l = l; st[id].r = r;
	if(l == r){
		st[id].OR = arr[l];
		st[id].AND = arr[l];
		st[id].XOR = arr[l];
		return;
	}
	build(lson, l, mid);
	build(rson, mid+1, r);
	st[id].OR = st[lson].OR | st[rson].OR;
	st[id].XOR = st[lson].XOR ^ st[rson].XOR;
	st[id].AND = st[lson].AND & st[rson].AND;
}

int query(int id, int l, int r, int op){
	if(st[id].l == l && st[id].r == r){
		if(op == 1)return st[id].OR;
		if(op == 2)return st[id].XOR;
		if(op == 3)return st[id].AND;
	}
	if(l > mid)return query(rson, l, r, op);
	else if(r <= mid)return query(lson, l, r, op);
	else{
		if(op == 1)return query(lson, l, mid, op) | query(rson, mid+1, r, op);
		if(op == 2)return query(lson, l, mid, op) ^ query(rson, mid+1, r, op);
		if(op == 3)return query(lson, l, mid, op) & query(rson, mid+1, r, op);
	} 
}

int main()
{
	int n, q;
	while(scanf("%d%d", &n, &q)!=EOF)
	{
		for(int i = 1; i <= n; i++)
		  scanf("%d", &arr[i]);
		build(1, 1, n);
		int p;
		while(q--){
			scanf("%d", &p);
			if(p == 1)
			  	printf("%d %d %d\n", query(1, 2, n, 3), query(1, 2, n, 1), query(1, 2, n, 2));
			else if(p == n)
			  	printf("%d %d %d\n", query(1, 1, n-1, 3), query(1, 1, n-1, 1), query(1, 1, n-1, 2));
			else	
			  	printf("%d %d %d\n", query(1, 1, p-1, 3)&query(1, p+1, n, 3), query(1, 1, p-1, 1)|query(1, p+1, n, 1), query(1, 1, p-1, 2)^query(1, p+1, n, 2));
		}
	}

	return 0;
}
