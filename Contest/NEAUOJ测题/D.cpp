#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;
const int N = 1100;
long long mat[N][N];

int main()
{
	int n, m, q;
	while(scanf("%d%d%d", &n, &m, &q) != EOF){
		for(int i = 1; i <= n; i++)
		  for(int j = 1; j <= m; j++)
			mat[i][j] = 1;
		int x, y, k;
		while(q--){
			scanf("%d%d%d", &x, &y, &k);
			mat[x][y] = (mat[x][y]*k)%MOD;
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++)
			  if(j != m)printf("%lld ", mat[i][j]);
			  else printf("%lld\n", mat[i][j]);
		}
	}

	return 0;
}
