#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int G[105][105];
int n;

void query(int a, int b)
{
	if(G[a][b] == 0){
		for(int i = 1; i <= n; i++)
		  	if(G[a][i] == 1 && G[b][i] == 1){
			  	cout<<"No problem"<<endl;
			  	return;
		}
		cout<<"OK"<<endl;
	}else if(G[a][b] == 1){
		for(int i = 1; i <= n; i++)
		  	if(G[a][i] == -1 && G[b][i] == -1)
			  	return;
		cout<<"No problem"<<endl;
	}else if(G[a][b] == -1){
		for(int i = 1; i <= n; i++)
		  if(G[a][i] == 1 && G[b][i] == 1){
			  cout<<"OK but..."<<endl;
			  return;
		  }
		cout<<"No way"<<endl;
	}
}

int main()
{
	int m, q, u, v, re;
	while(cin>>n>>m>>q)
	{
		memset(G, 0, sizeof(G));
		for(int i = 0; i < m; i++)
		{
			cin>>u>>v>>re;
			G[u][v] = G[v][u] = re;
		}
		while(q--)
		{
			cin>>u>>v;
			query(u, v);
		}
	}

    return 0;
}
