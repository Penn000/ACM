#include <stdio.h>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		vec.push_back(t);
	}
	long long ans = 0;
	for (int i = 0; i < n; i++)
	  for (int j = 0; j < n - 1; j++)
		if (vec[j] > vec[j+1])
		{
			ans++;
			swap(vec[j], vec[j+1]);
		}
	printf("%lld\n", ans);
	return 0;
}
