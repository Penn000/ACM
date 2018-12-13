//2017-05-16
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int M = 1005;
int dp[M];
struct Milk
{
	int bg, ed, eff;
	bool operator<(Milk x) const{
		return ed < x.ed;
	}
}milk[M];

int main()
{
    int n, m, r;
	while(scanf("%d%d%d", &n, &m, &r)!=EOF)
	{
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < m; i++){
			scanf("%d%d%d", &milk[i].bg, &milk[i].ed, &milk[i].eff);
		}
		sort(milk, milk+m);
		int ans = 0;
		for(int i = 0; i < m; i++){
			if(milk[i].ed > n)break;
			dp[i] = milk[i].eff;
			for(int j = 0; j < i; j++){
				if(milk[i].bg-r >= milk[j].ed){
					dp[i] = max(dp[i], dp[j]+milk[i].eff);//dp[i]表示到第i个区间的最大值
				}else break;
			}
			if(dp[i] > ans)ans = dp[i];
		}
		printf("%d\n", ans);
	}

	return 0;
}
