#include<iostream>
#include<cstdio>
#define ll long long 

using namespace std;

const int N = 1e6+5;

ll ex_gcd(ll a, ll b, ll& x, ll& y)
{
	if(b == 0)
	{
		x = 1; 
		y = 0;
		return a;
	}else
	{
		ll d = ex_gcd(b, a%b, x, y);
		ll tmp = x;
		x = y;
		y = tmp-(a/b)*y;
	}
}

int main()
{
	int n, m, k;
	while(cin>>n>>m>>k)
	{
		for(int i = 1; i <= k; i++)
		{

		}
	}

	return 0; 
}
