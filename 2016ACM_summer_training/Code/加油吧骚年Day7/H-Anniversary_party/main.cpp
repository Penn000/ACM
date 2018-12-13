//2016.8.7
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

const int maxn = 6005;
int dp[maxn][2];//dp[i][j]表示i节点的子树的最大happy值，j==1时i不去，j==0时i去
int happy[maxn], fa[maxn];//fa[i]表示i节点的父亲
vector<int> v[maxn];//用来保存v[i]的儿子

int dfs(int r)
{
	int len = v[r].size();
	dp[r][1] = happy[r];
	for(int i = 0; i < len; i++)
	  dfs(v[r][i]);//使得从叶子节点先计算
	for(int i = 0; i < len; i++)
	{
		dp[r][0] += max(dp[v[r][i]][0], dp[v[r][i]][1]);//r不去
		dp[r][1] += dp[v[r][i]][0];//r去
	}
}

int main()
{
	int n, l, k;
	while(cin>>n)
	{
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &happy[i]);
			fa[i] = -1;
			v[i].clear();//初始化
		}
		while(cin>>l>>k&&l&&k)
		{
			fa[l] = k;
			v[k].push_back(l);
		}
		int root = 1;
		while(fa[root] != -1)root = fa[root];//节点的父亲为-1时，此节点为根
		dfs(root);
		cout<<max(dp[root][0],dp[root][1])<<endl;
	}

	return 0;
}
