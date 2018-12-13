#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int N = 110000;
const int MOD = 1000000007;

int n, k, book[N], a;

int f(int n, int m){
	if(n < m)return (f(n, n) + m-n) % MOD;
	if(m == 1 || n == 0)return 1;
	if(n >= m)return (f(n-m, m) + f(n, m-1)) %  MOD;
}
int main()
{
	while(cin>>n>>k){
		cout<<f(n, k)<<endl;
	}
	cin>>n>>k;
	int fg = 0, h = 0;
	set<int> st[2];
	memset(book, 0, sizeof(book));
	for(int i = 0; i < n-k; i++){
		cin>>a;
		book[a]++;
		st[fg].insert(a);
	}
	while(true){
		int mx = *(--st[fg].end());
		k -= (mx - st[fg].size());
		h++;
		if(k < 0)break;
		for(auto &x: st[fg]){
			book[x]--;
			if(book[x]){
				st[!fg].insert(x);
			}
		}
		if(st[!fg].empty())break;
		st[fg].clear();
		fg = !fg;
	}
	if(k < 0)cout<<"No"<<endl;
	else{
		cout<<k<<" "<<h<<endl;
		cout<<f(k, h)<<endl;
	}

	return 0;
}
