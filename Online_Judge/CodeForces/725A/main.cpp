//2016.11.01
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 200005;
char arr[N];

int main()
{
	int n, ans;
	while(scanf("%d", &n)!=EOF)
	{
		scanf("%s", arr);
		ans = 0;
		for(int i = 0; i < n; i++)
		{
			if(arr[i] == '>')break;
			ans++;
		}
		for(int i = n-1; i >= 0; i--)
		{
			if(arr[i] == '<')break;
			ans++;
		}
		printf("%d\n", ans);
	}

    return 0;
}
