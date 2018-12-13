#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int min(int a, int b)
{
		return a > b ? b : a;
}

int main()
{
		int w, l, dp[305], len[605];
		char a[305], dict[605][30];
		while(cin>>w>>l)
		{
			scanf("%s", a);
			for(int i = 0; i < w; i++)
			{
				scanf("%s", dict[i]);
				len[i] = strlen(dict[i]);
			}
			memset(dp, 0, sizeof(dp));
		//	dp[l] = 0;
			for(int i = l-1; i >= 0; i--)
			{
				dp[i] = dp[i+1] + 1;
				for(int j = 0; j < w; j++)
				{
					if(dict[j][0] == a[i] && len[j] <= l-i)
					{
				    int t = 1; int k = 1;
					while(i+t < l && k < len[j])
					{
						if(dict[j][k] == a[i+t])k++;	
						t++;
					}
					if(k >= len[j])
					  dp[i] = min(dp[i], dp[i+t]-len[j]+t);
				}	
			}}
			  cout<<dp[0]<<endl;
		     // for(int i = 0; i < l; i++)
			//	cout<<dp[i]<<" ";
		}
		return 0;
}

