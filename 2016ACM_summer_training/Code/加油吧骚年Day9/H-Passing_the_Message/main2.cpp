#include<iostream>
#include<cstdio>
#include<deque>

using namespace std;
const int N = 50005;
int l[N], r[N], a[N];

int main()
{
    int T, n, kase = 0;
    cin>>T;
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        deque<int> q;
        for(int i = 1; i <= n; i++)
        {
            int fr = 1, ba = 0;
            while(!q.empty()&&a[q.back()]<a[i])
            {
                fr = 0;
                ba = q.back();
                q.pop_back();
            }
            if(fr) l[i] = 0;
            else l[i] = ba;
            q.push_back(i);
        }
        for(int i = n; i >= 1; i--)
        {
            int fr = 1, ba = 0;
            while(!q.empty()&&a[q.back()]<a[i])
            {
                fr = 0;
                ba = q.back();
                q.pop_back();
            }
            if(fr) r[i] = 0;
            else r[i] = ba;
            q.push_back(i);
        }
        printf("Case %d:\n", ++kase);
        for(int i = 1; i <= n; i++)
            printf("%d %d\n", l[i], r[i]);
    }
    return 0;
}
