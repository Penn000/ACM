//2017-10-08
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const int N = 200;

int n;
struct Bag{
	ll v, w;
	bool operator<(const Bag x) const {
		return v*x.w > w*x.v;
	}
}bag[N];

ll ans, limit;
void dfs(int step, ll wight, ll value){
	if(wight > limit)return;
	if(value > ans)ans = value;
	if(step >= n)return;
	if(value*1.0 + bag[step].v*1.0/(bag[step].w*1.0)*(limit-wight) <= ans*1.0)
	  return;//如果以当前最高的性价比装满剩下的容量，所得价值都不如当前最优解，则剪枝。
	dfs(step+1, wight+bag[step].w, value+bag[step].v);
	dfs(step+1, wight, value);
}

int main()
{
	while(~scanf("%d%lld", &n, &limit)){
		for(int i = 0; i < n; i++){
			scanf("%lld%lld", &bag[i].w, &bag[i].v);
		}
		sort(bag, bag+n);
		ans = 0;
		dfs(0, 0, 0);
		printf("%lld\n", ans);
	}

	return 0;
}
