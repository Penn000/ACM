//2016.10.7
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int inf = 0x3f3f3f3f;
int a[1000005], b[10005], nex[10005];

int kmp(int a[], int b[])
{
	int ans = 0;
	nex[0] = -1;
	for(int i = 0, fail = -1; b[i] != inf;)//求nex数组， fail为失配指针
	{
		if(fail==-1 || b[i] == b[fail])
		{
			i++, fail++;
			nex[i] = fail;
		}else fail = nex[fail];
	}
	int i = 0, j = 0;
	for(; a[i] != inf; i++, j++)
	{
		if(j != -1 && b[j] == inf)return i-j+1;
		while(j != -1 && a[i] != b[j])j = nex[j];
	}
	if(b[j] == inf)return i-j+1;
	return -1;
}

int main()
{
	int T, n, m;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++)scanf("%d", &a[i]);
		for(int i = 0; i < m; i++)scanf("%d", &b[i]);
		a[n] = b[m] = inf;//设置截止符号
		printf("%d\n", kmp(a, b));
	}

    return 0;
}
