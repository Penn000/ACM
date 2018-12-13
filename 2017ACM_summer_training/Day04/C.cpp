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

ll solve(int p){
    if(p <= 1)return 0;
    ll k = 0, powk = 1;
    while(p%2==0){
        k++;
        powk *= 2;
        p>>=1;
    }
    ll phip = phi(p);
	k %= phip;
    ll num = (solve(phip)+phip-k)%phip;
    return quick_pow(2, num, p)%p*powk;
}

int main()
{
    int T, p;
    cin>>T;
    while(T--){
        cin>>p;
        cout<<solve(p)<<endl;
    }
	return 0;
}
