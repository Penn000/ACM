// 2018-08-06
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 150;
const int INF = 0x3f3f3f3f;

int G[N][N], n;

bool vis[N];
int dist[N];
void dijsktra(int s){
	for(int i = 1; i <= n; i++){
		dist[i] = INF;
		vis[i] = false;
	}
	dist[s] = 0;
	vis[s] = true;
	for(int v = 1; v <= n; v++){
		if(s == v)continue;
		if(G[s][v]!=-1){
			dist[v] = G[s][v];
		}
	}
	int u, mindist;
	for(int ii = 0; ii < n-1; ii++){
		mindist = INF;
		for(int i = 1; i <= n; i++){
			if(!vis[i] && dist[i]<mindist){
				u = i;
				mindist = dist[i];
			}
		}
		vis[u] = true;
		for(int v = 1; v <= n; v++){
			if(!vis[v] && G[u][v]!=-1 && dist[v] > dist[u]+G[u][v])
			  dist[v] = dist[u]+G[u][v];
		}
	}
}

int main()
{
	int s, t, k, v;
	while(cin>>n>>s>>t){
		memset(G, -1, sizeof(G));
		for(int i = 1; i <= n; i++){
			cin>>k;
			for(int j = 0; j < k; j++){
				cin>>v;
				if(j==0)G[i][v] = 0;
				else G[i][v] = 1;
			}
		}
		dijsktra(s);
		if(dist[t]==INF)cout<<-1<<endl;
		else cout<<dist[t]<<endl;
	}

	return 0;
}
