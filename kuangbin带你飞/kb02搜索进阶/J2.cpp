#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int G[15][15], n, m, book[15], answer;

void dfs(int pos, int step, int cost)
{
	if(step == n){
		if(cost < answer)answer = cost;
		return;
	}
	for(int i = 1; i <= n; i++)
	{
		if(G[pos][i]!=-1 && !book[i]){
			book[i] = 1;
			dfs(i, step+1, cost+G[pos][i]);
			book[i] = 0;
		}
	}
}

int main()
{
	int a, b, c;
	while(cin>>n>>m)
	{
		memset(G, -1, sizeof(G));
		memset(book, 0, sizeof(book));
		answer = 0x3f3f3f3f;
		for(int i = 0; i < m; i++)
		{
			cin>>a>>b>>c;
			G[a][b] = c;
			G[b][a] = c;
		}
		for(int i = 1; i <= n; i++)
		{
			book[i] = 1;
			dfs(i, 1, 0);
			book[i] = 0;
		}
		if(answer == 0x3f3f3f3f)cout<<-1<<endl;
		else cout<<answer<<endl;
	}

    return 0;
}
