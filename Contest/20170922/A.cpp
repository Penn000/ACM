//2017-09-22
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int main()
{
	int T;
	ll n;
	cin>>T;
	while(T--){
		cin>>n;
		if(n == 1)cout<<2<<endl;
		else if(n&1)cout<<n/2+2<<endl;
		else cout<<n/2+1<<endl;
	}

	return 0;
}
