#include <cstdio>    
#include <cstring>    
#include <vector>    
#include <iostream>
#include <algorithm>    
using namespace std;    
    
const int N = 500010;    
struct edge    
{    
    int to, next;    
}g[N*2];    
struct node    
{    
    int l, r, val, mark;    
}s[N*4];    
int head[N], in[N], out[N], fat[N];    
int n, cnt, num;    
bool f;    
void add_edge(int v, int u)    
{    
    g[cnt].to = u;    
    g[cnt].next = head[v];    
    head[v] = cnt++;    
}    
void dfs(int v, int fa)    
{    
    in[v] = ++num;    
    for(int i = head[v]; i != -1; i = g[i].next)    
    {    
        int u = g[i].to;    
        if(u != fa)    
        {    
            fat[u] = v;    
            dfs(u, v);    
        }    
    }    
    out[v] = num;    
}    
void push_up(int k)    
{    
    if(s[k<<1].val == 1 && s[k<<1|1].val == 1) s[k].val = 1;/* 子孙全有水则此节点也有水，否则便为空 */    
    else s[k].val = 0;    
}    
void push_down(int k)    
{    
    if(s[k].mark)    
    {    
        s[k<<1].val = s[k<<1|1].val = s[k].mark;    
        s[k<<1].mark = s[k<<1|1].mark = s[k].mark;    
        s[k].mark = 0;    
    }    
}    
void build(int l, int r, int k)    
{    
    s[k].l = l, s[k].r = r, s[k].val = 0, s[k].mark = 0;    
    if(l == r) return;    
    int mid = (l + r) >> 1;    
    build(l, mid, k << 1);    
    build(mid + 1, r, k << 1|1);    
}    
void update(int l, int r, int c, int k)    
{    
    if(l == 0) return;    
    if(l <= s[k].l && s[k].r <= r)    
    {    
        if(s[k].val == 0) f = true; /* 其子孙中有空点，标记，之后把父节点置空 */    
        s[k].val = c;    
        if(c == 1) s[k].mark = c;    
        return;    
    }    
    push_down(k);    
    int mid = (s[k].l + s[k].r) >> 1;    
    if(l <= mid) update(l, r, c, k << 1);    
    if(r> mid) update(l, r, c, k << 1|1);    
    push_up(k);    
}    
void query(int l, int r, int k)    
{    
    if(l <= s[k].l && s[k].r <= r)    
    {    
        if(s[k].val == 0) f = true;/* 其子孙中有空点，被查询的点也是空点 */  
        return;    
    }    
    push_down(k);    
    int mid = (s[k].l + s[k].r) >> 1;    
    if(l <= mid) query(l, r, k << 1);    
    if(r> mid) query(l, r, k << 1|1);    
}    
int main ()    
{    
	freopen("inputF.txt", "r", stdin);
    int a, b;    
    scanf("%d", &n);    
    cnt = num = 0;    
    memset(head, -1, sizeof head);    
    for(int i = 1; i <= n - 1; i++)    
    {    
        scanf("%d%d", &a, &b);    
        add_edge(a, b);    
        add_edge(b, a);    
    }    
    fat[1] = 0;    
    dfs(1, 0);    
	for(int i = 1; i <= n; i++)
	  	cout<<in[i]<<" "<<out[i]<<endl;
    build(1, num, 1);    
    int m;    
    scanf("%d", &m);    
    while(m--)    
    {    
        scanf("%d%d", &a, &b);    
        if(a == 1)    
        {    
            f = false;    
            update(in[b], out[b], 1, 1);    
            if(f) update(in[fat[b]], in[fat[b]], 0, 1);    
        }    
        else if(a == 2) update(in[b], in[b], 0, 1);    
        else    
        {    
            f = false;    
            query(in[b], out[b], 1);    
            if(f) printf("0\n");    
            else printf("1\n");    
        }    
    }    
    return 0;    
}
