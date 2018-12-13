//2017-03-01
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int M[20][5], ans[25], vis[25], m, kase;

void dfs(int city, int step)
{
	if(step == 20 && city == m){
		cout<<++kase<<":  ";
		for(int i = 0; i < 20; i++)
		  	cout<<ans[i]<<" ";
		cout<<m<<endl;
		return;
	}
	ans[step] = city;
	for(int i = 0; i < 3; i++)
	{
		if(!vis[M[city][i]])
		{
			vis[M[city][i]] = 1;
			dfs(M[city][i], step+1);
			vis[M[city][i]] = 0;
		}
	}
}

int main()
{
	while(cin>>M[1][0]>>M[1][1]>>M[1][2])
	{
		sort(M[0], M[0]+3);
		for(int i = 2; i <= 20; i++)
		{
			cin>>M[i][0]>>M[i][1]>>M[i][2];
			sort(M[i], M[i]+3);
		}
		while(cin>>m && m)
		{
			memset(vis, 0, sizeof(vis));
			kase = 0;
			dfs(m, 0);
		}
	}

	return 0;
}
