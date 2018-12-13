#include <iostream>
#define N 10000005
#define lson (id<<1)
#define rson ((id<<1)|1)
#define mid ((l+r)>>1)
using namespace std;
struct nod{
	int sum,lazy;
}tree[N*5];
int n,q;
void push_up(int id)
{
	tree[id].sum=tree[lson].sum+tree[rson].sum;
	return;
}
void build_tree(int id,int l,int r)
{
//	cout<<id<<' '<<l<<' '<<r<<' '<<mid<<endl;
	if (l==r)
	{
		scanf("%d",&tree[id].sum);
		tree[id].lazy=0;
		return;
	}
	build_tree(lson,l,mid);
	build_tree(rson,mid+1,r);
	push_up(id);
	tree[id].lazy=0;
	return;
}

void push_down(int id,int l,int r)
{
	tree[lson].sum+=(mid-l+1)*tree[id].lazy;
	tree[lson].lazy+=tree[id].lazy;
	tree[rson].sum+=(r-mid)*tree[id].lazy;
	tree[rson].lazy+=tree[id].lazy;
	tree[id].lazy=0;
	return;
}

void ins(int id,int l,int r,int ql,int qr,int tt)
{
	if (ql<=l && r<=qr)
	{
		tree[id].sum+=(r-l+1)*tt;
		tree[id].lazy+=tt;
		return;
	}
	if (tree[id].lazy) push_down(id,l,r);
	if (ql<=mid)
		ins(lson,l,mid,ql,qr,tt);
	if (mid+1<=qr)
		ins(rson,mid+1,r,ql,qr,tt);
	push_up(id);
	return;
}

int query(int id,int l,int r,int ql,int qr)
{
	if (ql<=l && r<=qr)
	{
		return tree[id].sum;
	}
	if (tree[id].lazy)
		push_down(id,l,r);
	int sum=0;
	if (ql<=mid)
		sum+=query(lson,l,mid,ql,qr);
	if (mid+1<=qr)
		sum+=query(rson,mid+1,r,ql,qr);
	return sum;
}

int main()
{
	while (cin>>n>>q)
	{
		build_tree(1,1,n);
//		cout<<"GOOD"<<endl;
		while (q--)
		{
			int f,x,y;
			cin>>f>>x>>y;
			if (f==1)
			{
				int tt;
				cin>>tt;
				ins(1,1,n,x,y,tt);
			}
			else
			{
				cout<<query(1,1,n,x,y)<<endl;
			}
		}
	}
}
