#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100005;

double dp[N][2];
int arr[N], fa[N];
vector<int> vec[N];

void dfs(int rt){
	int len = vec[rt].size();
	dp[rt][1] = arr[rt]*1.0;
	for(int i = 0; i < len; i++)
	  	dfs(vec[rt][i]);
	for(int i = 0; i < len; i++){
		dp[rt][0] += max(dp[vec[rt][i]][0], dp[vec[rt][i]][1]);
		dp[rt][1] += max(dp[vec[rt][i]][1] - 0.5*arr[vec[rt][i]], dp[vec[rt][i]][0]);
	}
}

int main()
{
	int n;
	while(cin>>n){
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++){
			cin>>arr[i];
			fa[i] = -1;
			vec[i].clear();
		}
		int u, v;
		for(int i = 0; i < n-1; i++){
			cin>>u>>v;
			fa[v] = u;
			vec[u].push_back(v);
		}
		int root = 1;
		while(fa[root] != -1)root = fa[root];
		dfs(root);
		printf("%.1f\n", max(dp[root][0],dp[root][1]));
	}

	return 0;
}
