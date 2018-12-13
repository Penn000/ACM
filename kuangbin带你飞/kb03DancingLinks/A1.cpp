#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <stack>
#include <queue>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long
#define PI 3.1415926535897932626
using namespace std;
int gcd(int a, int b) {return a % b == 0 ? b : gcd(b, a % b);}
const int INF = 0x3f3f3f3f;
const int MAXN = 1010;
const int MAXM = 1010;
const int MAXNODE = MAXN * MAXN;
int g[MAXN];
struct DLX
{
    int n,m,sz;
    int U[MAXNODE],D[MAXNODE],R[MAXNODE],L[MAXNODE],Row[MAXNODE],Col[MAXNODE];
    int H[MAXN],S[MAXM];
    int ansd,ans[MAXN];

    void init(int _n,int _m)
    {
        n = _n;
        m = _m;
        for(int i = 0 ; i <= m ; i++)
        {
            S[i] = 0;
            U[i] = D[i] = i;
            L[i] = i - 1;
            R[i] = i + 1;
        }
        R[m] = 0; L[0] = m;
        sz = m;
        for(int i = 1 ; i <= n ; i++) H[i] = -1;
    }

    void link(int r,int c)
    {
        ++S[Col[++sz] = c];
        Row[sz] = r;
        D[sz] = D[c];
        U[D[c]] = sz;
        U[sz] = c;
        D[c] = sz;
        if(H[r] < 0)H[r] = L[sz] = R[sz] = sz;
        else
        {
            R[sz] = R[H[r]];
            L[R[H[r]]] = sz;
            L[sz] = H[r];
            R[H[r]] = sz;
        }
    }

    void Remove(int c)
    {
        L[R[c]] = L[c]; R[L[c]] = R[c];
        for(int i = D[c] ; i != c ; i = D[i])
            for(int j = R[i] ; j != i ; j = R[j])
            {
                U[D[j]] = U[j];
                D[U[j]] = D[j];
                --S[Col[j]];
            }
    }

    void resume(int c)
    {
        for(int i = U[c] ; i != c ; i = U[i])
            for(int j = L[i] ; j != i ; j = L[j])
                ++S[Col[U[D[j]] = D[U[j]] = j]];
        L[R[c]] = R[L[c]] = c;
    }

    bool Dance(int d)
    {
        if(R[0] == 0)
        {
            printf("%d ",d);
            for (int i = 0 ; i < d ; i++)
                printf("%d%c",ans[i],i == d - 1 ? '\n' : ' ');
            return true;
        }
        int c = R[0];
        for(int i = R[0] ; i != 0 ; i = R[i])
            if(S[i] < S[c])
                c = i;
        Remove(c);
        for(int i = D[c] ; i != c ; i = D[i])
        {
            ans[d] = Row[i];
            for(int j = R[i] ; j != i ; j = R[j]) Remove(Col[j]);
            if(Dance(d + 1))return true;
            for(int j = L[i] ; j != i ; j = L[j]) resume(Col[j]);
        }
        resume(c);
        return false;
    }
};

DLX slover;
int N,M;

int main()
{
    //freopen("sample.txt","r",stdin);
    while (scanf("%d%d",&N,&M) != EOF)
    {
        slover.init(N,M);
        for (int i = 1 ; i <= N ; i++)
        {
            int cnt;
            scanf("%d",&cnt);
            while(cnt--)
            {
                int x;
                scanf("%d",&x);
                slover.link(i,x);
            }
        }
        if (!slover.Dance(0)) puts("NO");
        putchar('\n');
    }
    return 0;
}
