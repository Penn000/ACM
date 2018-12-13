#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1500000;

int arr[N], book[N], dp[N];
int fg[N];

int main()
{
	freopen("input1007.txt", "r", stdin);
    int n;
	while(scanf("%d", &n) != EOF){
		memset(book, 0, sizeof(book));
		memset(dp, 0, sizeof(dp));
		memset(fg, 0, sizeof(fg));
		int ans = 0;
		for(int i = 0; i < n; i++){
		  	scanf("%d", &arr[i]);
			book[arr[i]]++;
		}
		for(int i = 1; i <= n; i++){
			int tmp = book[i]/2;
			ans += tmp;
			book[i] -= 2*tmp;
			fg[i] = tmp;
		}
		printf("%d\n", ans);
	}

	return 0;
}
