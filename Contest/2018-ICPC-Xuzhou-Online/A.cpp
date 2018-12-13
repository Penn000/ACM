#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const ll MOD = 1000000007LL;

ll quick_pow(ll a, ll n, ll MOD){
    ll ans = 1, base = a;
    while(n){
        if(n&1) ans = ans*base%MOD;
        base = base*base%MOD;
        n>>=1;
    }
    return ans;
}

int is_nag(int n){
	return (n&1)==1 ? -1 : 1;
}

int main()
{
	int T;
	ll n, k;
	cin>>T;
	while(T--){
		cin>>n>>k;
		ll ans = 0;
		if(n&1){
			ll _2k = quick_pow(2LL, k, MOD);
			for(int i = 1; i <= n; i++){
				ans = (ans+((_2k*quick_pow(_2k-1, n-i, MOD))%MOD*is_nag(i+1)+MOD)%MOD)%MOD;
			}
		}else{
			ll _2k = quick_pow(2LL, k, MOD);
			for(int i = 1; i < n; i++){
				ans = (ans+((_2k*quick_pow(_2k-1, n-i, MOD))%MOD*is_nag(i+1)+MOD)%MOD)%MOD;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
