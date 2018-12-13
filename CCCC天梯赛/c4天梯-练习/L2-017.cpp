//2018-03-14
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100005;
int arr[N];

int main()
{
	int n;
	while(~scanf("%d", &n)){
		for(int i = 0; i < n; i++)
		  	scanf("%d", &arr[i]);
		sort(arr, arr+n);
		int in = n/2;
		int sumIn = 0, sumOut = 0;
		for(int i= 0; i < n; i++){
			if(i < in) sumIn += arr[i];
			else sumOut += arr[i];
		}
		printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d\n", n-in, in, sumOut-sumIn);
	}

	return 0;
}
