// 2018-07-29
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long 

using namespace std;

int main()
{
	ll n;
	while(cin>>n){
		ll ans = n^(n-1);
		int cnt = 0;
		while(ans){
			if(ans&1LL){
				cnt++;
			}
			ans>>=1;
		}
		cout<<cnt<<endl;
	}


	return 0;
}
