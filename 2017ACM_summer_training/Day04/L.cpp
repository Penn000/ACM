#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long 

using namespace std;

vector<ll> p;

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

void decomposition_factor(ll n)    
{    
    p.clear();    
    for(ll i=2; i*i<=n; i++)    
    {    
        if(n%i==0)    
        {    
            p.push_back(i);    
            while(n%i==0) n/=i;    
        }    
    }    
    if(n>1)    
        p.push_back(n);  //这个不可以缺少  
}

void primitive_roots(ll num){
	ll phin = phi(num);
	decomposition_factor(phin);
	int ans = 0, len = p.size();
	bool fg;
	for(int i = 0; i < len; i++)
	  	cout<<p[i]<<" ";
	cout<<endl;
	for(int a = 2; a < num; a++){
		fg = true;
		for(int i = 0; i < len; i++){
			if(quick_pow(a, phin/p[i], num) == 1){
				fg = false;
				break;
			}
		}
		if(fg){
            ans++;
            if(ans == 1)cout<<a;
            else cout<<" "<<a;
        }
	}
	if(ans == 0)cout<<"-1"<<endl;
    else cout<<endl;
}

int main()
{
    ll num;
	while(cin>>num){
		primitive_roots(num);
	}

	return 0;
}
