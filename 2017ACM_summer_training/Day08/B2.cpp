#include <bits/stdc++.h>
#define ls (o << 1)
#define rs (o << 1 | 1)
#define FI first
#define SE second
using namespace std;

const int N = 100005;

const int MAGIC = 20;

int a[N];

vector <int> G[N];

int seq[N], tin[N], fa[N], dep[N], top[N], son[N], sz[N], label;

void dfs1(int u, int father) {
    fa[u] = father;
    son[u] = 0; sz[u] = 1;
    for(auto v : G[u]) {
        if(v == father) continue;
        dep[v] = dep[u] + 1;
        dfs1(v, u);
        sz[u] += sz[v];
        if(sz[v] > sz[son[u]])
            son[u] = v;
    }
}

void dfs2(int u, int anc) {
    top[u] = anc; tin[u] = ++ label;
    seq[label] = u;
    if(son[u]) dfs2(son[u], anc);
    for(auto v : G[u]) {
        if(v == fa[u] || v == son[u])
            continue;
        dfs2(v, v);
    }
}

inline int lca(int u, int v) {
    while(top[u] ^ top[v]) {
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}

vector < pair < pair <int, int>, int> > qs[MAGIC + 5];

int n, m, ans[N];

int nS[N], cL[N], cR[N];

struct Seg {
    int l, r, v;
} T[N << 2];

void build(int o, int l, int r) {
    T[o].l = l; T[o].r = r;
    if(l == r) { T[o].v = a[seq[nS[l]]]; return; }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    T[o].v = max(T[ls].v, T[rs].v);
}

int query(int o, int l, int r) {
    if(T[o].l == l && T[o].r == r) return T[o].v;
    int mid = (T[o].l + T[o].r) >> 1;
    if(r <= mid) return query(ls, l, r);
    if(l > mid) return query(rs, l, r);
    return max(query(ls, l, mid), query(rs, mid + 1, r));
}

inline int cal(int l, int r, int k) {
    if(cL[k] > cR[k]) return 0;
    l = lower_bound(nS + cL[k], nS + cR[k] + 1, l) - nS;
    r = upper_bound(nS + cL[k], nS + cR[k] + 1, r) - nS - 1;
    return l <= r ? query(1, l, r) : 0;
}

int ask(int u, int v, int k) {
    int ret = -1, f = lca(u, v);
    int uk = (dep[u] + 1) % k;
    int vk = (dep[f] + (k - (dep[u] - dep[f] + 1) % k)) % k;
    while(top[u] ^ top[v]) {
        if(dep[top[u]] > dep[top[v]]) {
            ret = max(ret, cal(tin[top[u]], tin[u], uk));
            u = fa[top[u]];
        } else {
            ret = max(ret, cal(tin[top[v]], tin[v], vk));
            v = fa[top[v]];
        }
    }
    if(dep[u] > dep[v]) {
        ret = max(ret, cal(tin[v], tin[u], uk));
    } else {
        ret = max(ret, cal(tin[u], tin[v], vk));
    }
    return ret;
}

vector <int> E[MAGIC];

void small_case(int k) {
    for(int i = 1; i <= n; ++ i) {
        int u = seq[i];
        E[dep[u] % k].push_back(u);
    }
    label = 0;
    for(int i = 0; i < k; ++ i) {
        cL[i] = label + 1;
        for(auto x : E[i])
            nS[++ label] = tin[x];
        cR[i] = label;
    }
    build(1, 1, n);
    for(auto &x : qs[k])
        ans[x.SE] = ask(x.FI.FI, x.FI.SE, k);
    for(int i = 0; i < k; ++ i)
        E[i].clear();
    qs[k].clear();
}

vector < pair < pair <int, int>, pair <int, int> > > qy[N];

int sk[N], tp;

void dfs(int u) {
    sk[++ tp] = u;
    for(auto &x : qy[u]) {
        for(int i = tp - x.FI.SE; i > 0 && dep[sk[i]] >= dep[x.FI.FI]; i -= x.SE.FI)
            ans[x.SE.SE] = max(ans[x.SE.SE], a[sk[i]]);
    }
    qy[u].clear();
    for(auto v : G[u])
        if(v ^ fa[u])
            dfs(v);
    -- tp;
}

int main() {
    int T, cas = 1;
    scanf("%d", &T);
    while(T --) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++ i) {
            scanf("%d", a + i);
        }
        for(int u, v, i = 1; i < n; ++ i) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        memset(ans, 0, m * sizeof(int));
        label = 0;
        dfs1(1, 1); dfs2(1, 1);
        for(int i = 0; i < m; ++ i) {
            int u, v, k;
            scanf("%d%d%d", &u, &v, &k);
            if(k >= MAGIC) {
                int f = lca(u, v), d = (dep[u] + dep[v] - 2 * dep[f] + 1) % k;
                if(u ^ f) qy[u].push_back( { {f, k - 1}, {k, i} } );
                if(v ^ f) qy[v].push_back( { {f, d}, {k, i} } );
            } else {
                qs[k].push_back( { {u, v}, i } );
            }
        }
        for(int i = 1; i < MAGIC; ++ i)
            if(qs[i].size())
                small_case(i);
        tp = 0; dfs(1);
        printf("Case #%d:\n", cas ++);
        for(int i = 0; i < m; ++ i)
            printf("%d\n", ans[i]);
        for(int i = 1; i <= n; ++ i)
            G[i].clear();
    }
    return 0;
}
