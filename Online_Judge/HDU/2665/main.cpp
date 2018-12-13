//2017-08-07
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
#define mid ((l+r)>>1)

using namespace std;

const int N = 100010;
const int M = N * 30;
struct node{//第i棵线段树的节点维护插入i个数字，每个区间的数字个数。
	int lson, rson, sum;
}tree[M];
int root[N], arr[N], arr2[N], tot;
int n, m, q;

void init(){//将原数列排序并去重
	tot = 0;
	for(int i = 1; i <= n; i++)
	  arr2[i] = arr[i];
	sort(arr2+1, arr2+1+n);
	m = unique(arr2+1, arr2+1+n)-arr2-1;
}

int getID(int x){
	return lower_bound(arr2+1, arr2+1+m, x) - arr2;
}

int build(int l, int r){
	int id = tot++;
	tree[id].sum = 0;
	if(l != r){
		tree[id].lson = build(l, mid);
		tree[id].rson = build(mid+1, r);
	}
	return id;
}

int update(int id, int pos, int value){
	int newroot = tot++, tmp = newroot;
	tree[newroot].sum = tree[id].sum + value;
	int l = 1, r = m;
	while(l < r){
		if(pos <= mid){
			tree[newroot].lson = tot++;
			tree[newroot].rson = tree[id].rson;
			newroot = tree[newroot].lson;
			id = tree[id].lson;
			r = mid;
		}else{
			tree[newroot].rson = tot++;
			tree[newroot].lson = tree[id].lson;
			newroot = tree[newroot].rson;
			id = tree[id].rson;
			l = mid+1;
		}
		tree[newroot].sum = tree[id].sum + value;
	}
	return tmp;
}

int query(int lroot, int rroot, int k){
	int l = 1, r = m;
	while(l < r){
		if(tree[tree[lroot].lson].sum - tree[tree[rroot].lson].sum >= k){
			r = mid;
			lroot = tree[lroot].lson;
			rroot = tree[rroot].lson;
		}else{
			l = mid + 1;
			k -= tree[tree[lroot].lson].sum - tree[tree[rroot].lson].sum;
			lroot = tree[lroot].rson;
			rroot = tree[rroot].rson;
		}
	}
	return l;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &q);
		for(int i = 1; i <= n; i++)
		  scanf("%d", &arr[i]);
		init();
		root[n+1] = build(1, m);
		for(int i = n; i > 0; i--){
			int pos = getID(arr[i]);
			root[i] = update(root[i+1], pos, 1);
		}
		while(q--){
			int l, r, k;
			scanf("%d%d%d", &l, &r, &k);
			printf("%d\n", arr2[query(root[l], root[r+1], k)]);
		}
	}

	return 0;

}
