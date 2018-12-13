#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 210;
char G[N][N];
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool vis[N][N];
struct Node{
	int x, y;
	Node(int _x, int _y):x(_x), y(_y){}
};

void bfs(int x, int y, int op){
	Node node(x, y);
	memset(vis, 0, sizeof(vis));
	vis[x][y] = op+1;
    G[x][y] = '#';
	queue<Node> q;
	q.push(node);
	while(!q.empty()){
		Node a = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int nx = a.x + dx[i];
			int ny = a.y + dy[i];
			if(nx>=0 && nx <= n+1 && ny>=0 && ny <= m+1 && !vis[nx][ny] && G[nx][ny] == '0'+op){
				Node tmp(nx, ny);
				q.push(tmp);
				vis[nx][ny] = op+1;
                G[nx][ny] = '#';
			}
		}
	}
}

int main()
{
	freopen("data1006.txt", "r", stdin);
	while(scanf("%d%d", &n, &m)!=EOF){
        for(int i = 0; i <= m+5; i++){
            G[0][i] = '0';
            G[n+1][i] = '0';
        }
		for(int i = 1; i <= n; i++){
		  	scanf("%s", G[i]+1);
		}
        for(int i = 1; i <= n+5; i++){
            G[i][0] = '0';
            G[i][m+1] = '0';
            G[i][m+2] = '\0';
        }
        bool fg1 = false;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < m; j++){
                if(G[i][j] == '1'){
                    bfs(i, j, 1);
                    fg1= true;
                }
                if(fg1)break;
            }
            if(fg1)break;
        }
        if(!fg1){
            printf("-1\n");
            continue;
        }
		// for(int i = 0; i <= n; i++){
		// 	for(int j = 0; j <= m; j++)
		// 	  cout<<G[i][j];
		// 	cout<<endl;
		// }
        bool fg2 = false;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < m; j++){
                if(G[i][j] == '0')
                {
                    bfs(i, j, 0);
                    fg2 = true;
                }
                if(fg2)break;
            }
            if(fg2)break;
        }
        // cout<<endl;
        // for(int i = 1; i <= n; i++){
		// 	for(int j = 0; j <= m; j++)
		// 	  cout<<G[i][j];
		// 	cout<<endl;
		// }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(G[i][j] == '0'){
                    bfs(i, j, 0);
                    cnt++;
                }else if(G[i][j] == '1'){
                    cnt = 100000000;
                    break;
                }
            }
        }
		if(!fg2)cnt = 0;
        if(cnt == 0)printf("1\n");
        else if(cnt == 1)printf("0\n");
		else printf("-1\n");
	}

	return 0;
}
