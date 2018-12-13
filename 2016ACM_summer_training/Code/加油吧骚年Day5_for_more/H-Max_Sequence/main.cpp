//2016.8.21
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N = 100005;
const int inf = 0x3f3f3f3f;
int a[N], dpl[N], dpr[N];//dpl[i]表示从左往右到第i位的最大子段和,dpr[i]表示从右往左到第i位的最大子段和

int main()
{
    int  n;
    while(scanf("%d", &n)!=EOF&&n)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        memset(dpl, 0, sizeof(dpl));
        memset(dpr, 0, sizeof(dpr));
//从左往右扫
//*************************************************
        dpl[0] = a[0];
        for(int i = 1; i < n; i++)
            if(dpl[i-1]>0) dpl[i] = dpl[i-1]+a[i];
            else dpl[i] = a[i];
        for(int i = 1; i < n; i++)
            if(dpl[i]<dpl[i-1])
                dpl[i] = dpl[i-1];
//从右往左扫
//*************************************************
        dpr[n-1] = a[n-1];
        for(int i = n-2; i>=0; i--)
            if(dpr[i+1]>0) dpr[i] = dpr[i+1]+a[i];
            else dpr[i] = a[i];
        for(int i = n-2; i>=0; i--)
            if(dpr[i]<dpr[i+1])
                dpr[i] = dpr[i+1];
//*************************************************
        int ans = -inf;
        for(int i = 0; i < n-1; i++)
        {
            ans = max(ans, dpl[i]+dpr[i+1]);
        }
        cout<<ans<<endl;
    }

    return 0;
}
