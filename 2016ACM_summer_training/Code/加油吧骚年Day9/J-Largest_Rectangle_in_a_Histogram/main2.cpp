#include<iostream>
#include<cstdio>
#define ll long long

using namespace std;

const int N = 100005;
ll hi[N];

int main()
{
	int n;
	while(scanf("%d", &n)!=EOF && n)
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &hi[i]);
		}
	}
	return 0;
}
