//2016.10.08
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N = 1000005;
const int inf = 0x3f3f3f3f;
int a[N], b[N], nex[N],n, m, p;

void pre_kmp(int b[], int m)//得到next数组
{
	int i, j;
	j = nex[0] = -1;
	i = 0;
	while(i < m)
	{
		while(j != -1 && b[i]!= b[j])j = nex[j];
		nex[++i] = ++j;
	}
}

int kmp(int a[], int n, int b[], int m)
{
	int ans = 0;
	pre_kmp(b, m);
	for(int pos = 0; pos < p; pos++)
	{
		int i = pos, j = 0;
		while(i < n)
		{
			while(j != -1 && a[i] != b[j])j = nex[j];
			i += p; j++;
			if(j >= m){ans++; j = nex[j];}
		}
	}
	return ans;
}

int main()
{
	int T, kase = 0;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &n, &m, &p);
		for(int i = 0; i < n; i++)scanf("%d", &a[i]);
		for(int i = 0; i < m; i++)scanf("%d", &b[i]);
		printf("Case #%d: %d\n", ++kase, kmp(a,n,b,m));
	}

    return 0;
}
