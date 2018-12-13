#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const int N = 110;
const int MOD = 1000000009;
ll arr[N], cnt[N], c[N][N];

int main()
{
	int n, m, k;
	for(int i=0;i<=100;i++){
		c[0][i]=1;
	}
	for(int i=1;i<=105;i++){
		for(int j=i;j<=105;j++){
			c[i][j]=c[i][j-1]+c[i-1][j-1];
			c[i][j]%=1000000009;
		}
	}
	while(cin>>n>>m>>k){
		for(int i = 0; i < n; i++) cin >> arr[i];
		sort(arr, arr+n);
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < n; i++){
			for(int j = i; j < n; j++){
				if((arr[j]-arr[i])%k == 0)cnt[i]++;
			}
		}
		ll ans = 0;
		for(int i = 0; i < n; i++){
			if(cnt[i] < m)continue;
			ans += c[m-1][cnt[i]-1];
			ans %= MOD;
		}
		cout<<ans<<endl;
	}

	return 0;
}
