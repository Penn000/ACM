//2017-09-10
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int main()
{
	ll n, k;
	while(cin>>n>>k){
		cout<<(n-k+1)*k<<endl;
	}

	return 0;
}
