#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000005;
int a, book[N], day[N];

int main()
{
	int n;
	while(scanf("%d", &n)!=EOF)
	{
		int len = 0;
		memset(book, 0, sizeof(book));
		memset(day, 0, sizeof(day));
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &a);
			if(a <= n)
			  book[a]++;
			if(a < n && a > len)len = a;
		}
		int ans = 1;
		for(int i = 1; i <= len; i++)
		{
			while(book[i]){
				bool fg = false;
				for(int j = 1; j <= ans; j++){
					if(day[j] < i){
						book[i]--;
						day[j]++;
						fg = true;
						break;
					}
				}
				if(!fg){
					ans++;
					day[ans]++;
					book[i]--;
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
