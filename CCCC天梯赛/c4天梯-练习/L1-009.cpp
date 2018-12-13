//2017-03-16
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	char ch;
	long long a, b, gcd;
	while(cin>>n)
	{
		long long A = 0, B = 1, tmp;
		for(int i = 0; i < n; i++)
		{
			cin>>b>>ch>>a;
			tmp = a*A+b*B;
			B = a*B;
			A = tmp;
			gcd = __gcd(A, B);
			A/=gcd;
			B/=gcd;
		}
		if(A==0){
			cout<<0<<endl;
			continue;
		}
		if(A/B && A%B)cout<<A/B<<" ";
		else if(A/B)cout<<A/B<<endl;
		if(A%B)cout<<(A%B)<<"/"<<B<<endl;
	}

    return 0;
}
