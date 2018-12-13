#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;
const int MOD = 999983;
long long n, m, dp[N][N][N];

int main(){
    while(cin>>n>>m){
        if(n > m)swap(n, m);
        memset(dp, 0, sizeof(dp));
        dp[1][m][0] = 1;
        dp[1][m-1][1] = m;
        dp[1][m-2][2] = m*(m-1)/2;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= m; k++){
                    if(j+k>m)break;
                    dp[i][j][k] = dp[i-1][j+1][k+1]*(j+1)*(k+1)+dp[i-1][j][k+1]*(k+1)+dp[i-1][j][k+2]*(k+2)*(k+1)/2+dp[i-1][j][k];
                    if(k-1>=0)dp[i][j][k] += dp[i-1][j+1][k-1]*(j+1);
                    if(k-2>=0)dp[i][j][k] += dp[i-1][j+2][k-2]*(j+2)*(j+1)/2;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= m; j++){
                ans += dp[n][i][j];
                ans %= MOD;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
