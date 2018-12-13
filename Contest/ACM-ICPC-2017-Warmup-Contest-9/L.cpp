//2017-10-24
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const int N = 21000;
ll arr[N];
int n;

int main()
{
	while(~scanf("%d", &n)){
		for(int i = 0; i < n; i++)
			scanf("%lld", &arr[i]);
		sort(arr, arr+n);
		bool ok = false;
		for(int i = 0; i < n-2; i++)
		  if(arr[i] + arr[i+1] > arr[i+2]){
			  ok = true;
			  break;
		  }
		if(ok)printf("possible\n");
		else printf("impossible\n");
	}

	return 0;
}
