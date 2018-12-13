//2017-08-19
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 15;
const int INF = 0x3f3f3f3f;
int G[N][N], n, m, pow3[N], dp[N][60000];//dp[i][S]表示到达节点i，状态为S时的最小费用

//询问节点i在状态S下经过了几次。将状态压缩为一个三进制数。
int query(int i, int S){
	return (S/pow3[i])%3;
}

int main()
{
	//预处理3的次方，pow3[n]表示3的n次方。
	pow3[0] = 1;
	for(int i = 1; i < N; i++)
	  	pow3[i] = pow3[i-1]*3;
	while(scanf("%d%d", &n, &m)!=EOF){
		int u, v, w;
		memset(G, INF, sizeof(G));
		memset(dp, INF, sizeof(dp));
		for(int i = 0; i < m; i++){
			scanf("%d%d%d", &u, &v, &w);
			u--; v--;//节点从0到n-1编号。
			G[u][v] = G[v][u] = min(G[u][v], w);//去重边
		}
		//初始化dp，因为每一个点都可以作为起点，所以到达i节点1次的最小费用为0。
		for(int i = 0; i < n; i++)
		  	dp[i][pow3[i]] = 0;
		int ans = INF;
		for(int S = 0; S < pow3[n]; S++){
			bool fg = true;
			for(int i = 0; i < n; i++){
				//检查是否每个节点都已经经过
				if(query(i, S) == 0){
					fg = false;
					continue;
				}
				//转移到下一个节点
				for(int v = 0; v < n; v++){
					if(query(v, S) == 2)
					  	continue;
					dp[v][S+pow3[v]] = min(dp[v][S+pow3[v]], dp[i][S]+G[i][v]);
				}
			}
			if(fg){
				for(int i = 0; i < n; i++)
				  	ans = min(ans, dp[i][S]);
			}
		}
		if(ans == INF)printf("-1\n");
		else printf("%d\n", ans);
	}

	return 0;
}
