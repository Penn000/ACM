//2017-08-05
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll a, b, n;
ll p, q;
const int N = 5;
ll MOD;

struct Matrix  
{  
    ll a[N][N];  
    int r, c; 
}ori, res;  

void init()  
{  
    memset(res.a, 0, sizeof(res.a));  
    res.r = 1; res.c = 2;
    res.a[1][1] = p;
    res.a[1][2] = 2;
    ori.r = 2; ori.c = 2;  
    ori.a[1][1] = p;
    ori.a[1][2] = 1;
    ori.a[2][1] = -q;  
    ori.a[2][2] = 0;  
}  

Matrix multi(Matrix x, Matrix y)  
{  
    Matrix z;  
    memset(z.a, 0, sizeof(z.a));  
    z.r = x.r, z.c = y.c;    
    for(int i = 1; i <= x.r; i++) 
    {  
        for(int k = 1; k <= x.c; k++)      
        {  
            if(x.a[i][k] == 0) continue;
            for(int j = 1; j<= y.c; j++)  
                z.a[i][j] = (z.a[i][j] + (x.a[i][k] * y.a[k][j]) % MOD + MOD) % MOD;  
        }  
    }  
    return z;  
}  

void Matrix_pow(int n)  
{  
    while(n)  
    {  
        if(n & 1)  
            res = multi(res, ori);  
        ori = multi(ori, ori);  
        n >>= 1;  
    }  
    printf("%lld\n", res.a[1][1] % MOD);
}  

int main()
{
	while(scanf("%lld%lld%lld%lld", &a, &b, &n, &MOD)!=EOF){
		p = 2*a;
		q = a*a-b;
		init();
		if(n == 0)printf("2\n");
		else if(n == 1)printf("%lld\n", p);
		else Matrix_pow(n-1);
	}

	return 0;
}
