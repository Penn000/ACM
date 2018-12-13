//2017-08-04
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long 

using namespace std;

const int N = 1000010;
char b[N];
ll a, c;

ll quick_pow(ll a, ll n, ll MOD){
	ll ans = 1;
	while(n){
		if(n&1)ans = ans*a%MOD;
		a = a*a%MOD;
		n>>=1;
	}
	return ans;
}

ll phi(ll n){
    ll ans = n;
    for(ll i = 2; i*i <= n; i++){
        if(n%i==0){
            ans -= ans/i;
            while(n%i==0)
                n /= i;
        }
    }
	if(n > 1)ans = ans - ans/n;
    return ans;
}

int main()
{
	while(scanf("%lld%s%lld", &a, b, &c)!=EOF){
		ll len = strlen(b);
		ll MOD = phi(c), num = 0;
		for(ll i = 0; i < len; i++)
			num = (num*10 + b[i]-'0')%MOD;
		num += MOD;
		printf("%lld\n", quick_pow(a, num, c));
	}
	return 0;
}
