//2016.8.17
#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long 

using namespace std;

ll ex_gcd(ll a, ll b, ll& x, ll& y)//扩展欧几里得
{
	if(b==0)
	{
		x = 1; 
		y = 0;
		return a;
	}
	ll ans = ex_gcd(b, a%b, x, y);
	ll tmp = x;
	x = y;
	y = tmp-(a/b)*y;
	return ans;
}

int main()
{
	ll a, b, c, x, y, res, n;
	int k;
	while(scanf("%lld%lld%lld%d", &a, &b, &c, &k)!=EOF)
	{
		if(!a&&!b&&!c&&!k)
		  break;
		n = (ll)1<<k;
		res = ex_gcd(c, n, x, y);
		cout<<res<<endl<<x<<endl;
		if((b-a)%res!=0)cout<<"FOREVER"<<endl;
		else 
		{
			x = x*(b-a)/res%n;//方程ax=b-a(mod n)的最小解
			ll tmp = n/res;
			x = (x%tmp+tmp)%tmp;//最小正数解
			printf("%lld\n", x);
		}
	}

	return 0;
}
