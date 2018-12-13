#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000;
const int INF = 0x3f3f3f3f;

int dist[N][N];

int main()
{
	int n;
	while(cin>>n){
		int u, v;
		for(int i = 1; i <= n; i++)
		  for(int j = 1; j <= n; j++)
			dist[i][j] = INF;
		for(int i = 0; i < n-1; i++){
			cin>>u>>v;
			dist[u][v] = dist[v][u] = 1;
		}
		for(int k=1;k<=n;k++)
		    for(int i=1;i<=n;i++)
        		for(int j=1;j<=n;j++)
		            if(dist[i][j]>dist[i][k]+dist[k][j])
        		    	dist[i][j]=dist[i][k]+dist[k][j];
		int sum = 0;
		for(int l = 1; l <= n; l++)
		  for(int r = l+1; r <= n; r++){
			cout<<l<<" "<<r<<" "<<dist[l][r]<<endl;
			sum += dist[l][r];
		  }
		cout<<sum<<endl;
	}

	return 0;
}
