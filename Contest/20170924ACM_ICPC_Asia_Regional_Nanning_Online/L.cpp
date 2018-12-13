#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 210000;
int arr[N], w[N], n;
int dp[N];

int Search(int* dp,int len,int num){  
	int low = 1,high = len;  
	while(low <= high){  
		int mid = (low + high) >> 1;  
		if (num == dp[mid]) return mid;  
		if (dp[mid] < num) low = mid + 1;  
		else high = mid - 1;  
	}  
	return low;  
}  

int main()
{
	n = 0;
	while(1){
		scanf("%d", &arr[n++]);
		if(getchar() == '\n')break;
	}
	for(int i = 0; i < n; i++){
		if(arr[i] < 0)w[i] = 0;
		else if(arr[i] > 10000){
			arr[i] -= 10000;
			w[i] = 5;
		}else w[i] = 1;
	}
	int lis = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] >= dp[lis]){
			dp[++lis] = arr[i];
		}
		else{
			int pos = Search(dp, lis, arr[i]);
			dp[pos] = arr[i];
		}
	}
	for(int i = 0; i < n; i++)
	  cout<<dp[i]<<" ";
	cout<<endl;

	return 0;
}
