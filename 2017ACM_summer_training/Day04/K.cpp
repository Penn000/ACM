#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long 

using namespace std;

ll p[10000], num;
int len;

ll quick_pow(ll a, ll n, ll MOD){
	ll ans = 1;
	while(n){
		if(n&1)ans = ans*a%MOD;
		a = a*a%MOD;
		n>>=1;
	}
	return ans;
}

// ll phi(ll n){
//     ll ans = n;
//     for(ll i = 2; i*i <= n; i++){
//         if(n%i==0){
//             ans -= ans/i;
//             while(n%i==0)
//                 n /= i;
//         }
//     }
// 	if(n > 1)ans = ans - ans/n;
//     return ans;
// }

void decomposition_factor(ll n)    
{    
    len = 0;    
    for(ll i=2; i*i<=n; i++)    
    {    
        if(n%i==0)    
        {    
            p[len++] = i;   
            while(n%i==0) n/=i;    
        }    
    }    
    if(n>1)    
        p[len++] = n;  //这个不可以缺少  
}

int primitive_roots(ll num){
	ll phin = num-1;
	decomposition_factor(phin);
	int ans = 0;
	bool fg;
	for(int a = 2; a < num; a++){
		fg = true;
		for(int i = 0; i < len; i++){
			if(quick_pow(a, phin/p[i], num) == 1){
				fg = false;
				break;
			}
		}
		if(fg)ans++;
	}
	return ans;
}

int main()
{
	while(scanf("%lld", &num)){
		printf("%d\n", primitive_roots(num));
	}

	return 0;
}
