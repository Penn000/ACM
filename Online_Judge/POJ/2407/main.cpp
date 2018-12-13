//2016.8.17
#include<iostream>
#include<cstdio>

using namespace std;

int phi(int n)
{
	int ans = n;
	for(int i = 2; i <= n; i++)
	{
		if(n%i==0)
		{
			ans -= ans/i;
			while(n%i==0)
				n /= i;
		}
		if(n == 1)break;
	}
	return ans;
}

int main()
{
	int n;
	while(cin>>n&&n)
	{
		cout<<phi(n)<<endl;
	}

	return 0;
}
