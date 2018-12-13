#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int mapp[18][18];
int dp[18][1<<18];

int main()
{
	string s;
	while(getline(cin, s))
	{
		memset(mapp, 0, sizeof(mapp));
		int n = 0;
		for(int i = 0; i < s.length(); i++)
		{
			if(s[i]==' ')n++;
			else(mapp[0][n] = mapp[0][n]*10+s[i]-'0');
		}
		n++;
		for(int i = 1; i < n; i++)
		  for(int j = 0; j < n; j++)
			scanf("%d", &mapp[i][j]);
		getchar();
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		for(int i = 0; i < n; i++)
		{
			for(int state = 0; state < (1<<n); state++)
			{
				if(dp[i][state]!=-1)
				{

				}
			}
		}
	}

	return 0;
}
