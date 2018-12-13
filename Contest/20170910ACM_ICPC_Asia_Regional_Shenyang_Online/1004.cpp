//2017-09-10
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110000;
int arr[N], rarr[N], n, k;
int dp1[N], dp2[N];

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
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++)
		  	scanf("%d", &arr[i]);
		for(int i = 1; i <= n; i++)
		  	rarr[i] = arr[n-i+1];
		int lis = 1;
		dp1[0] = -1;
		dp1[1] = arr[1];
		for(int i = 1; i <= n; i++){
			if(arr[i] > dp1[lis])
			  	dp1[++lis] = arr[i];
			else{
				int pos = Search(dp1, lis, arr[i]);
				dp1[pos] = arr[i];
			}
		}
		int lds = 1;
		dp2[0] = -1;
		dp2[1] = rarr[1];
		for(int i = 1; i <= n; i++){
			if(rarr[i] > dp2[lds])
			  	dp2[++lds] = rarr[i];
			else{
				int pos = Search(dp2, lds, rarr[i]);
				dp2[pos] = rarr[i];
			}
		}
		//printf("%d %d\n", lis, lds);
		if(n-k <= lis || n-k <= lds)
		  	printf("A is a magic array.\n");
		else
		  	printf("A is not a magic array.\n");
	}

	return 0;
}
