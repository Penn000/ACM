#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
	int l, r;
	bool operator<(const node x){
		return l < x.l;
	}
}A[110], comm[110];

int main()
{
	int T, n, m, x, y;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>x>>y;
		for(int i = 0; i < x; i++)
		  cin>>A[i].l>>A[i].r;
		sort(A, A+x);
		int cnt = 0, l, r, L, R;
		for(int i = 0; i < y; i++)
		{
			cin>>l>>r;
			for(int j = 0; j < x; j++){
				if(A[j].r >= l && A[j].l <= r){
					L = max(l, A[j].l);
					R = min(r, A[j].r);
					comm[cnt].l = L;
					comm[cnt].r = R;
					cnt++;
					if(A[j].l > r)break;
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < cnt; i++){
			if(comm[i].r-comm[i].l+1 >= m)
			  ans += comm[i].r-comm[i].l-m+2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
