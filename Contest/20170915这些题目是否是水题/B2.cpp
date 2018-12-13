#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

const int N = 100;
const int INF = 0x3f3f3f3f;
int dpmax[N][N], dpmin[N][N];
int n, arr[N];
int ST;  
int LIM = 1 * CLOCKS_PER_SEC;

void init(){
	memset(dpmin, INF, sizeof(dpmin));
	memset(dpmax, -INF, sizeof(dpmax));
	for(int i = 1; i <= n+1; i++)
	  	dpmax[i][i-1]  = dpmin[i][i-1] = 0;
	for(int l = n; l >= 1; l--){
		for(int r = l; r <= n; r++){
			int ll = l, rr = r, tmp;
			if(arr[ll] >= arr[rr])tmp = arr[ll++];
			else tmp = arr[rr--];
			dpmax[l][r] = max(dpmax[l][r], dpmax[ll+1][rr]+arr[ll]-tmp);
			dpmin[l][r] = min(dpmin[l][r], dpmin[ll+1][rr]+arr[ll]-tmp);
			dpmax[l][r] = max(dpmax[l][r], dpmax[ll][rr-1]+arr[rr]-tmp);
			dpmin[l][r] = min(dpmin[l][r], dpmin[ll][rr-1]+arr[rr]-tmp);
		}
	}
}

int ans;
void dfs(int l, int r, int diff){
	if(l > r){
		ans = max(ans, diff);
		return;
	}
	if(diff + dpmin[l][r] >= 0)return;
	if(diff + dpmax[l][r] <= ans)return;
	if(diff + dpmax[l][r] < 0){
		ans = max(ans, diff+dpmax[l][r]);
		return;
	}
	int tmp;
	if(arr[l] >= arr[r])tmp = arr[l++];
	else tmp = arr[r--];
	if (clock() - ST > LIM)return;
	dfs(l+1, r, diff+arr[l]-tmp);
	dfs(l, r-1, diff+arr[r]-tmp);
}

int main()
{
	while(scanf("%d", &n) != EOF){
		for(int i = 1; i <= n; i++)
		  	scanf("%d", &arr[i]);
		init();
		ST = clock();
		ans = -INF;
		dfs(1, n, 0);
		if(ans == -INF){
			cout<<"The child will be unhappy..."<<endl;
		}else cout<<-ans<<endl;
	}

	return 0;
}
