//2017-05-24
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10010;
double dp[N];

int main()
{
    int n, m, C;
	double W;
	while(cin>>m>>n){
		if(!n && !m)break;
		for(int i = 0; i <= m; i++)dp[i] = 1.0;
		for(int i = 1; i <= n; i++){
			cin>>C>>W;
			for(int j = m; j >= C; j--){
				dp[j] = min(dp[j], dp[j-C]*(1-W));
			}
		}
		printf("%.1lf%%\n", (1-dp[m])*100);
	}

	return 0;
}
