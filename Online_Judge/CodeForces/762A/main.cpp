//2017.02.01
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int divisor[35000000];

int main()
{
	long long n, k;
	while(cin>>n>>k)
	{
		long long ans = -1;
		int cnt = 0;
		bool fg = false;
		for(long long i = 1; i*i <= n; i++)
		{
			if(n%i==0)divisor[++cnt] = i;
			if(i*i == n)fg = true;
		}
		if(fg && k > 2*cnt-1)cout<<-1<<endl;
		else if(k > 2*cnt)cout<<-1<<endl;
		else if(k<=cnt)cout<<divisor[k]<<endl;
		else{
			if(!fg)cout<<(n/divisor[2*cnt+1-k])<<endl;
			else cout<<(n/divisor[2*cnt-k])<<endl;
		}
	}

    return 0;
}
