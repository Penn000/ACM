#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll n, m;

int main()
{
	while(cin>>n>>m){
		if(n > m)swap(n, m);
		if((m-1)%(n-1) == 0){
			cout<<m<<endl;
		}else{
			ll gcd = __gcd(n-1, m-1);
			if(gcd == 1)
			  	cout<<n+m-2<<endl;
			else{
				cout<<((n-1)/gcd)*((m-1)/gcd)*(gcd-1)+ (n-1)/gcd + (m-1)/gcd<<endl;
			}
		}
	}

	return 0;
}
