//2016.9.1
#include <iostream>
#include <cstdio>
#define N 15

using namespace std;

int f(int n, int m)
{
	if(n==1 || m==1)return 1;
	else if(n < m)return f(n, n);
	else if(n == m)return (1+f(n, n-1));
	else return f(n-m, m)+f(n, m-1);
}

int main()
{
	int T, n, m;
	cin>>T;
	while(T--)
	{
		scanf("%d%d", &n, &m);
		int ans = f(n, m);
		cout<<ans<<endl;
	}

    return 0;
}
