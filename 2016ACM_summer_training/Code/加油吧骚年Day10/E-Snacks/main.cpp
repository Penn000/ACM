//2016.8.11
#pragma comment(linker, "/STACK:1024000000, 1024000000")
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define N 100005
#define lson (id<<1)
#define rson ((id<<1)|1)
#define mid ((l+r)>>1)

using namespace std;

struct node
{
	long long max, lazy;
}tree[N*5];

vector<int> v[N];
long long w[N], val[N];//val[i]表示从根节点走到i节点的价值和
int in[N], out[N], flag;//in记录查询区间的左端，out记录查询区间的右端


//线段树模板
//************************************************************************************
void push_up(int id)
{
	tree[id].max = max(tree[lson].max, tree[rson].max);
	return;
}

void build_tree(int id, int l, int r)
{
	if(l == r)
	{
		tree[id].max = val[l];
		tree[id].lazy = 0;
		return ;
	}
	build_tree(lson, l, mid);
	build_tree(rson, mid+1, r);
	push_up(id);
	tree[id].lazy = 0;
	return ;
}

void push_down(int id, int l, int r)
{
	if(tree[id].lazy)
	{
		tree[lson].lazy += tree[id].lazy;
		tree[rson].lazy += tree[id].lazy;
		tree[lson].max += tree[id].lazy;
		tree[rson].max += tree[id].lazy;
		tree[id].lazy = 0;
	}
	return ;
}

void ins(int id, int l, int r, int ql, int qr, int tt)
{
	if(ql<=l&&r<=qr)
	{
		tree[id].max += tt;
		tree[id].lazy += tt;
		return;
	}
	if(tree[id].lazy) push_down(id, l, r);
	if(ql<=mid)
	  	ins(lson, l, mid, ql, qr, tt);
	if(mid+1<=qr)
	  	ins(rson, mid+1, r, ql, qr, tt);
	push_up(id);
	return;
}

long long query(int id, int l, int r, int ql, int qr)
{
	if(ql<=l && r<=qr)
	{
		return tree[id].max;
	}
	if(tree[id].lazy)
	  	push_down(id, l, r);
	long long maxnum = -9999999999999;
	if(ql<=mid) maxnum = max(maxnum, query(lson, l, mid, ql, qr));
	if(mid+1<=qr) maxnum = max(maxnum, query(rson, mid+1, r, ql, qr));
	return maxnum;
}
//************************************************************************************

void dfs(int a, int fa, long long wight)
{
	in[a] = ++flag;
	for(int i = 0; i < v[a].size(); i++)
	{
		int b = v[a][i];
		if(b==fa)continue;
		dfs(b, a, w[b]+wight);
	}
	out[a] = flag;
	val[in[a]] = wight;
}

int main()
{
	int T, n, m, a, b, cmd;
	cin>>T;
	for(int kase = 1; kase <= T; kase++)
	{
		printf("Case #%d:\n", kase);
		cin>>n>>m;
		for(int i = 0; i < N; i++)
		    v[i].clear();
		for(int i = 0; i < n-1; i++)
		{
			scanf("%d%d", &a, &b);
			a++; b++;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(int i = 1 ; i <= n; i++)
		  scanf("%lld", &w[i]);
		flag = 0;
		dfs(1, 0, w[1]);
		for(int i = 1; i <= n; i++)
		  cout<<in[i]<<" "<<out[i]<<endl;
		build_tree(1, 1, n);
		while(m--)
		{
			scanf("%d", &cmd);
			if(cmd == 0)
			{
				scanf("%d%d", &a, &b);a++;
				ins(1, 1, n, in[a], out[a], b-w[a]);
				w[a] = b;
			}else
			{
				scanf("%d", &a); a++;
				long long ans = query(1, 1, n, in[a], out[a]);
				cout<<ans<<endl;
			}
		}
	}

	return 0;
}
