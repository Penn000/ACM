#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110000;
int arr[N], n, tail;

bool check(int len){
	for(int l = 0; l+len < n; l++){
		int r = l+len;
		bool fg = true;
		if(l-2>=0 && arr[l-1]<arr[l-2])return false;
		if(l-1>=0 && arr[l-1]>arr[r])continue;
		if(r<tail)fg = false;
		if(fg)return true;
	}
	return false;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	tail = n-1;
	while(tail>=0 && arr[tail-1]<=arr[tail])tail--;
	int l = 0, r = n-1;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid))r = mid;
		else l = mid+1;
	}
	printf("%d\n", r);

	return 0;
}
