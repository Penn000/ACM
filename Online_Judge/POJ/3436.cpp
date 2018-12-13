//2017-08-23
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int N = 110;
const int P = 20;
const int INF = 0x3f3f3f3f;
int head[N], tot;
struct Edge{
    int next, to, w;
}edge[N<<4];

void add_edge(int u, int v, int w){
    edge[tot].w = w;
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;

    edge[tot].w = 0;
    edge[tot].to = u;
    edge[tot].next = head[v];
    head[v] = tot++;
}

struct Dinic{
    int level[N], S, T;
    void init(int _S, int _T){
        S = _S;
        T = _T;
        tot = 0;
        memset(head, -1, sizeof(head));
    }
    bool bfs(){
        queue<int> que;
        memset(level, -1, sizeof(level));
        level[S] = 0;
        que.push(S);
        while(!que.empty()){
            int u = que.front();
            que.pop();
            for(int i = head[u]; i != -1; i = edge[i].next){
                int v = edge[i].to;
                int w = edge[i].w;
                if(level[v] == -1 && w > 0){
                    level[v] = level[u]+1;
                    que.push(v);
                }
            }
        }
        return level[T] != -1;
    }
    int dfs(int u, int flow){
        if(u == T)return flow;
		int fw;
        for(int i = head[u]; i != -1; i = edge[i].next){
            int v = edge[i].to, w = edge[i].w;
            if(!w || level[v] != level[u]+1 || (fw=dfs(v, min(flow, w))) <= 0)
                  continue;
            edge[i].w -= fw;
            edge[i^1].w += fw;
			return fw;
        }
        return 0;
    }
    int maxflow(){
        int flow = 0;
        while(bfs())
          flow += dfs(S, INF);
        return flow;    
    }
}dinic;

int in[N][P], out[N][P];
struct Node{
    int u, v, w;
    Node(int _u, int _v, int _w):u(_u), v(_v), w(_w){}
};

int main()
{
    std::ios::sync_with_stdio(false);
    //freopen("inputA.txt", "r", stdin);
    int n, p, w;
    while(cin>>p>>n){
        int s = 0, t = 2*n+1;
        dinic.init(s, t);
        for(int i = 1; i <= n; i++){
            cin>>w;
            add_edge(i, i+n, w);
            bool fg = true;
            for(int j = 0; j < p; j++){
                cin>>in[i][j];
                if(in[i][j] == 1)fg = false;
            }
            if(fg)add_edge(0, i, INF);
            for(int j = 0; j < p; j++)
                  cin>>out[i][j];
        }
        for(int i = 1; i <= n; i++){
            bool all_one = true;
            for(int k = 0; k < p; k++)
                  if(out[i][k] == 0){
                      all_one = false;
                    break;
                }
            if(all_one){
                add_edge(i+n, t, INF);
            }
            for(int j = 1; j <= n; j++){
                if(i == j)continue;
                bool fg = true;
                for(int k = 0; k < p; k++){
                    if((in[j][k] == 1 && out[i][k] == 0)
                    || (in[j][k] == 0 && out[i][k] == 1)){
                        fg = false;
                        break;
                    }
                }
                if(fg)add_edge(i+n, j, INF);
            }
        }
        cout<<dinic.maxflow()<<" ";
        vector<Node> vec;
        for(int u = n+1; u < 2*n+1; u++){
            for(int i = head[u]; i != -1; i = edge[i].next){
                int v = edge[i].to;
                if(v == t)continue;
                if(u-n != v && edge[i^1].w != 0){
                    Node tmp(u-n, v, edge[i^1].w);
                    vec.push_back(tmp);
                }
            }
        }
        cout<<vec.size()<<endl;
        for(int i = 0; i < vec.size(); i++)
              cout<<vec[i].u<<" "<<vec[i].v<<" "<<vec[i].w<<endl;
    }

    return 0;
}
