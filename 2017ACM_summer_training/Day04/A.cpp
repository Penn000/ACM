//2017-08-04
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const int N = 100010;
const int MOD = 1000000007;
char str[N];

ll quick_pow(ll a, ll n){//快速幂
	ll ans = 1;
	while(n){
		if(n&1)ans = ans*a%MOD;
		a = a*a%MOD;
		n>>=1;
	}
	return ans;
}

int main()
{
	while(scanf("%s", str)!=EOF){
		ll num = 0;
		for(int i = 0; i < strlen(str); i++){//欧拉降幂
			num *= 10;
			num += str[i]-'0';
			num %= (MOD-1);
		}
		num -= 1;
		printf("%lld\n", quick_pow(2, num));
	}

	return 0;
}
