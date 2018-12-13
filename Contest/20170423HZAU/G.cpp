#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 50005;
int A[N], dp[N];

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &A[i]);
		}
		int len = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = n-1; j > i; j--){
				if(j-i < len)break;
				if(A[i] <= A[j]){
					if(j-i > len)len = j-i;
				}
			}
			if(n-1-i < len)break;
		}
		printf("%d\n", len);
	}
	return 0;
}
