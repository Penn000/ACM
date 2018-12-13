#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int a[9][9];
int ta[9][9];
int b[9][9];
int n,m,t,mm;
void solve()
{
    int old;
    t--;
    int numa = 0;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++)
            if(a[i][j] == 1)
                numa++;
    if(t == 0)
    {
        printf("%d\n",numa);
        return;
    }
    old = numa;
    for(int cas = 1; cas<=t; cas++)
    {
        memset(ta,0,sizeof(ta));
        for(int i = m+1; i<=n-m; i++)
            for(int j = m+1; j<=n-m; j++)
            {
                int sum = 0;
                for(int p = i-m; p<=i+m; p++)
                    for(int q = j-m; q<=j+m; q++)
                    {
                        sum+=a[p][q]*b[p-i+m+1][q-j+m+1];
                    }
                ta[i][j] = sum%2;
            }
        int num = 0;
        bool r = true;
        for(int i = 1; i<=n; i++)
            for(int j = 1; j<=n; j++)
            {
                if(a[i][j] != ta[i][j])
                {
                    r = false;
                }
                a[i][j] = ta[i][j];
                if(a[i][j] == 1)
                    num++;
            }
        if(r || num == old)
        {
            printf("%d\n",num);
            return;
        }
        old = num;
        //cout<<endl;
        //cout<<num<<endl;
        //cout<<endl;
        //cout<<endl;
    }
    int num = 0;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++)
            if(a[i][j] == 1)
                num++;
    printf("%d\n",num);
    return;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&mm,&t);
        int numa = 0;
        for(int i = 1; i<=n; i++)
            for(int j = 1; j<=n; j++)
            {
                scanf("%d",&a[i][j]);
                a[i][j]%=2;
                if(a[i][j] == 1)
                    numa++;
            }
        int numb = 0;
        for(int i = 1; i<=mm; i++)
            for(int j = 1; j<=mm; j++)
            {
                scanf("%d",&b[i][j]);
                b[i][j]%=2;
                if(b[i][j] == 1)
                    numb++;
            }
        m = mm/2;
        solve();
    }
    return 0;
}
