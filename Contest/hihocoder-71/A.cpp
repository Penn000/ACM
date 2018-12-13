// 2018-08-05
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int n, k, a;
	scanf("%d%d", &n, &k);
	map<int, int> mp;
	int ans = -1;
	for(int i = 0; i < n; i++){
		scanf("%d", &a);
		a%=k;
		if(mp[k-a])ans = 2;
		++mp[a];
	}
	if(mp[0]>=2)
	  ans = max(ans, mp[0]);
	if(k%2==0 && mp[k/2]>=2)
	  ans = max(ans, mp[k/2]);

	printf("%d\n", ans);

	return 0;
}
