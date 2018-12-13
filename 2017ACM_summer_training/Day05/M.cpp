#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const int N = 310;
int n;
ll a[N];

int main()
{
    int T, kase = 0;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		  	scanf("%lld", &a[i]);
	}

	return 0;
}
