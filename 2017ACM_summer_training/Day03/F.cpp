//2017-08-03
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5010;
const int inf = 0x3f3f3f3f;
int n, a[N], dp[N][N];//dp[l][r]表示把区间l-r合并为回文的最小代价
long long v[N], sum[N];

int dfs(int l, int r){
    if(l >= r)return dp[l][r] = 0;
    if(dp[l][r] != -1)return dp[l][r];//记忆化搜索
    int i = l;
    dp[l][r] = v[r-l+1];
    for(int j = r; j >= l; j--){
        while((sum[i]-sum[l-1]) < (sum[r]-sum[j-1]) && i < j){
            i++;
        }
        if(j == i)break;
        if((sum[i]-sum[l-1]) == (sum[r]-sum[j-1])){//划分子区间，需保证区间左端所有数之和与区间右端所有数之和相等。
            int tmp = dfs(i+1, j-1)+v[i-l+1]+v[r-j+1];
            dp[l][r] = dp[l][r] < tmp ? dp[l][r] : tmp;
        }
    }
    return dp[l][r];
}

int main(){
    while(scanf("%d", &n)!=EOF && n){
        sum[0] = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            sum[i] = sum[i-1]+a[i];
        }
        for(int i = 1; i <= n; i++)
            scanf("%lld", &v[i]);
        memset(dp, -1, sizeof(dp));
        int ans = dfs(1, n);
        printf("%d\n", ans);
    }

    return 0;
}
