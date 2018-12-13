// 2018-07-29
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long 

using namespace std;

ll arr[20];
int n, ans;
bool vis[20];

void dfs(int step){
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			for(int k = j+1; k <= n; k++){
				if(!vis[i] && !vis[j] && !vis[k] && arr[i]+arr[j]>arr[k]){
					vis[i] = vis[j] = vis[k] = true;
					ans = max(ans, step);
					dfs(step+1);
					vis[i] = vis[j] = vis[k] = false;
				}
			}
		}
	}
	return;
}

int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++)
	  cin>>arr[i];
	ans = 0;
	sort(arr+1, arr+1+n);
	memset(vis, 0, sizeof(vis));
	dfs(1);
	cout<<ans<<endl;

	return 0;
}
