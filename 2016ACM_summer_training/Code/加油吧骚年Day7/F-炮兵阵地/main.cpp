#include<stream>
#include<cstdio>
#include<cstring>

using namespace std;

char mapp[105][12];

int main()
{
	int n, m;
	while(cin>>n>>m)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			  scanf("%c", &mapp[i][j]);
			getchar();
		}
	}

	return 0;
}
