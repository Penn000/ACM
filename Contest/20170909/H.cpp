#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 10004;
const int MAXM = 100005;

struct Edge{
	int t, len, next;

}e[MAXM];

int top, n, m, head[MAXN];
int du[MAXN];
int dp[MAXN];
bool vis[MAXN];
int T;
queue<int> q;

void add(int f, int t, int len){
	e[top].t = t;
	e[top].len = len;
	e[top].next = head[f];
	head[f] = top++;
}

void bfs(){
	//memset(vis, false, sizeof(vis));
	for(int i=1; i<=n; i++){
		if(du[i] == 0){
			q.push(i);
			dp[i] = 0;
			//vis[i] = true;
		}
	}
	while(!q.empty()){
		int fr = q.front();
		q.pop();
		//vis[fr] = false;
		for(int i=head[fr]; i!=-1; i=e[i].next){
			int t = e[i].t, len = e[i].len;
			du[t]--;
			dp[t] = max(dp[t], len+dp[fr]);
			if(du[t] == 0){
				q.push(t);
			}
		}
	}
}

int main(){
	scanf("%d", &T);
	while(T--){
		memset(head, -1, sizeof(head));
		memset(du, 0, sizeof(du));
		memset(dp, 0, sizeof(dp));
		top = 0;
		scanf("%d%d", &n, &m);
		int f, t, len;
		for(int i=0; i<m; i++){
			scanf("%d%d%d", &f, &t, &len);
			add(f, t, len);
			du[t]++;
		}
		bfs();
		int ans = 0;
		for(int i=1; i<=n; i++){
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;

}
