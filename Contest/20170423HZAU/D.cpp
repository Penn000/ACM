#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long
#define MAXN 100

using namespace std;

int MOD;

struct Matrix  
{  
    LL a[MAXN][MAXN];  
    int r, c; 
};  

Matrix ori, res; 

void init()  
{  
    memset(res.a, 0, sizeof(res.a));  
    res.r = 2; res.c = 2;  
    for(int i = 1; i <= 2; i++)  
        res.a[i][i] = 1;  
    ori.r = 2; ori.c = 2;  
    ori.a[1][1] = ori.a[1][2] = ori.a[2][1] = 1;  
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
                z.a[i][j] = (z.a[i][j] + (x.a[i][k] * y.a[k][j]) % MOD) % MOD;  
        }  
    }  
    return z;  
}  
void Matrix_mod(int n)  
{  
    while(n)  
    {  
        if(n & 1)  
            res = multi(ori, res);  
        ori = multi(ori, ori);  
        n >>= 1;  
    }  
    printf("%lld\n", res.a[1][2] % MOD);  
}  

int main()
{
	int T, n, m;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &n, &m, &MOD);
		LL pos = __gcd(n+2, m+2);
		init();
		Matrix_mod(pos);
	}
	return 0;
}
