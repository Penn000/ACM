//2017-09-07
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
#define mid ((l+r)>>1)

using namespace std;

const int N = 100010;
const int M = N * 30;
struct node{
	int lson, rson, sum;//sum维护l到r的数有几个
}tree[M];
//第i棵线段树为插入前i个数字所构成的权值线段树。
int root[N], arr[N], arr2[N], tot;
int n, m, q;

void init(){//将原数列排序并去重
	tot = 0;
	for(int i = 1; i <= n; i++)
		arr2[i] = arr[i];
	sort(arr2+1, arr2+1+n);
	m = unique(arr2+1, arr2+1+n)-arr2-1;
}

//离散化
int getID(int x){
	return lower_bound(arr2+1, arr2+1+m, x) - arr2;
}

int build(int l, int r){
	int id = ++tot;
	tree[id].sum = 0;
	if(l == r)return id;
	if(l <= mid)
		tree[id].lson = build(l, mid);
	if(r > mid)
		tree[id].rson = build(mid+1, r);
	return id;
}

int update(int id, int pos, int value){
	int newroot = ++tot, tmp = newroot;
	tree[newroot].sum = tree[id].sum + value;
	int l = 1, r = m;
	while(l < r){
		if(pos <= mid){
			tree[newroot].lson = ++tot;
			tree[newroot].rson = tree[id].rson;
			newroot = tree[newroot].lson;
			id = tree[id].lson;
			r = mid;
		}else{
			tree[newroot].rson = ++tot;
			tree[newroot].lson = tree[id].lson;
			newroot = tree[newroot].rson;
			id = tree[id].rson;
			l = mid+1;
		}
		tree[newroot].sum = tree[id].sum + value;
	}
	return tmp;
}

int query(int ltree, int rtree, int k){
	int l = 1, r = m, ans = 0;
	while(l < r){
		if(k <= mid){
			ltree = tree[ltree].lson;
			rtree = tree[rtree].lson;
			r = mid;
		}else{
			ans += tree[tree[rtree].lson].sum - tree[tree[ltree].lson].sum;
			ltree = tree[ltree].rson;
			rtree = tree[rtree].rson;
			l = mid+1;
		}
	}
	if(l == r){
		if(k < l)return 0;
		else return ans + tree[rtree].sum - tree[ltree].sum;
	}
}

int main()
{
    //freopen("dataN.txt", "r", stdin);
	int T, kase = 0;
	scanf("%d", &T);
    while(T--){
		scanf("%d%d", &n, &q);
		for(int i = 1; i <= n; i++)
			scanf("%d", &arr[i]);
		init();
		root[0] = build(1, m);
		for(int i = 1; i <= n; i++){
			int pos = getID(arr[i]);
			root[i] = update(root[i-1], pos, 1);
		}
		printf("Case %d:\n", ++kase);
		while(q--){
			int l, r, h;
			scanf("%d%d%d", &l, &r, &h);
			l++; r++;
			int pos = getID(h);//找到第一个小于概数的位置
			if(arr2[pos] > h)pos--;
			printf("%d\n", query(root[l-1], root[r], pos));
		}
	}

	return 0;
}
