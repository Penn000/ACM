#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#define ll long long 

using namespace std;

const int N = 25;
const ll MOD = 1000000009;

ll k[N], a[N], n, m, c;

map<ll, ll> val;

ll dfs(ll x){
	if(x<=n)return a[x];
	if(val[x] != 0)return val[x];
	ll sum = 0;
	for(int i = 1; i <= c; i++){
		sum = (sum+dfs(x-k[i]))%MOD;
	}
	return val[x] = sum;
}

int main()
{
	cin>>n>>m>>c;
	for(int i = 1; i <= n; i++)
	  cin>>a[i];
	for(int i = 1; i <= c; i++)
	  cin>>k[i];

	cout<<dfs(m)<<endl;

	return 0;
}
