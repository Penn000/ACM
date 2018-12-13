//2016.8.19
#include <iostream>

using namespace std;

int line[15], ans[15], n, cnt;

void dfs(int row)
{
	if(row == n)cnt++;
	else
	{
		for(int i = 0; i < n; i++)
		{
			bool fg = true;
			line[row] = i;
			for(int j = 0; j < row; j++)
			{
				if(line[row]==line[j] || line[row]-line[j]==row-j || line[row]-line[j]==j-row)
				{
					fg = false;
					break;
				}
			}
			if(fg)dfs(row+1);
		}
	}
}

int main()
{
	for(n = 1; n <= 10; n++)
	{
		cnt = 0;
		dfs(0);
		ans[n] = cnt;
	}
	while(cin>>n&&n)
	{
		cout<<ans[n]<<endl;
	}

    return 0;
}
