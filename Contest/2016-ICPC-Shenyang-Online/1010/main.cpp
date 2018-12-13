#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define ll long long 
#define N 1000010

using namespace std;

int num[N], prime[50]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

bool is_prime(ll x)
{
	for(int i = 0; i < 25; i++)
	  	if(x%prime[i]==0)return false;
	for(int i = 100; i <= sqrt(x); i++)
	  	if(x % i == 0)
		  	return false;
	return true;
}

int main()
{
	int cnt = 0;
	memset(num, 0, sizeof(num));
	for(ll i = 2; i <= 100005; i++)
	{
		if(is_prime(i))
		  	pri[cnt++] = i;
	}
	int ct = 1;
	num[1] = 0;
	num[2] = 1;
	for(int i = 3; i <= 1000005; i++)
	{
		if(i%2==1)
			if(is_prime(i))ct++;
		num[i] = ct;
	}
	for(int i = 0; i < cnt; i++)
	  	cout<<pri[i]<<endl;
	printf("------------------------\n");
	cout<<cnt<<endl;
	ll n;
	while(scanf("%lld", &n)!=EOF)
	{
		if(n <= 1000005){
			printf("%d\n", num[n]);	
		}
		else{
			int count = ct;
			for(ll i = 1000006; i <= n; i++)
			  	if(is_prime(i))
				  	count++;
			printf("%d\n", count);
		}
	}

    return 0;
}
