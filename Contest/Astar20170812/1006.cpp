#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 110;
char G[N][N];
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool vis[N][N];
int kuai[N];
struct Node{
	int x, y;
	Node(int _x, int _y):x(_x), y(_y){}
};

void bfs(int x, int y){
	Node node(x, y);
	memset(vis, 0, sizeof(vis));
	vis[x][y] = 1;
	G[x][y] = '0';
	queue<Node> q;
	q.push(node);
	while(!q.empty()){
		Node a = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int nx = a.x + dx[i];
			int ny = a.y + dy[i];
			if(nx>=0 && nx < n && ny>=0 && ny < m && !vis[nx][ny] && G[nx][ny] == '1'){
				Node tmp(nx, ny);
				q.push(tmp);
				vis[nx][ny] = 1;
				G[nx][ny] = '0';
			}
		}
	}
}

int main()
{
	freopen("data1006.txt", "r", stdin);
	while(scanf("%d%d", &n, &m)!=EOF){
		for(int i = 0; i < n; i++){
		  	scanf("%s", G[i]);
		}
		bool ok = true;
		int ans = -1;
		/*
		for(int i = 0; i < m; i++){
			if(G[0][i] == '1' || G[n-1][i] == '1'){
				ok = false;
				ans = -1;
				break;
			}
		}
		for(int i = 0; i < n; i++){
			if(G[i][0] == '1' || G[i][m-1] == '1'){
				ok = false;
				ans = -1;
				break;
			}
		}*/
		//cout<<ok<<endl;
		bool fg = false;
		if(ok){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					if(fg && G[i][j]=='1'){
						ok=false;
						ans = -1;
						break;
					}
					if(G[i][j] == '1'){
						bfs(i, j);
						fg = true;
					}
				}
				if(!ok)break;
			}/*
			for(int i = 0; i < n; i++){
				for(int j= 0; j < m; j++)
				  cout<<vis[i][j];
				cout<<endl;
			}*/
			if(!fg)ok = false;
			if(!ok){
				printf("-1\n");
				continue;
			}
			memset(kuai, 0, sizeof(kuai));
			for(int i = 0 ; i < n; i++){
				int cnt = 0;
				for(int j = 0; j < m; j++){
					if(vis[i][j] == 1){
						while(vis[i][j] == 1){
							j++;
						}
						cnt++;
						j--;
					}
				}
				kuai[i] = cnt;
			}
			for(int i = 0; i < n; i++)cout<<kuai[i]<<" ";
			for(int i = 0; i < n; i++){
				while(kuai[i] == 0)i++;
				if(kuai[i] == 1){
					while(kuai[i] == 1 && i < n){
						i++;
					}
				}
				if(kuai[i] == 2){
					while(kuai[i] == 2 && i<n)i++;
				}
				if(kuai[i] == 1)break;
				while(kuai[i] == 0 && i < n){
					i++;
				}
				ans = 1;
			}
			if(ans == -1){
				for(int i = 0; i < n; i++){
					while(kuai[i] == 0)i++;
					if(kuai[i] == 1){
						while(kuai[i] == 1 && i < n)i++;
					}
					if(kuai[i] == 2){
						while(kuai[i] == 2 && i < n)i++;
						if(kuai[i] == 1){
							while(kuai[i] == 1 < n)i++;
							if(i == n || kuai[i] == 0){
								ans = 0;
								break;
							}else{
								ans = -1;
								break;
							}
						}else{
							ans = -1;
							break;
						}
					}else{
						ans = -1;
						break;
					}
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
