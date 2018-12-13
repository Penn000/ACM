//2017-08-16
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const int TIMES = 10;

ll random0(ll n){
	return ((double)rand() / RAND_MAX*n + 0.5);
}

//快速乘a*b%mod
ll quick_mul(ll a, ll b, ll mod){
	ll ans = 0;
	while(b){
		if(b&1){
			b--;
			ans = (ans+a)%mod;
		}
		b >>= 1;
		a = (a+a) % mod;
	}
	return ans;
}

//快速幂a^b%mod
ll quick_pow(ll a, ll n, ll mod){
	ll ans = 1; 
	while(n){
		if(n&1)ans = quick_mul(ans, a, mod);
		a = quick_mul(a, a, mod);
		n >>= 1;
	}
	return ans;
}

bool witness(ll a, ll n){
	ll tmp = n-1;
	int i = 0;
	while(tmp % 2 == 0){
		tmp >>= 1;
		i++;
	}
	ll x = quick_pow(a, tmp, n);
	if(x == 1 || x == n-1)return true;
	while(i--){
		x = quick_mul(x, x, n);
		if(x == n-1)return true;
	}
	return false;
}

bool miller_rabin(ll n){
	if(n == 2)return true;
	if(n < 2 || n % 2 == 0)return false;
	for(int i  = 1; i <= TIMES; i++){
		ll a = random0(n-2)+1;
		if(!witness(a, n))
		  	return false;
	}
	return true;
}

//factor存放分解出来的素因数
ll factor[1000];
int tot;

ll gcd(ll a, ll b){
	if(a == 0)return 1;
	if(a < 0)return gcd(-a, b);
	while(b){
		ll tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

ll pollard_rho(ll x, ll c){
	ll i = 1, k = 2;
	ll x0 = rand()%x, x1 = x0;
	while(1){
		i++;
		x0 = (quick_mul(x0, x0, x)+c)%x;
		ll d = gcd(x1-x0, x);
		if(d != 1 && d != x)return d;
		if(x1 == x0)return x;
		if(i == k){
			x1 = x0;
			k += k;
		}
	}
}

//对n分解质因数
void decomposition_factor(ll n){
	if(miller_rabin(n)){
		factor[tot++] = n;
		return;
	}
	ll p = n;
	while(p >= n){
		p = pollard_rho(p, rand()%(n-1)+1);
	}
	decomposition_factor(p);
	decomposition_factor(n/p);
}

int main()
{
    int T;
	scanf("%d", &T);
	while(T--){
		ll n;
		scanf("%lld", &n);
		if(miller_rabin(n))
		  	printf("Prime\n");
		else{
			tot = 0;
			decomposition_factor(n);
			ll ans = factor[0];
			for(int i = 1; i < tot; i++)
			  	if(factor[i] < ans)ans  = factor[i];
			printf("%lld\n", ans);
		}
	}

	return 0;
}
