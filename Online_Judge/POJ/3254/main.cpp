//2016.8.8
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int mod = 1000000000;
int arr[13][13];
int dp[13][1<<13];//dp[i][j]表示第ｉ行第ｊ种状态时的方法数。
int state[1<<13];//记录可行的状态，即两两不相邻，以减少枚举次数。
int cur[13];//根据输入记录该行的状态。
int len;//可行状态总数

bool ok(int sta)//判断状态两两不相邻
{
	return (sta&(sta<<1))==0?true:false;
}

void init(int m)//初始化可行状态
{
	len = 0;
	for(int i = 0; i < (1<<m); i++)
	  if(ok(i))state[len++] = i;
}

bool fit(int sta, int k)//判断状态sta是否满足第k行的状态要求
{
	return (sta&cur[k])==0?true:false;
}

int main()
{
	int n, m;
	while(cin>>n>>m)
	{
		init(m);
		for(int i = 0; i < n; i++)
		{
		  int feifa = 0;
		  for(int j = 0; j < m; j++)
		  {
			scanf("%d", &arr[i][j]);
			if(arr[i][j]==0)feifa += (1<<(m-j-1));//0为不可以放牛，反向存为１
		  }
		  cur[i] = feifa;
		}
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < len; i++)//初始化第一行dp值
		  if(fit(state[i], 0))
			dp[0][i] = 1;
		for(int i = 1; i < n; i++)
		{
			for(int j = 0; j < len; j++)
			{
				if(fit(state[j], i))//如果状态state[j]满足该行i的要求，把上一行可行状态的方法数加起来
				{
					for(int k = 0; k < len; k++)//枚举上一行(第i-1行)的状态
					{
						if(!fit(state[k], i-1))continue;//排除不满足i-1行要求的状态
						if(state[k]&state[j])continue;//排除不满足状态state[j]的状态
						dp[i][j] = (dp[i][j]+dp[i-1][k])%mod;
					}
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < len; i++)//答案是最后一行填各个状态的方法数之和
		  ans = (ans+dp[n-1][i])%mod;
		cout<<ans<<endl;
	}

	return 0; 
}
