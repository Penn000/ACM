//2017-08-05
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const int N = 110;
const int MOD = 20090126;
ll stir2[N][N], ans[N], factorial[N];

void init(){
	factorial[1] = 1;
	for(int i = 2; i < N; i++)
	  	factorial[i] = (factorial[i-1]*i)%MOD;
	memset(stir2, 0, sizeof(stir2));
	for(int n = 1; n < N; n++){
		stir2[n][1] = 1;
		stir2[n][n] = 1;
		for(int k = 2; k < n; k++){
			stir2[n][k] = stir2[n-1][k-1]+k*stir2[n-1][k];
			stir2[n][k] %= MOD;
		}
	}
}

int main()
{
    int T, n;
	init();
	cin>>T;
	while(T--){
		cin>>n;
		ll ans = 0;
		for(int i = 1; i <= n; i++)
		  	ans = (ans + factorial[i]*stir2[n][i]) % MOD;
		cout<<ans<<endl;
	}

	return 0;
}
