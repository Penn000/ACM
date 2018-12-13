//2017-03-22
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int G[1010][1010], n, jiqun[1010];
int vis[1010];

void dfs(int id, int cnt)
{
	vis[id] = cnt;
	for(int i = 1; i <= 1000; i++){
		if(G[id][i] == 1){
			for(int j = 1; j <= n; j++){
				if(G[j][i] && !vis[j])dfs(j, cnt);
			}
		}
	}
}

int main()
{
	int k;
	while(scanf("%d", &n)!=EOF)
	{
		char ch;
		int ho;
		memset(G, 0, sizeof(G));
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i++)
		{
			scanf("%d:", &k);
			for(int j = 0; j < k; j++){
				cin>>ho;
				G[i][ho] = 1;
			}
		}
		int cnt = 1;
		for(int i = 1; i <= n; i++){
			if(!vis[i]){
				dfs(i, cnt);
				cnt++;
			}
		}
		cnt--;
		for(int i = 1; i <= n; i++){
			jiqun[vis[i]]++;
		}
		cout<<cnt<<endl;
		sort(jiqun+1, jiqun+1+cnt);
		for(int i = cnt; i >= 1; i--)
		  	if(i == 1)cout<<jiqun[i]<<endl;
			else cout<<jiqun[i]<<" ";
	}

    return 0;
}
