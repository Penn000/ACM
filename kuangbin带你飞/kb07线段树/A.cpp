//2016-05-13
#include<iostream>
#include<string>
#include<cstdio>  
#include<cstring>  
#include<algorithm>
using namespace std;

struct Node{
    int l, r, sum;
}A[500050];

void Pushup(int root)
{
    A[root].sum = A[root<<1].sum + A[root<<1|1].sum;
    return ;
}

void Build(int l, int r, int root)
{
    A[root].l = l;
    A[root].r = r;
    if(l == r)
    {
        scanf("%d", &A[root].sum);
        return;
    }
    int mid = (l + r)>>1;
    Build(l, mid, root<<1);
    Build(mid+1, r, root<<1|1);
    Pushup(root);
    return ;
}

void update(int l, int r, int root , int k)
{
    if(l == A[root].l && r == A[root].r)
    {
        A[root].sum += k;
        return ;
    }
    int mid = (A[root].l + A[root].r) >> 1;
    if(r <= mid)
        update(l, r, root<<1, k);
    else if(l > mid)
        update(l, r, root<<1|1, k);
    else
    {
        update(l, mid, root<<1, k);
        update(mid+1, r, root<<1|1, k);
    }
    Pushup(root);
    return ;    
}

int Query(int l, int r, int root)
{
    if(l == A[root].l && r == A[root].r)
        return A[root].sum;
    int mid = (A[root].l + A[root].r) >> 1;
    int ans = 0;
    if(r <= mid)
        ans += Query(l, r, root<<1);
    else if(l > mid)
        ans += Query(l, r, root<<1|1);
    else
        ans += Query(l, mid, root<<1) + Query(mid+1, r, root<<1|1);
    return ans;
}

int main ()
{
    int T, cas, N;
    int l, k;
    string OP, A = "Add", S = "Sub", Q = "Query", E = "End";
    cas = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        Build(1, N, 1);
        printf("Case %d:\n", ++cas);
        while(cin>>OP)
        {
            if(OP == A)
            {
                scanf("%d %d", &l, &k);
                update(l, l, 1, k);
            }
            else if(OP == S)
            {
                scanf("%d %d", &l, &k);
                update(l, l, 1, -k);
            }
            else if(OP == Q)
            {
                scanf("%d %d", &l, &k);
                printf("%d\n", Query(l, k, 1));
            }
            else if(OP == E)
                break;
        }
    }
    return 0;
}
