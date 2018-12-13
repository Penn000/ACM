#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int inf = 2147483647;

int main()
{
	long long n, arr_src[100005], arr_dest[100005];
	while(cin >> n)
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &arr_src[i]);
			arr_dest[i] = arr_src[i];
		}
		sort(arr_dest+1, arr_dest+1+n);
		int r, l;
		bool fg = false;
		for(int i = 1; i <= n; i++)
		{
			if(arr_src[i] != arr_dest[i])
			{
				l = i;
				while(arr_src[i]!=arr_dest[i])
				{
					i++;
				}
				r = i-1;
				fg = true;
			}
			if(fg && arr_src[i]!=arr_dest[i])
			{
				fg = false;
				break;
			}
		}
		arr_src[0] = arr_dest[0] = inf;
		bool f = true, g = true;
		for(int i = 1; i <= n; i++)
		{
			if(arr_src[i] > arr_src[i-1])f = false;
			if(arr_src[i] != arr_dest[i])g = false;
			if(!f&&!g)break;
		}
		if(f)
		{
			fg = true; l = 1; r = n;
		}
		else if(g)
		{
			fg = true; l = r =1;
		}
		else 
		{
			for(int i = l+1; i <= r; i++)
			  if(arr_src[i] > arr_src[i-1])
			  {fg = false;break;}
		}
		if(fg)printf("yes\n%d %d\n", l, r);
		else printf("no\n");
	}

	return 0;
}
