//2016.8.7
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

int dp[12][13][2][3];
//dp[i][j][k][p]表示方法数,i表示已处理的长度，j表示mod13的余数，k表示前缀是否相同(0为相同，1为不同),p为1表示前一个数为1,为2表示已出现13，否则为0
int mi[12];

int cal(int x, int n, int p)
{
	return x*mi[n]%p;
}

int judge(int x)//三态函数
{
	if(x==1)return 1;
	else if(x==3)return 2;
	else return 0;
}

int solve(string s)
{
	memset(dp, 0, sizeof(dp));
	dp[0][0][1][0] = 1;
	int len = s.size();
	for(int i = 0; i < len; i++)
	  for(int j = 0; j < 13; j++)
		for(int k = 0; k < 2; k++)
		  for(int p = 0; p < 3; p++)
		  {
			  if(dp[i][j][k][p]!=0)
			  {
				  int l, r;
				  l = 0; r = (k==1?s[i]-'0':9);
				  for(int x = l; x <= r; x++)
				  {
					  if(p==0)
					  dp[i+1][(j+cal(x, len-i-1, 13))%13][(k==1&&x==r)?1:0][x==1?1:0]+=dp[i][j][k][p];
					  else if(p==1)
					  dp[i+1][(j+cal(x, len-i-1, 13))%13][(k==1&&x==r)?1:0][judge(x)]+=dp[i][j][k][p];
					  else if(p==2)
					  dp[i+1][(j+cal(x, len-i-1, 13))%13][(k==1&&x==r)?1:0][2]+=dp[i][j][k][p];
				  }
			  }
		  }
	return dp[len][0][0][2] + dp[len][0][1][2];
}

int main()
{
	string n; 
	while(cin>>n)
	{
		mi[0] = 1;
		for(int i = 1; i < 12; i++)
		  mi[i] = mi[i-1]*10%13;
		int ans;
		ans = solve(n);
		cout<<ans<<endl;
	}

	return 0;
}
