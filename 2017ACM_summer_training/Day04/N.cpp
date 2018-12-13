//2017-08-04
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;
int mu[N], prime[N], tot, phi[N];
long long plane[N];
bool book[N];

void Moblus()//求出莫比乌斯函数
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

void getphi()    
{    
   int i,j;    
   phi[1]=1;    
   for(i=2;i<=N;i++)//相当于分解质因式的逆过程    
   {    
       if(!book[i])
	   {    
    		prime[++tot]=i;//筛素数的时候首先会判断i是否是素数。    
            phi[i]=i-1;//当 i 是素数时 phi[i]=i-1    
        }    
       for(j=1;j<=tot;j++)    
       {    
          if(i*prime[j]>N)  break;    
          book[i*prime[j]]=1;//确定i*prime[j]不是素数    
          if(i%prime[j]==0)//接着我们会看prime[j]是否是i的约数    
          {    
             phi[i*prime[j]]=phi[i]*prime[j];break;    
          }    
          else  phi[i*prime[j]]=phi[i]*(prime[j]-1);//其实这里prime[j]-1就是phi[prime[j]]，利用了欧拉函数的积性    
       }    
   }    
}

int main()
{
    int T, n;
	scanf("%d", &T);
	Moblus();
	getphi();
	plane[2] = 1;
	for(int i = 3; i < N; i++){
		plane[i] = plane[i-1]+phi[i];
	}
	while(T--){
		scanf("%d", &n);
		long long ans = 3;
		for(int d = 1; d <= n; d++){
			int tmp = (int)(n/d);
			ans += (long long)mu[d]*tmp*tmp*tmp;
		}
		ans += 3*(plane[n]*2+1);
		printf("%lld\n", ans);
	}

	return 0;
}
