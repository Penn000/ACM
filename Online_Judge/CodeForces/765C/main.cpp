//2017-02-14
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	long long k, a, b;
	while(cin>>k>>a>>b)
	{
		long long ans = a/k+b/k;
		if(ans == 0 && a+b > 0)cout<<"-1"<<endl;
		else if(a < k && b%k != 0)cout<<"-1"<<endl;
		else if(b < k && a%k != 0)cout<<"-1"<<endl;
		else cout<<ans<<endl;
	}

    return 0;
}
