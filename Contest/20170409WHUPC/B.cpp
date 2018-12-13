#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 10005;
int n, m, G[N][N], A[N][25], cnt[N];

int main()
{
	int u, v;
	while(scanf("%d%d", &n, &m)!=EOF)
	{
		memset(G, 0, sizeof(G));
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < n-1; i++)
		{
			scanf("%d%d", &u, &v);
			G[u][v] = G[v][u] = 1;
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++){
			  	scanf("%d", &A[i][j]);
				if(A[i][j] == 1)cnt[i]++;
			}
		for(int l = 1; l < n; l++)
		{
			for(int i = 0; i < l; i++)
		}
	}

    return 0;
}
