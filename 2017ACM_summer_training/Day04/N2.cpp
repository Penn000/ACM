#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;
int mu[N], prime[N];
bool book[N];

void Moblus()
{
    memset(book,false,sizeof(book));
    mu[1] = 1;
    int tot = 0;
    for(int i = 2; i <= N; i++){
        if(!book[i]){
            prime[tot++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < tot; j++){
            if(i * prime[j] > N) break;
            book[i * prime[j]] = true;
            if( i % prime[j] == 0){
                mu[i * prime[j]] = 0;
                break;
            }else{
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
}

int main()
{
    int T, n;
	scanf("%d", &T);
	Moblus();
	while(T--){
		scanf("%d", &n);
		long long ans = 3;
		for(int d = 1; d <= n; d++){
			int tmp = (int)(n/d);
			ans += (long long)mu[d]*tmp*tmp*(tmp+3);
		}
		printf("%lld\n", ans);
	}

	return 0;
}
