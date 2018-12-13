#include<iostream>
#include<cstdio>
#include<cstring>
#define ll int

using namespace std;

const int N = 50005;
ll h[N];
int l[N], r[N];

int main()
{
    int n, T, kase = 0;
	cin>>T;
    while(T--)
    {
		scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &h[i]);
        l[1] = 0, r[n] = 0;
        for(int i = 2; i <= n; i++)
        {
            int tmp = i;
            while(tmp>1 && h[tmp-1] < h[i])tmp = l[tmp-1];
			if(h[tmp]>h[l[i]])
	            l[i] = tmp;
        }
        for(int i = n-1; i >= 1; i--)
        {
            int tmp = i;
            while(tmp<n && h[tmp+1] < h[i])tmp = r[tmp+1];
			if(h[tmp]>h[r[i]])
	            r[i] = tmp;
        }
      
		printf("Case %d:\n", ++kase);
        for(int i = 1; i <= n; i++)
        	printf("%d %d\n", l[i], r[i]);
    }

    return 0;

}
