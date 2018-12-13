//2017-08-31
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const int N = 20;
ll arr[N];

int main()
{
	for(ll i = 1; i <= 15; i++){
		arr[i] = 1;
		for(int j = 0; j < i; j++)
		  	arr[i] *= i;
	}
	ll n;
	while(cin>>n){
		int ans = 0;
		for(int i = 1; i <= 15; i++){
			if(arr[i] <= n){
				ans++;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
