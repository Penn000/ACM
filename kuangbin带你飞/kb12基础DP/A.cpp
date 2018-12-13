#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6+10;
int S[N], dp[N], sm[N];

int main()
{
	int n, m;
	while(scanf("%d%d", &m, &n)!=EOF)
	{
		int len = 1, a, cntpos = 0;
		memset(S, 0, sizeof(S));
		scanf("%d", &S[0]);
		if(a >= 0)cntpos++;
		for(int i = 1; i < n; i++)
		{
			scanf("%d", &a);
			if(a >= 0){
				cntpos++;
				if(S[len-1] < 0)S[len++] = a;
				else S[len-1]+=a;
			}else S[len++] = a;
		}
		int cnt = 0;
		for(int i = 0; i < len; i++)
		  	if(S[i] > 0)cnt++;
		int ans = 0;
		if(m >= cnt)
		{
			sort(S, S+len);
			if(m > len)m = len;
			if(m <= cntpos)m = cnt;
			else m -= (cntpos-cnt);
			for(int i = len-1; i > len-m-1; i--)
			  	ans += S[i];
		}else{
			dp[0] = S[0];
			for(int i = 1; i < len; i++)
			  	if(dp[i-1] > 0)dp[i] = dp[i-1]+S[i];
				else dp[i] = S[i];

			for(int i = len-1; i >= 0; i--)
			{

			}
		}
		printf("%d\n", ans);
	}

    return 0;
}
