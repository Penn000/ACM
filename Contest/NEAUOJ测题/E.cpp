#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1100000;
int n, k;
long long arr[N];

long long book[N][2];
bool check(int l){
	int cnt = l;
	bool fg = 0;
	for(int i = 0; i < l; i++)
	  book[i][fg] = arr[i];
	for(int i = 1; i < k; i++){
		for(int j = 0; j < l; j++){
			while(cnt < n && arr[cnt] < book[j][fg]*2)
			  cnt++;
			if(cnt >= n)return false;
			book[j][!fg] = arr[cnt++];
		}
		fg = !fg;
	}
	return true;
}

int main()
{
	while(~scanf("%d%d", &n, &k)){
		for(int i = 0; i < n; i++)
		  scanf("%lld", &arr[i]);
		sort(arr, arr+n);
		int ans = 0;
		int l = 0, r = n/k;
		while(l <= r){
			int mid = (l+r)>>1;
			if(check(mid)){
				ans = mid;
				l = mid+1;
			}else r = mid-1;
		}
		cout<<ans<<endl;
	}

	return 0;
}
