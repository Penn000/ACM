//2017-03-14
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 35;
int n, dp[N*6];//DAG模型，dp[i]表示从第i个箱子出发能够走的最大值
struct node
{
	int x, y, z;
	void setNode(int a, int b, int c){
		this->x = a;
		this->y = b;
		this->z = c;
	}
}box[N*6];

int dfs(int i)
{
	int& ans = dp[i];
	if(ans)return ans;//记忆化搜索
	ans = 0;
	for(int j = 0; j < n*6; j++)
	{
		if(box[i].x > box[j].x && box[i].y > box[j].y)
		{
			ans = max(ans, dfs(j));
		}
	}
	ans += box[i].z;
	return ans;
}

int main()
{
	int a, b, c, kase = 0;
	while(cin>>n && n)
	{
		int cnt = 0;
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; i++)
		{
			cin>>a>>b>>c;
			box[cnt++].setNode(a, b, c);
			box[cnt++].setNode(a, c, b);
			box[cnt++].setNode(b, a, c);
			box[cnt++].setNode(b, c, a);
			box[cnt++].setNode(c, a, b);
			box[cnt++].setNode(c, b, a);
		}
		for(int i = 0; i < n*6; i++)
		  	dfs(i);
		int ans = 0;
		for(int i = 0; i < n*6; i++)
		  	if(dp[i] > ans)ans = dp[i];
		cout<<"Case "<<++kase<<": maximum height = "<<ans<<endl;
	}

    return 0;
}
