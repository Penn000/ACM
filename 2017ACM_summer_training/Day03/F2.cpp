#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
 
const int INF = 0x3f3f3f3f;
const int N = 5005;
 
typedef long long ll;
 
int n, a[N], dp[N][N];
ll v[N], pre[N];
 
void init() {
    for (int i = 1; i <= n; i++) {
    scanf("%lld", &v[i]);
    pre[i] = pre[i - 1] + v[i];
    }
    for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);
    memset(dp, -1, sizeof(dp));
}
 
int solve(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    dp[l][r] = a[r - l + 1];
    if (l >= r) return dp[l][r] = 0;
    int now = l;
    for (int i = r; i >= l; i--) {
    while (pre[now] - pre[l - 1] < pre[r] - pre[i - 1] && now < i)
        now++;
    if (now == i) break;
    if (pre[now] - pre[l - 1] == pre[r] - pre[i - 1])
        dp[l][r] = min(dp[l][r], a[now - l + 1] + a[r - i + 1] + solve(now + 1, i - 1));
    }
    return dp[l][r];
}
 
int main() {
    while (~scanf("%d", &n) && n) {
    init();
    printf("%d\n", solve(1, n));
    }
    return 0;
}