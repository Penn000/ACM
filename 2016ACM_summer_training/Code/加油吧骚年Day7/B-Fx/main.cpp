#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int dp[10][10000][2];
string a;

//int mi[10] = {512, 256, 128, 64, 32, 16, 8, 4, 2, 1};

int F(string a)
{
	int ans = 0;
	int len = a.size();
	for(int i = 0; i < len; i++)
		ans+=(a[i]-'0')*(1<<(len-i-1));
	return ans;
}

int solve(string s)
{
	memset(dp, 0, sizeof(dp));
	dp[0][0][1]= 1;
	int len = s.size(), alen;
	alen = F(a);
	for(int i = 0; i < len; i++)
		for(int j = 0; j <= alen; j++)
		  for(int k = 0; k < 2; k++)
		  {
			  if(dp[i][j][k]!=0)
			  {
				  int r, l;
				  l = 0; r = (k==1?s[i]-'0':9);
				  for(int x = l; x <= r; x++)
				  {
					  if(j+x*(1<<(len-1-i)) <= alen)
					  dp[i+1][j+x*(1<<(len-1-i))][(k==1&&x==r)?1:0]+=dp[i][j][k];
				  }
			  }
		  }
	int sum = 0;
	for(int i = 0; i <= alen; i++)
	  sum+=dp[len][i][1]+dp[len][i][0];
//	return dp[len][a][1]+dp[len][a][0];
	return sum;
}

int main()
{
	int T, kase = 0;
	string b;
	cin>>T;
	while(T--)
	{
		cin>>a>>b;
		int ans = solve(b);
		printf("Case #%d: %d\n", ++kase, ans);
		cout << F(a) << endl;
	}

	return 0;
}
