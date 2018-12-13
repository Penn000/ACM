//2017-08-17
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 310;
int G[N][N], vis[N][N], n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
struct Node{
	int x, y, h;
	bool operator<(const Node X) const{
		return h > X.h;
	}
	Node(int _x, int _y, int _h):x(_x), y(_y), h(_h){}
};
priority_queue<Node> pq;

void work(){
	int ans = 0, cnt = 0;
	while(!pq.empty()){
		Node node = pq.top();
		pq.pop();
		for(int i = 0; i < 4; i++){
			int nx = node.x + dx[i];
			int ny = node.y + dy[i];
			if(nx<0 || nx>=n || ny<0 || ny>=m || vis[nx][ny])continue;
			vis[nx][ny] = 1;
			if(G[nx][ny] >= node.h){
				Node tmp(nx, ny, G[nx][ny]);
				pq.push(tmp);
			}else{
				ans += node.h-G[nx][ny];
				Node tmp(nx, ny, node.h);
				pq.push(tmp);
			}
			cnt++;
		}
		if(cnt >= (n-2)*(m-1))break;
	}
	printf("%d\n", ans);
}

int main()
{
	//freopen("input2227.txt", "r", stdin);
	while(scanf("%d%d", &m, &n) != EOF){
		while(!pq.empty())pq.pop();
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < n; i++)
		  for(int j = 0; j < m; j++){
			  scanf("%d", &G[i][j]);
			  if(i == 0 || i == n-1 || j == 0 || j == m-1){
					Node node(i, j, G[i][j]);
					pq.push(node);
					vis[i][j] = 1;
			  }				
		  }
		work();
	}

	return 0;
}
