#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110000;

long long arr[N];
int n;

int main()
{
	while(~scanf("%d", &n)){
		long long sum = 0;
		for(int i = 0; i < n; i++){
			scanf("%lld", &arr[i]);
			sum += arr[i];
		}
		sort(arr, arr+n);
		int p, pre = 0;
		for(int i = 0; i < n;){
			p = i;
			while(arr[p] == arr[i] && i < n)i++;
			if(i >= n)break;
			sum -= (n-p)*(arr[p]-pre);
			printf("%lld\n", sum);
			pre = arr[p];
		}
		printf("0\n");
	}
	return 0;
}
