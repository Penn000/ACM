#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const int N = 110;
const ll MOD = 1000000009;
ll arr[N], cnt[N], fact[N];

ll pow(ll a, ll b)//快速幂
{
    ll ans = 1;
    while(b)
    {
        if(b&1)ans *= a, ans %= MOD;
        a *= a, a %= MOD;
        b>>=1;
    }
    return ans;
}

ll inv(ll x){
	return pow(x, MOD-2);
}

int main()
{
	fact[0] = 1;
	for(int i = 1; i < 105; i++) fact[i] = (fact[i-1]*i)%MOD;
	int n, m, k;
	while(cin>>n>>m>>k){
		for(int i = 0; i < n; i++) cin >> arr[i];
		sort(arr, arr+n);
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < n; i++){
			for(int j = i; j < n; j++){
				if((arr[j]-arr[i])%k == 0)cnt[i]++;
			}
		}
		ll ans = 0;
		for(int i = 0; i < n; i++){
			if(cnt[i] < m)continue;
			ans += ((fact[cnt[i]-1]*inv(fact[m-1]))%MOD * inv(fact[cnt[i]-m]))%MOD;
			ans %= MOD;
		}
		cout<<ans<<endl;
	}

	return 0;
}
