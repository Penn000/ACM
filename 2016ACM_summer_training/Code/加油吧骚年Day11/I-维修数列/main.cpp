#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 1000005;
int n, m;
int root, tot;
int sum[N], son[N][2], fa[N], size[N], mx[N], key[N], lx[N], rx[N];
bool tag[N], rev[N];

void update(int id)
{
	int lson = son[id][0], rson = son[id][1];
	sum[id] = sum[lson] + sum[rson] + key[id];
	size[id] = size[lson] + size[rson] + 1;
	mx[id] = max(mx[lson], mx[rson]);
	mx[id] = max(mx[id], rx[lson]+lx[rson]+key[id]);
	lx[id] = max(lx[lson], sum[lson]+lx[rson]+key[id]);
	rx[id] = max(rx[rson], sum[rson]+rx[lson]+key[id]);
}

void pushdown(int id)
{
	int lson = son[id][0], rson = son[id][1];
	if(tag[id])
	{
		rev[id]= tag[id] = 0;
		if(lson)tag[lson]=1,key[lson]=key[id],sum[lson]=key[id]*size[lson];
		if(rson)tag[rson]=1,key[rson]=key[id],sum[rson]=key[id]*size[rson];
		if(key[id]>=0)
		{

		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	

	return 0;
}
