#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const int MOD = 1000000007;

ll quick_pow(ll a, ll n){
	ll ans = 1;
	while(n){
		if(n&1)ans = (ans*a)%MOD;
		a = (a*a)%MOD;
		n >>= 1;
	}
	return ans;
}

int main()
{
	ll a, b, c, p, n;
	while(cin>>a>>b>>c>>p>>n){
		cout<<((((a*n)%MOD*(n-1))%MOD)*quick_pow(p, n-2))%MOD<<endl;
	}

	return 0;
}
