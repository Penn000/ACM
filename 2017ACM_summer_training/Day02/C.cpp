#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 20;
const int P = 12;
const int inf = 0x3f3f3f3f;
int dp[N][N][1 << P], n, m, p, k, s, edge[2050][2050], grid[N][N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int min(int a, int b)
{
    return a > b ? b : a;
}

int dfs(int x, int y, int state)
{
//    if (dp[x][y][state] != inf)return dp[x][y][state];
//	else{
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 && nx > n && ny < 1 && ny > m)
                continue;
            if (edge[nx * 100 + ny][x * 100 + y] == -1)
                continue;
            if (edge[nx * 100 + ny][x * 100 + y] == 0 || ((1 << (edge[nx * 100 + ny][x * 100 + y] - 1)) & state) > 0)
            {
                if (grid[nx][ny])
                {
                    dp[nx][ny][state | (1 << grid[nx][ny])] = min(dfs(nx, ny, state | (1 << grid[nx][ny])), dp[x][y][state] + 1);
                }
                else
                {
                    dp[nx][ny][state] = min(dfs(nx, ny, state), dp[x][y][state] + 1);
                }
            }
        }
//    }
    return dp[x][y][state];
}
    int main()
    {
        while (scanf("%d%d%d%d", &n, &m, &p, &k) != EOF)
        {
            memset(grid, 0, sizeof(grid));
            memset(edge, 0, sizeof(edge));
            memset(dp, inf, sizeof(dp));
            int x1, x2, y1, y2, g;
            for (int i = 0; i < k; i++)
            {
                scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &g);
                if (g == 0)
                    g = -1;
                edge[x1 * 100 + y1][x2 * 100 + y2] = edge[x2 * 100 + y2][x1 * 100 + y1] = g;
            }
            scanf("%d", &s);
            for (int i = 0; i < s; i++)
            {
                scanf("%d%d%d", &x1, &y1, &g);
                grid[x1][y1] = g;
            }
            dp[1][1][0] = 0;
            dfs(1, 1, 0);
            int ans = inf;
            for (int state = 0; state < (1 << p); state++)
            {
                ans = min(ans, dp[n][m][state]);
            }
            printf("%d\n", ans);
        }
        return 0;
    }
