#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100;
const int A = 200000;
int arr[N], n, dp[N][N];
int main()
{
	std::ios::sync_with_stdio(false);
	while(cin>>n){
		for(int i = 1; i <= n; i++)
		  cin>>arr[i];
		for(int i = 0; i <= n; i++)
		  for(int j = 0; j <= n; j++)
			dp[i][j] = A;
		for(int len = 2; len <= n; len+=2){
			for(int l = 1, r = l+len-1; r <= n; l++, r++){
				if(len == 2)
				  dp[l][r] = abs(arr[l]-arr[r])+A;
				else{
					if(arr[l] < arr[r]){
						dp[l][r] = min(dp[l+1][r-1]+arr[r]-arr[l], dp[l][r-2]+arr[r]-arr[r-1]);
					}else{
						dp[l][r] = min(dp[l+2][r]+arr[l]-arr[l+1], dp[l+1][r-1]+arr[l]-arr[r]);
					}
				}
			}
		}
		//for(int i = 1; i <= n; i++){
		//	for(int j = 1; j <= n; j++)
		//	  	cout<<dp[i][j]<<" ";
		//	cout<<endl;
		//}
		if(dp[1][n] <= A)cout<<"The child will be unhappy..."<<endl;
		else cout<<dp[1][n]-A<<endl;
	}

	return 0;
}
