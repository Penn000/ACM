//2017.02.08
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void extend_Euclid(int a, int b, int &x, int &y)
{
	if(b==0){
		x = 1;
		y = 0;
		return;
	}
	extend_Euclid(b, a%b, x, y);
	int tmp = x;
	x = y;
	y = tmp-(a/b)*y;
}

int CRT(int *a, int *m, int n)
{
	int M = 1, ans = 0;
	for(int i = 1; i <= n; i++) M*=m[i];
	for(int i = 1; i <= n; i++){
		int x, y;
		int Mi = M/m[i];
		extend_Euclid(Mi, m[i], x, y);
		ans = (ans+Mi*x*a[i])%M;
	}
	if(ans < 0) ans+=M;
	return ans;
}

int main()
{
	int a[5], m[5] = {0, 23, 28, 33}, d, kase = 0;
	while(cin>>a[1]>>a[2]>>a[3]>>d)
	{
		if(a[1]==-1&&a[2]==-1&&a[3]==-1&&d==-1)break;
		int ans = CRT(a, m, 3);
		if(ans <= d) ans+=21252;
		printf("Case %d: the next triple peak occurs in %d days.\n", ++kase, ans-d);
	}

    return 0;
}
