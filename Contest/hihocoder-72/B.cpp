//2018-08-12
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int main(){
	ll n, k, p;
	cin>>n>>k>>p;
	ll num2 = 1LL;
	for(int i = 0; i < n-2; i++)
	  num2 = (num2*(n-i))%p;
	ll num1 = (num2*2)%p;
	if(n==k){
		cout<<1<<endl;
	}else if(k == n-1){
		cout<<n<<endl;
	}else{
		if(k&1LL){
			cout<<num1<<endl;
		}else cout<<num2<<endl;
	}
	return 0;
}
