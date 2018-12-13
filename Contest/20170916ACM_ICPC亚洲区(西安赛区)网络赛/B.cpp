//2017-10-24
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const int MOD = 1000000007;

ll quickPow(ll a, ll n){
	ll ans = 1;
	while(n){
		if(n&1)
			ans = (a*ans)%MOD;
		a = (a*a)%MOD;
		n >>= 1;
	}
	return ans;
}

int main()
{
	ll p, q, k, T;
	cin>>T;
	while(T--){
		cin>>p>>q>>k;
		ll X = quickPow(p-2*q, k);
		ll Y = quickPow(p, k);
		cout<<(((1+X*quickPow(Y, MOD-2))%MOD) * quickPow(2, MOD-2))%MOD<<endl;
	}

	return 0;
}
