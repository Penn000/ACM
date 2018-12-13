//2017-10-15
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510000;
int arr[N];

int main()
{
	//freopen("inputI.txt", "r", stdin);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	while(cin>>n>>k){
		long long sum = 0;
		int MAX = 0;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			MAX = max(MAX, arr[i]);
			sum += arr[i];
		}
		sort(arr, arr+n);
		int L = sum/n, R = (sum+n-1)/n;
		int l = 0, r = L, mininum = 0;
		while(l <= r){
			int mid = (l+r)>>1;
			long long tmp = 0;
			for(int i = 0; i < n; i++)
			  	if(arr[i] < mid)
				  	tmp += mid-arr[i];
				else break;
			if(tmp <= k){
				mininum = mid;
				l = mid+1;
			}else r = mid-1;
		}
		l = R, r = MAX;
		int maxinum = 0;
		while(l <= r){
			int mid = (l+r)>>1;
			long long tmp = 0;
			int pos = lower_bound(arr, arr+n, mid)-arr;
			for(int i = pos; i < n; i++)
			  	if(arr[i] > mid)
				  	tmp += arr[i]-mid;
			if(tmp <= k){
				maxinum = mid;
				r = mid-1;
			}else l = mid+1;
		}
		cout<<maxinum-mininum<<endl;
	}

	return 0;
}
