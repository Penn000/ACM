//2017-02-19
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, k, cnt;
char M[10][10];
bool col[10];

void dfs(int row, int step) //row表示当前行数，step表示已经放的棋子数
{
	if (step == k)
	{
		cnt++;
		return;
	}
	if (row >= n)
		return;
	dfs(row + 1, step); //该行不放棋子
	for (int j = 0; j < n; j++)
		if (col[j] == false && M[row][j] == '#')
		{
			col[j] = true;
			dfs(row + 1, step + 1); //该行放棋子
			col[j] = false;
		}
}

int main()
{
	while (cin >> n >> k)
	{
		if (n == -1 && k == -1)
			break;
		cnt = 0;
		memset(col, 0, sizeof(col));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> M[i][j];

		dfs(0, 0);
		cout << cnt << endl;
	}

	return 0;
}
