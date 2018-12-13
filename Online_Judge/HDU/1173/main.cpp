//2016.9.22
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1000005;
double x[N], y[N];

int main()
{
	int n;
	while(scanf("%d", &n)!=EOF && n)
	{
		for(int i = 0; i < n; i++)
		  	scanf("%lf%lf", &x[i], &y[i]);
		sort(x, x+n);
		sort(y, y+n);
		printf("%.2lf %.2lf\n", x[n/2], y[n/2]);
	}

    return 0;
}
