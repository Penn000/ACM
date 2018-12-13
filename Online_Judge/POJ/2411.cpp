//2017-08-02
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 15;
int n, m;
long long dp[N][1<<N];//dp[col][state]表示第col列，在state状态下（即前一列对该列的影响）的方法数。

//dfs表示当前处理到col列的第i个格子，state状态下，对下一列的影响nex
void dfs(int col, int i, int state, int nex){
    if(i == n){
        dp[col+1][nex] += dp[col][state];
        return;
    }
    if((state&(1<<i)) > 0)//这个格子已经被上一列填过
        dfs(col, i+1, state, nex);
    if((state&(1<<i)) == 0)//格子没有被填充，尝试横着放一块砖
        dfs(col, i+1, state, nex|(1<<i));
    if(i+1<n && (state&(1<<i))==0 && (state&(1<<(i+1)))==0)//尝试竖着放一块砖
        dfs(col, i+2, state, nex);
}

int main(){
    while(cin>>n>>m){
        if(!n && !m)break;
        memset(dp, 0, sizeof(dp));
        dp[1][0] = 1;
        for(int col = 1; col <= m; col++){
            for(int state = 0; state < (1<<n); state++){
                if(dp[col][state])
                    dfs(col, 0, state, 0);
            }
        }
        cout<<dp[m+1][0]<<endl;//答案为第m+1列，前一列对其影响为0的方法数。
    }

    return 0;
}