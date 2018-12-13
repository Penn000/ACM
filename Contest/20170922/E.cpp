//2017-09-22
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110000;

int n, arr[N], k;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &k);
		for(int i = 0; i < n; i++){
			scanf("%d", &arr[i]);
		}
		sort(arr, arr+n);
		int ptr = n-1, ans = 0;
		while(ptr >= 1 && arr[ptr]-arr[ptr-1] <= k){
			ptr--;
			ans++;
		}
		printf("%d\n", ans+1);
	}

	return 0;
}
