// 2018-07-29
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#define ll long long

using namespace std;

const ll INF = 0x3f3f3f3f3f3f3f3f;

map<ll, ll> factor;

void get_fact(ll k){
	for(ll i = 2; i <= k; i++){
		if(k%i == 0){
			while(k%i==0){
				factor[i]++;
				k/=i;
			}
		}
	}
}

void print_factor(){
	for(auto &f: factor){
		cout<<f.first<<" "<<f.second<<endl;
	}
}

int main()
{
	ll n, k;
	while(cin>>n>>k){
		factor.clear();
		if(k > n){
			cout<<0<<endl;
			continue;
		}
		get_fact(k);
		ll ans = INF;
		for(auto &f: factor){
			ll a = f.first;
			ll b = f.second;
			ll sum = 0;
			ll tmp = a;
			while(tmp <= n){
				sum += n/tmp;
				tmp *= a;
			}
			ans = min(ans, sum/b);
		}
		cout<<ans<<endl;
	}

	return 0;
}
