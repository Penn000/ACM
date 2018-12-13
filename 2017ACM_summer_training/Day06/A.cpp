//2017-08-06
#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define mid ((st[id].l+st[id].r)>>1)
#define lson (id<<1)
#define rson ((id<<1)|1)

using namespace std;

const int N = 150000;
int arr[N];
struct Node{
    int l, r, OR;
}st[N<<3];

void build(int id, int l, int r, bool op)
{
    st[id].l = l; st[id].r = r;
    if(l == r){
        st[id].OR = arr[l];
        return;
    }
    build(lson, l, mid, !op);
    build(rson, mid+1, r, !op);
    if(op)st[id].OR = st[lson].OR | st[rson].OR;
    else st[id].OR = st[lson].OR ^ st[rson].OR;
}

void update(int id, int pos, int w, bool op)
{
    if(st[id].l == pos && st[id].r == pos){
        st[id].OR = w;
        return;
    }
    if(pos <= mid)update(lson, pos, w, !op);
    else if(pos > mid)update(rson, pos, w, !op);
    if(op)st[id].OR  = st[lson].OR | st[rson].OR;
    else st[id].OR  = st[lson].OR ^ st[rson].OR;
}

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m)!=EOF)
    {
        int deep = n;
		n = (1<<n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        build(1, 1, n, deep&1 ? 1 : 0);
        int a, b;
        while(m--){
            scanf("%d%d", &a, &b);
            update(1, a, b, deep&1 ? 1 : 0);
            printf("%d\n", st[1].OR);
	    }
    }

    return 0;
}
