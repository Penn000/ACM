#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110000;

int arr[N], n;

int main()
{
	scanf("%d", &n);
	int cnt_nag = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		if(arr[i] < 0)cnt_nag++;
	}
	long long ans = 0;
	sort(arr, arr+n, [](int a, int b){return a > b;});
	int t;
	for(int i = 0; i < n; i++){
		t = 0;

	}

	return 0;
}
