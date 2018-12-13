//2017-09-17
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const int N = 600000;

ll cubic[N+100];
ll diff[N+100];

bool check(ll p){
	int pos = lower_bound(diff+1, diff+N, p) - diff;
	if(diff[pos] == p)
	  return true;
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);
	ll p;
	for(ll i = 1; i <= N; i++)
		cubic[i] = i*i*i;
	for(int i = 1; i <= N; i++)
		diff[i] = cubic[i+1]-cubic[i];
	while(T--){
		scanf("%lld", &p);
		if(check(p))
		  printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
