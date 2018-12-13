#include<iostream>
#include<cstdio>
#include<deque>

using namespace std;

const int N = 50005;
int hi[N], l[N], r[N];

int main()
{
	int T, n, kase = 0;
	cin>>T;
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &hi[i]);
		}
		deque<int> dq;
		l[1] = r[n] = 0;
		for(int i = 1; i <= n; i++)
		{
			if(dq.empty()||hi[dq.back()]>hi[i])
			{
				dq.push_back(i);
				l[i] = 0;
			}else
			{
				int tmp = dq.back(), tt;
				r[tmp] = 0;
				dq.pop_back();
				tt = tmp;
				while(!dq.empty()&&hi[dq.back()]<hi[i])
				{
					tt = dq.back();
					r[tt] = tmp;
					dq.pop_back();
				}
					l[i] = tt;
				dq.push_back(i);
			}
		}
		while(!dq.empty())
		{
			int tmp = dq.back();
			dq.pop_back();
			if(!dq.empty())
				r[dq.back()] = tmp;
		}
		printf("Case %d:\n", ++kase);
		for(int i = 1; i <= n; i++)
		  	printf("%d %d\n", l[i], r[i]);
	}

	return 0;
}
