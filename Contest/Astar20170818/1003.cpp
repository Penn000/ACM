#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10010;
const int MOD = 1000000007;
int G[N][2], vis[N][2], ans, n;

void dfs(int x, int y, int cnt){
	if(cnt == 2*n){
		ans++;
		ans %= MOD;
		return;
	}
	for(int i = -1; i <= 1; i++){
		for(int j = -1; j <= 1; j++){
			int nx = x + i;
			int ny = y + j;
			if(nx<0||nx>=n||ny<0||ny>=2||vis[nx][ny])continue;
			vis[nx][ny] = 1;
			dfs(nx, ny, cnt+1);
			vis[nx][ny] = 0;
		}
	}
}

int main()
{
	//freopen("input1003.txt", "r", stdin);
	freopen("output1003.txt", "w", stdout);
	for(n = 1; n <= 10000; n++){
		ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 2; j++){
				memset(vis, 0, sizeof(vis));
				vis[i][j] = 1;
				dfs(i, j, 1);
			//	cout<<ans<<endl;
			}
		}
		cout<<ans<<endl;
	 }

	return 0;
}
