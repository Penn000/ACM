#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int mod = 1000000000 + 7;
const int INF = 1000000000 + 7;
const int maxn = 50000 + 10;
int T,n,m,p[maxn],ra[maxn],edge[maxn],vis[maxn];
struct node {
    int a, b, c;
    bool operator < (const node& rhs) const {
        return c < rhs.c;
    }
}a[100000 + 10];
int _find(int x) { return p[x] == x ? x : _find(p[x]); }
void Union(int a, int b, int c) {
    int x = _find(a);
    int y = _find(b);
    if(x == y) return ;
    if(ra[x] < ra[y]) {
        p[x] = y;
        edge[x] = c;
    }
    else {
        p[y] = x;
        edge[y] = c;
        if(ra[x] == ra[y]) ra[x]++;
    }
}
void pre() {
    sort(a, a+m);
    for(int i=1;i<=n;i++) {
        p[i] = i;
        ra[i] = 0;
        vis[i] = -1;
    }
    for(int i=0;i<m;i++) {
        Union(a[i].a,a[i].b,a[i].c);
    }
}
int query(int x, int y) {
    int ans1 = 0, ans2 = -1;
    int cur = x;
    while(true) {
        vis[cur] = ans1;
        if(cur == p[cur]) break;
        ans1 = max(ans1, edge[cur]);
        cur = p[cur];
    }
    cur = y;
    while(true) {
        if(vis[cur] >= 0) {
            ans2 = max(ans2, vis[cur]); break;
        }
        if(cur == p[cur]) break;
        ans2 = max(ans2, edge[cur]);
        cur = p[cur];
    }
    cur = x;
    while(true) {
        vis[cur] = -1;
        if(cur == p[cur]) break;
        cur = p[cur];
    }
    return ans2;
}
int u,v,q,kase=0;
int main() {
    while(~scanf("%d%d",&n,&m)) {
        for(int i=0;i<m;i++) {
            scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
        }
        if(kase) printf("\n");
        else ++kase;
        pre();
        scanf("%d",&q);
        while(q--) {
            scanf("%d%d",&u,&v);
            printf("%d\n",query(u, v));
        }
    }
    return 0;
}

