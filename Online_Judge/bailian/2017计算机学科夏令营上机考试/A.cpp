//2018-06-26
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 123456;

bool prime[N];

bool isPrime(int x){
	for(int i = 2; i*i <= x; i++)
	  if(x%i==0)
		return false;
	return true;
}

int main()
{
	prime[1] = false;
	prime[2] = true;
	for(int i = 2; i < 100001; i++)
	  prime[i] = isPrime(i);

	int l, r;
	while(cin>>l>>r){
		if(l > r)swap(l, r);
		int cnt = 0;
		for(int i = l; i <= r; i++)
		  if(prime[i])
			cnt++;
		cout<<cnt<<endl;
	}

	return 0;
}
