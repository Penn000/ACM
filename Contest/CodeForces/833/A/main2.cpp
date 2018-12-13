//2017-08-16
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long 

using namespace std;

int main()
{
    int n;
	ll a, b, c;
	while(scanf("%d", &n)!=EOF){
		for(int i = 0; i < n; i++){
			scanf("%I64d%I64d", &a, &b);
			c = ceil(pow(a*b, 1.0/3));//ceil为向上取整函数
			if(c*c*c == a*b && a%c==0 && b%c==0)
			  	printf("Yes\n");
			else printf("No\n");
		}
	}

	return 0;
}
