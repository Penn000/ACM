//2017-08-04
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int phi(int n){
    int ans = n;
    for(int i = 2; i*i <= n; i++){
        if(n%i==0){
            ans -= ans/i;
            while(n%i==0)
                n /= i;
        }
    }
	if(n > 1)ans = ans - ans/n;
    return ans;
}

int main()
{
    int num;
	while(scanf("%d", &num)!=EOF){
		printf("%d\n", phi(num-1));
	}

	return 0;
}
