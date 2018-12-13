#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 310;
int n, m, p;
int a[N][N];
int dp[N];

int getMaxArray(int a[], int n) {
	int max = a[0], tmp = 0;
	for (int i = 0; i < n; ++i) {
		if (tmp > 0) {
			tmp += a[i];
		} else {
			tmp = a[i];
		}
		max = max > tmp ? max : tmp;
	}
	return max;
}

int main() {
	//freopen("input.txt", "r", stdin);
	while (scanf("%d%d%d", &n, &m, &p) != EOF) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%d", &a[i][j]);
			}
		}
		int res = a[0][0], tmp;
		for (int i = 0; i < n; ++i) {
			memset(dp, 0, sizeof(dp));
			for (int j = i; j < n; ++j) {
				for (int k = 0; k < m; ++k) {
					dp[k] += a[j][k];
				}
				tmp = getMaxArray(dp, m);
				res = res > tmp ? res : tmp;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
