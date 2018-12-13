//2017-03-14
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6;
int arr[N];

int main()
{
	int n;
	while(scanf("%d", &n)!=EOF)
	{
		for(int i = 0; i < n; i++)
		  	scanf("%d", &arr[i]);
		sort(arr, arr+n);
		printf("%d\n", arr[n/2]);
	}

    return 0;
}
