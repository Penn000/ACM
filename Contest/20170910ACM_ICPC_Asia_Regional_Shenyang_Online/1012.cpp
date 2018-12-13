//2017-09-10
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1100000;
int A[N], B[N], n;

int main()
{
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; i++)
		  	scanf("%d", &A[i]);
		for(int i = 0; i < n; i++)
		  	scanf("%d", &B[i]);
		int ans = 0, sum1 = 0, sum2 = 0, ptr1, ptr2;
		for(ptr1 = 0; ptr1 < n; ptr1++){
			sum1 += A[ptr1]-B[ptr1];
			if(sum1 < 0)break;
		}
		for(ptr2 = n-1; ptr2 >= ptr1; ptr2--){
			sum2 += A[ptr2]-B[ptr2];
			if(sum2 >= 0){
				ans = ptr2;
				sum2 = 0;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
