#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 1<<30
#define maxn 1010
#define maxm 50000
using namespace std;

int v[maxm],Next[maxm],w[maxm];
int first[maxn],d[maxn],q[maxn];
int e,S,T;

void init(){
	e = 0;
	memset(first,-1,sizeof(first));
}

void add_edge(int a,int b,int c){
	v[e] = b;Next[e] = first[a];w[e] = c;first[a] = e++;
	v[e] = a;Next[e] = first[b];w[e] = 0;first[b] = e++;
}

int bfs(){
	int rear = 0;
	memset(d,-1,sizeof(d));
	d[S] = 0;q[rear++] = S;
	for(int i = 0;i < rear;i++){
		for(int j = first[q[i]];j != -1;j = Next[j])
		  if(w[j] && d[v[j]] == -1){
			  d[v[j]] = d[q[i]] + 1;
			  q[rear++] = v[j];
			  if(v[j] == T)   return 1;
		  }
	}
	return 0;
}

int dfs(int cur,int maxflow){
	if(cur == T)    return maxflow;
	for(int i = first[cur];i != -1;i = Next[i]){
		if(w[i] && d[v[i]] == d[cur] + 1)
		  if(int t = dfs(v[i],min(maxflow,w[i]))){
			  w[i] -= t;w[i^1] += t;
			  return t;
		  }
	}
	return 0;
}

int dinic(){
	int ans = 0;
	while(bfs()){
		ans += dfs(S,INF);
	}
	return ans;
}

int main()
{
	int n,m,T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d%d",&n,&m);
		scanf("%d%d", &S, &T);
		for(int i = 0;i < m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			add_edge(a,b,c);
		}
		dinic();
		for(int i = 0;i < e;i += 2){
			if(w[i] == 0){
				w[i] = 1;
				w[i^1] = 0;
			}else{
				w[i] = INF;
				w[i^1] = 0;
			}
		}
		printf("%d\n",dinic());
	}
	return 0;

}
