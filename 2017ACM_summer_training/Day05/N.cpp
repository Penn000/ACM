//2017-08-05
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long 

using namespace std;

const int N = 22;
ll factorial[N], stir1[N][N];//factorial[n]存n的阶乘，stir1为第一类斯特林数

int main()
{
    int T, n, k;
	cin >> T;
	factorial[1] = 1;
	for(int i = 2; i < N; i++)
	  	factorial[i] = factorial[i-1]*i;
	memset(stir1, 0, sizeof(stir1));
	stir1[1][1] = 1;
	stir1[0][0] = 0;
	for(int i = 2; i < N; i++){
	  	for(int j = 1; j <= i; j++)
		  	stir1[i][j] = stir1[i-1][j-1] + (i-1)*stir1[i-1][j];
	}
	while(T--){
		cin>>n>>k;
		ll tmp = 0;
		for(int i = 1; i <= k; i++)
		  	tmp += stir1[n][i] - stir1[n-1][i-1];
		printf("%.4lf\n", (double)tmp*1.0/factorial[n]);
	}

	return 0;
}
