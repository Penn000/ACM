#include <iostream>
#include <cstdio>

using namespace std;

int b[15], like[15][15];

int main()
{
	int T, n, m, k, kase = 0;
	cin>>T;
	while(T--)
	{
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 0; i < m; i++)
		  	scanf("%d", &b[i]);
		for(int i = 0; i < n; i++)
		  	for(int j = 0; j < m; j++)
			  	scanf("%d", &like[i][j]);
		printf("Case #%d: ", ++kase);
	}

    return 0;
}
