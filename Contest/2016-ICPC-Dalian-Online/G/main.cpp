#include <iostream>
#include <cstdio>

using namespace std;

long long fun(int m)
{
	long long ans;
	ans = (m/2)*(m/2);
	if(m%2)ans += (m/2);
	return ans;
}

int main()
{
	long long n, m, res;
	while(scanf("%lld%lld", &m, &n)!=EOF)
	{
		res = fun(m);
		if(n>=res)
		  printf("T\n");
		else printf("F\n");
	}

    return 0;
}
