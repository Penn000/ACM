#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int G[N][N], n, m;

int fun(int x, int y){
	int cnt = 0;
	if(x==0 || G[x-1][y]==0)cnt++;
	if(y==0 || G[x][y-1]==0)cnt++;
	if(x==n-1 || G[x+1][y]==0)cnt++;
	if(y==m-1 || G[x][y+1]==0)cnt++;
	return cnt;
}

int main()
{
	while(cin>>n>>m){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin>>G[i][j];
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++)
		  for(int j = 0; j < m; j++)
			if(G[i][j]==1)
			  ans+=fun(i, j);

		cout<<ans<<endl;
	}

	return 0;
}
