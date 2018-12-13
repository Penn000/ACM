#include<iostream>
#include<cstdio>
#include<cstring>
#define N 5005
#define lson (id<<1)
#define rson ((id<<1)|1)
#define mid ((l+r)>>1)

using namespace std;

struct node
{
	int sum;
}tree[N*5];

int arr[N];

void push_up(int id)
{
	tree[id].sum = 0;
}

void build_tree(int id, int l, int r)
{
	tree[id].sum = 0;
	if(l == r){
		return ;
	}
	build_tree(lson, l, mid);
	build_tree(rson, mid+1, r);
	return;
}

void ins(int id, int l, int r, int pos)
{
	if(l == r){
		tree[id].sum = 1;return ;
	}
	if(pos <= mid)
	  ins(lson, l, mid, pos);
	else 
	  ins(rson, mid+1, r, pos);
	tree[id].sum = tree[lson].sum + tree[rson].sum;
	return ;
}

int query(int id, int l, int r, int ql, int qr)
{
	if(ql<=l&&r<=qr){
		return tree[id].sum;
	}
	int cnt = 0;
	if(ql<=mid)cnt += query(lson, l, mid, ql, qr);
	if(mid+1<=qr)cnt += query(rson, mid+1, r, ql, qr);

	return cnt;
}

int main()
{
	int n;
	while(cin>>n)
	{
		int sum = 0;
		build_tree(1, 0, n-1);
		for(int i = 0; i < n; i++){
			scanf("%d", &arr[i]);
			sum+=query(1, 0, n-1, arr[i], n-1);
			ins(1, 0, n-1, arr[i]);
		}

		int ans = sum;
		for(int i = 0; i < n; i++)
		{
			sum = sum-2*arr[i]+n-1;
			if(ans > sum)ans = sum;
		}
		cout<<ans<<endl;
	}

	return 0;
}
