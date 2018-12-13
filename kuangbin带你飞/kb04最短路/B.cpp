#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 210;
pair<int, int> p[N];
int n, vis[N], pre[N];
double G[N][N], dis[N];

void dijkstra(int s)
{
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++)
        dis[i] = G[s][i];
    dis[s] = 0;
    vis[s] = 1;
    pre[s] = -1;
    double maxdis;
	int u = 1;
    for(int i = 0; i < n; i++)
    {
        maxdis = 0;
        for(int j = 2; j < n; j++)
            if(!vis[j] && dis[j] > maxdis)
            {
                maxdis = dis[j];
                u = j;
            }
        vis[u] = 1;
        for(int v = 1; v < n; v++)
        {
			if(vis[v])continue;
            if(dis[v] <= dis[u]+G[u][v]){
                dis[v] = dis[u]+G[u][v];
                pre[v] = u;
            }
        }
    }
}


int main(){
    int kase = 0;
    while(scanf("%d", &n)!=EOF && n){
        for(int i = 0; i < n; i++){
            scanf("%d%d", &p[i].first, &p[i].second);
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                G[i][j] = G[j][i] = sqrt((p[i].first-p[j].first)*(p[i].first-p[j].first)+(p[i].second-p[j].second)*(p[i].second-p[j].second))*1.0;
            }
        }
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
			  	cout<<G[i][j]<<" ";
			cout<<endl;
		}
        dijkstra(0);
        int ptr = 1;
		double ans = 500000.0;
        while(pre[ptr] != -1){
            if(ans > G[ptr][pre[ptr]])ans = G[ptr][pre[ptr]];
            ptr = pre[ptr];
        }
        printf("Scenario #%d\nFrog Distance = %.3f\n\n", ++kase, ans);
    }

    return 0;
}
