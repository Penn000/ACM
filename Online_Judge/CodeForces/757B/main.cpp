//2016.01.18
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5+10;
int book[N];

int main()
{
	int n, a;
	while(scanf("%d", &n) != EOF)
	{
		memset(book, 0, sizeof(book));
		for(int i = 0; i < n; i++)
		{
		  	scanf("%d", &a);
			for(int j = 1; j*j <= a; j++)
			{
				if(j*j == a)
				  	book[j]++;
				else if(a%j == 0)
				{
					book[j]++;
					book[a/j]++;
				}
			}
		}
		int ans = 1;
		for(int i = 2; i < N; i++)
		  	if(book[i] > ans)
			  	ans = book[i];
		printf("%d\n", ans);
	}

    return 0;
}
