#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll n, m;
int vis[150][300];
int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, -1, 1};

void dfs(int x, int y, int dir){
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if(nx<1||nx>n||ny<1||ny>m)return;
	vis[nx][ny]++;
	if((nx==n&&ny==m) || (nx==n&&ny==1) || (nx==1&&ny==m) || (nx==1&&ny==1))return;
	else if(nx == n){
		if(dir == 0)dfs(nx, ny, 3);
		if(dir == 1)dfs(nx, ny, 2);
	}else if(nx == 1){
		if(dir == 2)dfs(nx, ny, 1);
		if(dir == 3)dfs(nx, ny, 0);
	}else if(ny == m){
		if(dir == 3)dfs(nx, ny, 2);
		if(dir == 0)dfs(nx, ny, 1);
	}else if(ny == 1){
		if(dir == 1)dfs(nx, ny, 0);
		if(dir == 2)dfs(nx, ny, 3);
	}else{
		dfs(nx, ny, dir);
	}
}

void work(){
	memset(vis, 0, sizeof(vis));
	vis[1][1]++;
	dfs(1, 1, 0);
	int cnt = 0;
	for(int i = 1; i <= n; i++){
	  	for(int j = 1; j <= m; j++)
		  	if(vis[i][j] == 1)
			  	cnt++;
	}
	if(m%2 == 0)cout<<"& ";
	if((m-n)%(n-1) == 0)cout<<"##### ";
	cout<<n<<" "<<m<<" >>> "<<cnt<<endl;
}

int main()
{
	//freopen("output.txt", "w", stdout);
	for(n = 2; n < 20; n++){
		if(n%2 == 0)continue;
		for(m = n; m < 50; m++)
		  	work();
		cout<<endl;
	}
	while(cin>>n>>m){
		if(n > m)swap(n, m);
		work();
//		if(m == n){
//			cout<<m<<endl;
//		}else if((m-n)%(n-1) == 0){
//			cout<<m<<endl;
//		}else if(m > 2*n-1){
//			cout<<(m+1)/2*2+n-2<<endl;
//		}else{
//
//		}
	}

	return 0;
}
