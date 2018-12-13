#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define lson (id<<1)
#define rson ((id<<1)|1)

using namespace std;

const int N = 100010;
const int LEN = 20;//块的大小
vector<int> G[N];
int n, m, label, answer[N];

//树链剖分
int arr[N];//arr[i]表示节点i的权值
int fa[N];//fa[i]表示节点i的父亲
int son[N];//son[i]表示节点i的重儿子
int top[N];//top[i]表示节点i所在重链的顶端节点
int size[N];//size[i]表示以节点i为根的子树的节点数
int deep[N];//deep[i]表示节点i的深度
int postion[N];//postion[i]表示节点i在线段树中的位置
int trID[N];//trID[i]表示节点i在剖分后的新编号

void dfs1(int u, int father){
    fa[u] = father;
    son[u] = 0;
    size[u] = 1;
    for(auto v: G[u]){
        if(v == father)continue;
        deep[v] = deep[u]+1;
        dfs1(v, u);
        size[u] += size[v];
        if(size[v] > size[son[u]])
            son[u] = v;
    }
}

void dfs2(int u, int ancestor){
    top[u] = ancestor;
    postion[u] = ++label;
    trID[label] = u;
    if(son[u])
        dfs2(son[u], ancestor);
    for(auto v: G[u]){
        if(v == fa[u] || v == son[u])
            continue;
        dfs2(v, v);
    }
}

//最近公共祖先
inline int lca(int u, int v){
    while(top[u] ^ top[v]){
        if(deep[top[u]] < deep[top[v]])
            swap(u, v);
        u = fa[top[u]];
    }
    return deep[u] < deep[v] ? u : v;
}

//线段树
struct Node{
    int l, r, v;
}tree[N<<2];
int nS[N], qL[N], qR[N];

void build(int id, int l , int r){
    tree[id].l = l;
    tree[id].r = r;
    if(l == r){
        tree[id].v = arr[trID[nS[l]]];
        return;
    }
    int mid = (l+r)>>1;
    build(lson, l, mid);
    build(rson, mid+1, r);
    tree[id].v = tree[lson].v ^ tree[rson].v;
}

int query(int id, int l, int r){
    if(tree[id].l == l && tree[id].r == r)
        return tree[id].v;
    int mid = (tree[id].l+tree[id].r)>>1;
    if(l > mid)return query(rson, l, r);
    if(r <= mid)return query(lson, l, r);
    return query(lson, l, mid) ^ query(rson, mid+1, r);
}

inline int cal(int l, int r, int k){
    if(qL[k] > qR[k])return 0;
    l = lower_bound(nS+qL[k], nS+qR[k]+1, l)-nS;
    r = upper_bound(nS+qL[k], nS+qR[k]+1, r)-nS-1;
    if(l <= r)return query(1, l, r);
    else return 0;
}

int question(int u, int v, int k){
    int ans = 0, f = lca(u, v);
    int uk = (deep[u] + 1)%k;
    int vk = (deep[f] + (k - (deep[u]-deep[f]+1)%k)) % k;
    while(top[u] ^ top[v]){
        if(deep[top[u]] > deep[top[v]]){
            ans = ans ^ cal(postion[top[u]], postion[u], uk);
            u = fa[top[u]];
        }else{
            ans = ans ^ cal(postion[top[v]], postion[v], vk);
            v = fa[top[v]];
        }
    }
    if(deep[u] > deep[v])
        ans = ans ^ cal(postion[v], postion[u], uk);
    else 
        ans = ans ^ cal(postion[u], postion[v], vk);
    return ans;
}

vector<int> block[LEN];
vector< pair< pair<int, int>, int > > qs[LEN+5];
vector< pair< pair<int, int>, pair<int, int> > > qy[N];
void solve(int k){
    for(int i = 1; i <= n; i++){
        int u = trID[i];
        block[deep[u]%k].push_back(u);
    }
    label = 0;
    for(int i = 0; i < k; i++){
        qL[i] = label + 1;
        for(auto x: block[i])
            nS[++label] = postion[x];
        qR[i] = label;
    }
    build(1, 1, n);
    for(auto &x: qs[k])
        answer[x.second] = question(x.first.first, x.first.second, k);
    for(int i = 0; i < k; i++)
        block[i].clear();
    qs[k].clear();
}

int sk[N], tp;//sk为栈， tp为栈顶指针

void dfs(int u){
    sk[++tp] = u;
    for(auto &x: qy[u]){
        for(int i = tp-x.first.second;
            i > 0 && deep[sk[i]] >= deep[x.first.first];
            i -= x.second.first)
            answer[x.second.second] = answer[x.second.second] ^ arr[sk[i]];
    }
    qy[u].clear();
    for(auto v : G[u]){
        if(v ^ fa[u])
            dfs(v);
    }
    --tp;
}

int main()
{
    //freopen("dataB.txt", "r", stdin);
    while(~scanf("%d%d", &n, &m)){
        int u, v, k;
        for(int i = 1; i <= n; i++)
            G[i].clear();
        for(int i = 1; i <= n-1; i++){
              scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i = 1; i <= n; i++)
              scanf("%d", &arr[i]);
        label = 0;
        dfs1(1, 1);
        dfs2(1, 1);
        //debug();
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &u, &v, &k);
            if(k >= LEN){
                int f = lca(u, v);
                int d = (deep[u]+deep[v]-2*deep[f]+1)%k;
                if(u ^ f)
                    qy[u].push_back({ {f, k-1}, {k, i} });
                if(v ^ f)
                    qy[v].push_back({ {f, d}, {k, i} });
            }else{
                qs[k].push_back({ {u, v}, i });
            }
        }
        memset(answer, 0, sizeof(answer));
        for(int i = 1; i < LEN; i++)
            if(qs[i].size())
                solve(i);
        tp = 0;
        dfs(1);
        for(int i = 0; i < m; i++)
            printf("%d\n", answer[i]);
    }

    return 0;
}
