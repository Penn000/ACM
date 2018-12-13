#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1100000;
const int LEN = 1000;

int n, m, k, a[N], XOR[N], block[N], ANS[N], cnt[N];
int ans, L, R;
struct Node{
	int l, r, id;
//	bool operator<(const Node x) const {
//		if(block[l] == block[x.l])
//		  return r < x.r;
//		return block[l] < block[x.l];
//	}
}q[N];

bool cmp(const Node a, const Node b){
	if(block[a.l] == block[b.l])
	  return a.r < b.r;
	else return block[a.l] < block[b.l];
}

void add(int x){
	ans += cnt[XOR[x]^k];
	cnt[XOR[x]]++;
}

void del(int x){
	cnt[XOR[x]]--;
	ans -= cnt[XOR[x]^k];
}

int main()
{
	freopen("input.txt", "r", stdin);
	while(~scanf("%d%d%d", &n, &m, &k)){
		XOR[0] = 0;
		for(int i = 1; i <= n; i++){
		  scanf("%d", &a[i]);
		  XOR[i] = XOR[i-1] ^ a[i];
		  block[i] = (i-1)/LEN;
		}
		for(int i = 1; i <= m; i++){
			scanf("%d%d", &q[i].l, &q[i].r);
			q[i].id = i;
		}
		sort(q+1, q+n+1, cmp);
		for(int i = 0; i < m; i++)
		  cout<<q[i].l<<" "<<q[i].r<<endl;
		L = 1, R = 0, ans = 0;
		cnt[0] = 1;
		for(int i = 0; i < m; i++){
			while(L < q[i].l){
				del(L-1);
				L++;
			}
			while(L > q[i].l){
				L--;
				add(L-1);
			}
			while(R < q[i].r){
				R++;
				add(R);
			}
			while(R > q[i].r){
				del(R);
				R--;
			}
			ANS[q[i].id] = ans;
		}
		for(int i = 0; i < m; i++)
		  printf("%d\n", ANS[i]);
	}

	return 0;
}
