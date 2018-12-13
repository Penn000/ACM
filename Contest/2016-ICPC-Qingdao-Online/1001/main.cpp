//2016.9.17
#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 10000
#define ll long long 

using namespace std;

int arr[N];

ll pow(ll a, ll b)
{
	ll ans = 1;
	while(b)
	{
		if(b & 1)ans *= a;
		a *= a;
		b>>=1;
	}
	return ans;
}

int main()
{
	ll tmp; int cnt = 0;
	for(int a = 0; a < 31; a++)
	{
		for(int b = 0; b < 20; b++)
		{
			for(int c = 0; c < 14; c++)
			{
				for(int d = 0; d < 12; d++)
				{
					tmp = pow(2, a)*pow(3, b);
					if(tmp > 1e9)break;
					tmp *= pow(5, c);
					if(tmp > 1e9)break;
					tmp *= pow(7, d);
					if(tmp > 1e9)break;
					arr[cnt++] = tmp;
				}
			}
		}
	}
	sort(arr, arr+cnt);
	int T, n;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		int pos = lower_bound(arr, arr+cnt, n)-arr;
		printf("%d\n", arr[pos]);
	}

    return 0;
}
