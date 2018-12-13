#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const int N = 100010;
int fac_a[N], fac_b[N];

bool check(int a, int b){
	if(a == 1 && b == 1)return true;
	if(__gcd(a, b) == 1)return false;
	memset(fac_a, 0, sizeof(fac_a));
	memset(fac_b, 0, sizeof(fac_b));
	int len = 0, tmp = a;
	while(a > 1){
		for(int i = 2; i <= a; i++){
			if(a%i == 0){
				while(a % i == 0){
					a /= i;
					fac_a[i]++;
				}
				len = max(len, i);
			}
			if(a != 1 && __gcd(a, b)==1)return false;
		}
	}
	while(b > 1){
		for(int i = 2; i <= b; i++){
			if(b%i == 0){
				while(b % i == 0){
					b /= i;
					fac_b[i]++;
				}
				len = max(len, i);
			}
			if(b != 1 && __gcd(tmp, b)==1)return false;
		}
	}
	for(int i = 2; i <= len; i++){
		int a = max(fac_a[i], fac_b[i]);
		int b = min(fac_a[i], fac_b[i]);
		if((2*a-b)%3 != 0)return false;
	}
	return true;
}

int main()
{
    //freopen("input.txt", "r", stdin);
	int n, a, b;
	while(cin>>n){
		for(int i = 0; i < n; i++){
			cin>>a>>b;
			if(check(a, b))
			  	cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}

	return 0;
}
