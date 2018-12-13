#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int G[15][15], n, m, book[15], answer;

bool check()
{
	for(int i = 1; i <= n; i++)
	  	if(book[i] == 0)return false;
	return true;
}

void dfs(int pos, int cost)
{
	if(cost >= answer)return ;
	if(check()){
		if(cost < answer)answer = cost;
		return;
	}
	for(int i = 1; i <= n; i++)
	{
		if(G[pos][i]!=-1 && book[i] < 2){
			book[i]++;
			dfs(i, cost+G[pos][i]);
			book[i]--;
		}
	}
}

int main()
{
	int a, b, c;
	while(scanf("%d%d", &n, &m)!=EOF)
	{
		memset(G, -1, sizeof(G));
		memset(book, 0, sizeof(book));
		answer = 0x3f3f3f3f;
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			G[a][b] = c;
			G[b][a] = c;
		}
		for(int i = 1; i <= n; i++)
		{
			book[i]++;
			dfs(i, 0);
			book[i]--;
		}
		if(answer == 0x3f3f3f3f)cout<<-1<<endl;
		else cout<<answer<<endl;
	}

    return 0;
}
