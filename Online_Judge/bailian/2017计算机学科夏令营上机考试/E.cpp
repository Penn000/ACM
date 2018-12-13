//2018-06-30
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200;

int n, arr[N], inv_arr[N], dp[N];

int lis(int direction){
	int ans = 0;
	for(int i = 0; i < n; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if(direction == 0){
				if(arr[i] > arr[j])
				  	dp[i] = max(dp[i], dp[j]+1);
			}else{
				if(inv_arr[i] > inv_arr[j])
				  	dp[i] = max(dp[i], dp[j]+1);
			}
		}
		ans = max(ans, dp[i]);
	}
	return ans;
}

int main()
{
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			inv_arr[n-1-i] = arr[i];
		}
		int ans = lis(0);
		ans = max(ans, lis(1));
		cout<<ans<<endl;
	}

	return 0;
}
