//2016.8.2
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	long long arr_src[100005], arr_dest[100005];
	int l, r, n;
	while(cin >> n)
	{
		r = l = 1;
		for(int i = 1; i <= n; i++)
		{
			scanf("%lld", &arr_src[i]);
			arr_dest[i] = arr_src[i];
		}
		sort(arr_dest+1, arr_dest+1+n);
		for(int i = 1; i <= n; i++)
		  if(arr_src[i] != arr_dest[i])
		  {
			  l = i;
			  break;
		  }
		for(int i = n; i >= 1; i--)
			if(arr_src[i]!=arr_dest[i])
			{
				r = i;
				break;
			}
		bool fg = true;
		reverse(arr_dest+l, arr_dest+1+r);
		for(int i = 1; i <= n; i++)
		{
			if(arr_src[i] != arr_dest[i])
			{
				fg = false;
				break;
			}
		}
		if(fg)printf("yes\n%d %d\n", l, r);
		else printf("no\n");
	}
	return 0;
}
