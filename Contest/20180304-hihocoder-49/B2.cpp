#include <stdio.h>
#include <bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
using namespace std;  
int cnt[105];
int n,m,k;
ll c[105][105];
int main()
{
	cin>>n>>m>>k;
	int a;
	for(int i=0;i<=100;i++){
		c[0][i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			c[i][j]=c[i][j-1]+c[i-1][j-1];
			c[i][j]%=1000000009;
		}
	}
	for(int i=0;i<n;i++){
		cin>>a;
		cnt[a%k]++;
	}
	ll ans=0;
	for(int i=0;i<k;i++){
		if(cnt[i]>=m){
			ans+=c[m][cnt[i]];
			ans%=1000000009;
		}
	}	
	cout<<ans;
	return 0;  
}
