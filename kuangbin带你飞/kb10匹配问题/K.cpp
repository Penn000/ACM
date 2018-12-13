//2017-08-21
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 310;
const int INF = 0x3f3f3f3f;
int G[N][N];
int n_x, n_y;
int matching[N], l_x[N], l_y[N];
int slack[N];
bool vis_x[N], vis_y[N];

bool dfs(int u){
	vis_x[u] = 1;
	for(int v = 0; v < n_y; v++){
		if(vis_y[v])continue;
		int tmp = l_x[u]+l_y[v]-G[u][v];
		if(tmp == 0){
			vis_y[v] = 1;
			if(matching[v] == -1 || dfs(matching[v])){
				matching[v] = u;
				return true;
			}
		}else if(slack[v] > tmp){
			slack[v] = tmp;
		}
	}
	return false;
}

int KM(){
	memset(matching, -1, sizeof(matching));
	memset(l_y, 0, sizeof(l_y));
	for(int u = 0; u < n_x; u++){
		l_x[u] = -INF;
		for(int v = 0; v < n_y; v++)
			if(G[u][v] > l_x[u])
			  	l_x[u] = G[u][v];
	}
	for(int u = 0; u < n_x; u++){
		for(int i = 0; i < n_y; i++)
		  	slack[i] = INF;
		while(1){
			memset(vis_x, 0, sizeof(vis_x));
			memset(vis_y, 0, sizeof(vis_y));
			if(dfs(u))break;
			int d = INF;
			for(int i = 0; i < n_y; i++)
			  	if(!vis_y[i] && d > slack[i])
				  	d = slack[i];
			for(int i = 0; i < n_x; i++)
			  	if(vis_x[i])
				  	l_x[i] -= d;
			for(int i = 0; i < n_y; i++){
				if(vis_y[i])l_y[i] += d;
				else slack[i] -= d;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n_y; i++)
		if(matching[i] != -1)
		  	ans += G[matching[i]][i];
	return ans;
}

int main()
{
	freopen("inputK.txt", "r", stdin);
    int n;
	while(scanf("%d", &n)!=EOF){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &G[i][j]);
			}
		}
		n_x = n_y = n;
		printf("%d\n", KM());
	}

	return 0;
}
