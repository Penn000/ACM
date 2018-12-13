//2016.8.6
#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>

using namespace std;

int l[305], c[305];
map<int, int>dp1, dp2;

/*
int min(int a, int b)
{
	if(a == 0)return b;
	if(b == 0)return a;
	return a>b?b:a;
}*/

int gcd(int a, int b)
{
	return b==0?a:gcd(b, a%b);
}

int main()
{
	int n;
	while(cin>>n)
	{
		dp1.clear();
		for(int i = 1; i <= n; i++)
		  scanf("%d", &l[i]);
		for(int i = 1; i <= n; i++)
		  scanf("%d", &c[i]);
		dp1[0] = 0;
		for(int i = 1; i <= n; i++)
		{
			map<int, int>::iterator it;
			for(it = dp1.begin(); it != dp1.end(); it++)
			{
				int g = gcd(it->first, l[i]);
				if(dp1.count(g))
				  dp1[g] = min(it->second+c[i], dp1[g]);
				else dp1[g] = it->second+c[i];
			}
		}
		if(dp1.count(1))cout<<dp1[1]<<endl;
		else cout<<-1<<endl;
	}

	return 0;
}
