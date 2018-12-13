//2017-08-04
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;
int phi[N],prime[N],tot;
long long ans[N];
bool book[N];

void getphi()//线性欧拉函数筛
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
    int n; 
	getphi();
	ans[2] = 1;
	for(int i = 3; i < N; i++){
		ans[i] = ans[i-1]+phi[i];
	}
	while(scanf("%d", &n) && n){
		printf("%lld\n", ans[n]);
	}

	return 0;
}
