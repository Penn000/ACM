//2016.8.22
#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

const int N = 100005;
const int inf = 0x3f3f3f3f;
int arr[N], sum[N*2];

int main()
{
	int T, n, k, bg, ed;
	cin>>T;
	while(T--)
	{
		scanf("%d%d", &n, &k);
		sum[0] = 0;
		for(int i = 1; i <= n; i++)
		{
		  	scanf("%d", &arr[i]);
			sum[i] = sum[i-1]+arr[i];
		}
		for(int i = n+1; i < n+k; i++)
		  	sum[i] = sum[i-1]+arr[i-n];//求一个前缀和
		int ans = -inf;
		deque<int> dq;//双端队列
		for(int i = 1; i <= n+k-1; i++)
		{
			while(!dq.empty()&&sum[i-1]<sum[dq.back()])//保持单调，使队首的sum尽量小
			  	dq.pop_back();
			while(!dq.empty()&&dq.front()<i-k)
			  	dq.pop_front();
			dq.push_back(i-1);
			if(sum[i]-sum[dq.front()]>ans)//sum[i]-sum[dq.front()]就是子段的和
			{
				ans = sum[i]-sum[dq.front()];
				bg = dq.front()+1;
				ed = i;
			}
		}
		if(ed>n)ed %= n;
		printf("%d %d %d\n", ans, bg, ed);
	}

	return 0;
}
