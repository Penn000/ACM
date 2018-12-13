//2016.8.12
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

const int N = 200005;
int k[N], step[N], nex[N];//step[i]记录i点走出块的步数，nex[i]记录i走出块到达的点

int main()
{
	int n, m, a, b, c, cnt, ans;
	scanf("%d", &n);
	{
		int len = (int)sqrt(n);
		for(int i = 0; i < n; i++)
		  scanf("%d", &k[i]);
		for(int i = n-1; i>0; i--)
		{
			int tmp = i+k[i];
			if(tmp>=n)
			{
				step[i] = 1;
				nex[i] = -1;//用-1表示走出整个区间
			}else if(tmp>=(i/len+1)*len)
			  	step[i] = 1, nex[i]  = tmp;
			else
			  nex[i] = nex[tmp] , step[i] = step[tmp]+1;
		}
		scanf("%d", &m);
		while(m--)
		{
			scanf("%d%d", &a, &b);
			if(a==1)
			{
				ans = 0;
				for(int i = b; ~i;i = nex[i])//当i==-1时，~i==0，为假退出
				{
					ans+=step[i];
				}
				printf("%d\n", ans);
			}else
			{
				scanf("%d", &c);
				k[b] = c;
				for(int i = b; i >= b/len*len; i--)
				{
					int tmp = i+k[i];
					if(tmp>=n)
					  step[i] = 1, nex[i] = -1;
					else if(tmp>=(i/len+1)*len)
					  step[i] = 1, nex[i] = tmp;
					else
						step[i] = step[tmp]+1, nex[i] = nex[tmp];
				}
			}
		}
	}

	return 0;
}
