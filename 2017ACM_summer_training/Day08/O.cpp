#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const int N = 110;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n, arr[N];
ll sum[N];

ll solve(int l, int r){
	ll ans = 0;
	for(int p1 = l; p1 < r; p1++){
		ll tmp = INF;
		for(int p2 = p1+1; p2 < r; p2++){
			tmp = min(tmp, sum[p1]-sum[0]);
			tmp = min(tmp, sum[p2]-sum[p1]);
			tmp = min(tmp, sum[r]-sum[p2]);
		}
		for(int p2 = 1; p2 < p1; p2++){
			tmp = min(tmp, sum[p2]-sum[0]);
			tmp = min(tmp, sum[p1]-sum[p2]);
			tmp = min(tmp, sum[r]-sum[p1]);
		}
		ans = max(ans, tmp);
	}
	return ans;
}

int main()
{
	freopen("inputO.txt", "r", stdin);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n){
		sum[0] = 0;
		for(int i = 1; i <= n; i++){
		  	cin>>arr[i];
			sum[i] = sum[i-1]+arr[i];
		}
		cout<<solve(1, n)<<endl;
	}

	return 0;
}
