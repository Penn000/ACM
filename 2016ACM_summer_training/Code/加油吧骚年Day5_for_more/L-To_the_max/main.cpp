//2016.8.21
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N = 105;
const int inf = 0x3f3f3f3f;
int a[N][N];

int main()
{
	int n, tmp;
	while(scanf("%d", &n)!=EOF)
	{
		for(int i = 0; i < n; i++)
		  	for(int j = 0; j < n; j++)
			  	scanf("%d", &a[i][j]);
		
		int ans = -inf;
		for(int i = 0; i < n-1; i++)
		{
//把第j行合并到第i行，求出第i行到第j行的最大子段和**************
			for(int j = i; j < n; j++)
			{
				tmp = 0;
				for(int k = 0; k < n; k++)
				{
					if(j > i) a[i][k]+=a[j][k];//把矩阵合并为一维的数组
					if(tmp > 0) tmp += a[i][k];
					else tmp = a[i][k];
					ans = max(ans, tmp);
				}
			}
//**************************************************************			
		}

		cout<<ans<<endl;
	}

	return 0;
}
