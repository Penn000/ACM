#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110000;

int arr[N], n;

int main()
{
	while(~scanf("%d", &n)){
		int l = 0, r = n-1, num;
		scanf("%d", &num);
		if(num&1)arr[l++] = num;
		else arr[r--] = num;
		for(int i = 1; i < n; i++){
			scanf(",%d", &num);
			if(num&1)arr[l++] = num;
			else arr[r--] = num;
		}
		for(int i = 0; i < n; i++)
		  	if(i == n-1)printf("%d\n", arr[i]);
			else printf("%d,", arr[i]);
	}

	return 0;
}
