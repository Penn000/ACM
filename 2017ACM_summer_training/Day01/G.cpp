//2017-08-01
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;
const int M = 1010;
int w[N], vis[N], b[M], n, m;

int main(){
    while(scanf("%d%d", &n, &m)!=EOF){
        for(int i = 0; i < n; i++)
            scanf("%d", &w[i]);
        for(int i = 0; i < m; i++)
            scanf("%d", &b[i]);
        int ans = 0;
        for(int i = 1; i < m; i++){
            memset(vis, 0, sizeof(vis));
            for(int j = i-1; j >= 0; j--){
                if(b[i] == b[j])break;
                if(!vis[b[j]-1]){
                    ans += w[b[j]-1];
                    vis[b[j]-1] = 1;
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}