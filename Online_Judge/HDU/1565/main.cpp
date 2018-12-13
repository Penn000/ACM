//2016.9.8
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int arr[22][22];
int dp[22][20000], sum[22][20000];//dp[i][j]表示第i行使用第j种方法所能得到的最大值，sum[i][j]表示第i行使用第j种方法所得的和
int state[20000];//表示可行的状态，即可行的取数方法
int len, n;

bool ok(int sta)//可行状态，即1的位置两两不相邻
{
	return (sta&(sta<<1))==0?true:false;
}

int get_sum(int pos, int x)//求第pos行，使用x方法能取得的和
{
	int sum = 0, cnt = 1;
	while(x)
	{
		sum += (x%2)*arr[pos][n-cnt];
		x >>= 1;
		cnt++;
	}
	return sum;
}

void init(int m)//初始化
{
	len = 0;
	for(int i = 0; i < (1<<m); i++)
	  	if(ok(i))state[len++] = i;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < len; j++)
			sum[i][j] = get_sum(i, state[j]);
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < len; i++)
	  	dp[0][i] = sum[0][i];
}

int main()
{
	while(cin>>n)
	{
		for(int i = 0; i < n; i++)
		 	for(int j = 0; j < n; j++)
				scanf("%d", &arr[i][j]);
		init(n);
		for(int i = 1; i < n; i++)//处理第i行
			for(int j = 0; j < len; j++)//采取第j种方法
				for(int k = 0; k < len; k++)//枚举上一行所采取的方法k
					if((state[j]&state[k])==0)//方法j、k可行。ps：要加括号，&的优先级比==还低，debug了半天一脸懵逼，真是醉了
						dp[i][j] = max(dp[i][j], dp[i-1][k]+sum[i][j]);//状态转移方程

		int ans = 0;
		for(int i = 0; i < len; i++)//找出最大值
			if(dp[n-1][i]>ans)
			  	ans = dp[n-1][i];

		cout<<ans<<endl;
	}
	return 0; 
}
