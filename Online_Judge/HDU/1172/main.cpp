//2016.9.1
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, a[105], b[105], c[105], book[105][12], dit[105][5], vis[12], dit2[5], ans;
//book[i]记录a[i]出现了哪些数字,dit[i]记录a[i]不同位上的数字,vis记录x出现了哪些数字,dit2记录x不同位上的数字

bool judge(int x)
{
	int cntb, cntc, pos = 0;
	memset(vis, 0, sizeof(vis));
	memset(dit2, 0, sizeof(dit2));
	while(x)
	{
		dit2[pos] = x%10;
		vis[x%10]++;
		x /= 10;
		pos++;															
	}
	for(int i = 0; i < n; i++)
	{
		cntb = cntc = 0;
		for(int j = 0; j < 4; j++)
		  	if(dit2[j] == dit[i][j])cntc++;
		if(cntc != c[i])return false;
		for(int j = 0; j < 10; j++)
	  	  	if(vis[j] && book[i][j])
				cntb += min(vis[j], book[i][j]);
		if(cntb != b[i])return false;
	}
	return true;
}

int main()
{
	int cnt;
	while(scanf("%d", &n)!=EOF && n)
	{
		cnt = 0;
		memset(book, 0, sizeof(book));
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
			int tmp = a[i], count = 0;
			while(tmp)
			{
				book[i][tmp%10]++;
				dit[i][count++] = tmp%10;
				tmp /= 10;
			}
		}
		for(int i = 1000; i < 10000; i++)//暴力枚举所有四位数
		  	if(judge(i))
			{
				ans = i;
				cnt++;
			}
		if(cnt==1)printf("%d\n", ans);
		else printf("Not sure\n");//如果答案不唯一，则不确定
	}
    return 0;
}
