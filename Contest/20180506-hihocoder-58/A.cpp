#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 200;

int n, k, arr[N];
bool book[N], fg;

void dfs(int step){
	if(fg)return;
	if(step > n){
		for(int i = 1; i <= n; i++){
			if(i == n)cout<<arr[i]<<endl;
			else cout<<arr[i]<<" ";
		}
		fg = true;
	}
	for(int i = n; i > 0; i--){
		if(!book[i] && abs(i-step)<=k){
			book[i] = 1;
			arr[step] = i;
			dfs(step+1);
			book[i] = 0;
		}
	}
}

int main()
{
	while(cin>>n>>k){
		if(k == 0){
			for(int i = 1; i <= n; i++){
				if(i == n)cout<<i<<endl;
				else cout<<i<<" ";
			}
			continue;
		}
		int len = n/k;
		int cnt = 1;
		if(len == 1){
			for(int i = 1; i <= k; i++){
				if(i+k<=n)
					arr[i] = i+k;
				else arr[i] = n+1-i;
			}
			for(int i = k+1; i <= n; i++){
				arr[i] = i-k;
			}
		}else{
			for(int i = 0; i < len; i++){
				for(int j = 0; j < k; j++){
					if(i%2 == 0){
						if(i == len-1)break;
						arr[cnt] = cnt+k;
						cnt++;
					}else{
						arr[cnt] = cnt-k;
						cnt++;
					}
				}
			}
			if(cnt <= n){
				int m = n-cnt;
				for(int i = 0; i <= m; i++){
					arr[cnt] = n-i;
					cnt++;
				}
			}
		}
		for(int i = 1; i <= n; i++){
			if(i == n)cout<<arr[i]<<endl;
			else cout<<arr[i]<<" ";
		}
		fg = false;
		dfs(1);
	}

	return 0;
}

