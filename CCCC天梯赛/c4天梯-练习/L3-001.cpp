//2018-03-15
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;
int arr[N], book[N], suffix_sum[N];//后缀和
int n, m;
bool ok;

void dfs(int step, int money){
	//剪枝
	if(step > n || ok || money > m || money+suffix_sum[step] < m)return;
	if(money == m){
		ok = true;
		bool first = true;
		for(int i = 0; i < n; i++){
			if(book[i]){
				if(first){
					printf("%d", arr[i]);
					first = false;
				}else{
					printf(" %d", arr[i]);
				}
			}
		}
		printf("\n");
	}
	book[step] = 1;
	dfs(step+1, money+arr[step]);
	book[step] = 0;
	dfs(step+1, money);
}

int main()
{
	while(~scanf("%d%d", &n, &m))
	{
		for(int i = 0; i < n; i++)
		  	scanf("%d", &arr[i]);
		sort(arr, arr+n);
		suffix_sum[n] = 0;
		for(int i = n-1; i >= 0; i--)
		  	suffix_sum[i] = suffix_sum[i+1]+arr[i];
		ok = false;
		memset(book, 0, sizeof(book));
		dfs(0, 0);
		if(!ok)printf("No Solution\n");
	}

    return 0;
}
