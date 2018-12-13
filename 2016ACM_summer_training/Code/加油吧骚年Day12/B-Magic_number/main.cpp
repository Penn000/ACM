//2016.8.14
#include<iostream>
#include<cstdio>
#define ll long long 

using namespace std;

const int mod = 1e9+7;

ll pow(ll a, ll b)//快速幂
{
	ll ans = 1;
	while(b)
	{
		if(b&1)ans *= a, ans %= mod;
		a *= a, a %= mod;
		b>>=1;
	}
	return ans;
}

int main()
{
	string a;
	int k;
	ll ans = 0;//ans = 2^i * ((i^kn)/(1-2^n))%mod
	while(cin>>a>>k)
	{
		ans = 0;
		int n = a.size();
		for(int i = 0; i < n; i++)
		  	if(a[i]=='0'||a[i]=='5')
			  	ans+=pow(2, i);
		ll y = pow(2, n);
		ll x = pow(y, k);
		x = ((1-x)%mod+mod)%mod;
		y = ((1-y)%mod+mod)%mod;
		ans = ((ans%mod)*(x*pow(y, mod-2)%mod))%mod;//利用费马小定理求y的逆元
		cout<<ans<<endl;
	}
	
	return 0;
}
