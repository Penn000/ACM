//2017-08-05
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 30;
const int MOD = 1000;
int n, m, grid[N][N], dp[N][N][N];//dp[i][j][k]表示从i点到j正好走k步的方法数，转移方程为dp[i][j][k] = sum(dp[i]][v][k-1]) | j到v有边

int main()
{
	while(scanf("%d%d", &n, &m)!=EOF){
		if(!n && !m)break;
		memset(grid, 0, sizeof(grid));
		int s, t, k, T;
		for(int i = 0; i < m; i++){
			scanf("%d%d", &s, &t);
			grid[s][t] = 1;
		}
		memset(dp, 0, sizeof(dp));
		for(int k = 0; k < N; k++){
			for(int i = 0; i < n; i++){
				dp[i][i][0] = 1;
				for(int j = 0; j < N; j++){
					for(int v = 0; v < n; v++){
						if(grid[v][j] && k-1 >= 0){
							dp[i][j][k] += dp[i][v][k-1];
							dp[i][j][k] %= MOD;
						}
					}	
				}
			}
		}
		scanf("%d", &T);
		while(T--){
			scanf("%d%d%d", &s, &t, &k);
			printf("%d\n", dp[s][t][k]);
		}
	}

	return 0;
}
