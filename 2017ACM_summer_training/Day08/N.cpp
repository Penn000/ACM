#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mid ((l+r)>>1)

using namespace std;

const int N = 100010;
struct Node{
	int lson, rson, sum;
}tree[N*30];
int root[N], arr[N], arr2[N], tot;
int n, m, q;

void init_Hash(){//将原数列排序并去重
	tot = 0;
	for(int i = 1; i <= n; i++)
		arr2[i] = arr[i];
	sort(arr2+1, arr2+1+n);
	m = unique(arr2+1, arr2+1+n)-arr2-1;
}

int Hash(int x){
	return lower_bound(arr2+1, arr2+1+m, x) - arr2;
}

int build(int l, int r){
	int rt = tot++;
	tree[rt].sum = 0;
	if(l != r){
		tree[rt].lson = build(l, mid);
		tree[rt].rson = build(mid+1, r);
	}
	return rt;
}

int update(int rt, int pos, int value){
	int newroot = tot++, tmp = newroot;
	tree[newroot].sum = tree[rt].sum + value;
	int l = 1, r = m;
	while(l < r){
		if(pos <= mid){
			tree[newroot].lson = tot++;
			tree[newroot].rson = tree[rt].rson;
			newroot = tree[newroot].lson;
			rt = tree[rt].lson;
			r = mid;
		}else{
			tree[newroot].rson = tot++;
			tree[newroot].lson = tree[rt].lson;
			newroot = tree[newroot].rson;
			rt = tree[rt].rson;
			l = mid+1;
		}
		tree[newroot].sum = tree[rt].sum + value;
	}
	return tmp;
}

int query(int lroot, int rroot, int pos){
	int ans = 0;
	int l = 1, r = m-1;
	while(l < r){
		if(pos <= mid){
			r = mid;
			lroot = tree[lroot].lson;
			rroot = tree[rroot].lson;
		}else{
			l = mid+1;
			ans += (tree[tree[rroot].lson].sum-tree[tree[lroot].lson].sum);
			lroot = tree[lroot].rson;
			rroot = tree[rroot].rson;
		}
	}
	if(pos < l)return 0;
	else return ans+tree[rroot].sum-tree[lroot].sum;
}

int main()
{
	freopen("dataN.txt", "r", stdin);
    int T, kase = 0;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &q);
		for(int i = 1; i <= n; i++)
			scanf("%d", &arr[i]);
		init_Hash();
		root[0] = build(1, m);
		for(int i = 1; i <= n; i++){
			int pos = Hash(arr[i]);
			root[i] = update(root[i-1], pos, 1);
		}
		for(int i = 0; i < tot; i++){
			cout<<i<<" "<<tree[i].lson<<" "<<tree[i].rson<<" "<<tree[i].sum<<endl;
		}
		printf("Case %d:\n", ++kase);
		int l, r, h;
		while(q--){
			scanf("%d%d%d", &l, &r, &h);
			l+=1; r+=1;
			int pos = Hash(h);
			if(pos == 0)printf("0\n");
			else printf("%d\n", query(root[l-1], root[r], pos));
		}
	}

	return 0;
}
