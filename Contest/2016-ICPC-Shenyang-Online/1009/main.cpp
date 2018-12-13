#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 305
#define ll long long

using namespace std;

const int inf = 0x3f3f3f3f;
int key[N], val[N];
int book[N], n;

int func(int l, int r)
{
	int ans;
	for(int i = l; i <= r; i++)
	{
		if((i-l)%2==0)ans = min(ans, val[i]);
		else ans = min(ans, val[i] + func(l, i-1) + func(i+1, r));
	}
	return ans;
}

int main()
{
	int T;
	long long ans;
	scanf("%d", &T);
	while(T--)
	{
		ans = 0;
		memset(book, 0, sizeof(book));
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		  	scanf("%d", &key[i]);
		for(int i = 0; i < n; i++)
		  	scanf("%d", &val[i]);
		for(int i = 1; i < n; i++)
		  	if(__gcd(key[i], key[i-1])!=1)
			{
				book[i] = book[i-1] = 1;				
			}	
		for(int i = 0; i < n; i++)
		{
			if(book[i]==0)continue;
			int ct = 0;
			int l = i, mipos;
			int mini = inf;
			bool fg = false;
			while(book[i]==1)
			{
				ans += val[i];
				if(val[i]<mini)
				{
					mini = val[i];
					mipos = i;
				}
				ct++;
				i++;
			}
			int r = --i;
			if(ct%2==1)
			{
				int sub = func(l, r);
				ans -= sub;
			}
		}
		printf("%lld\n", ans);
	}

    return 0;
}
