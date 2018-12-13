//2017-09-10
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long
#define MAXN 100

using namespace std;

const int MOD = 998244353;

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
	printf("%lld\n", res.a[1][2]-1 % MOD);  
}  

int main()
{
	int k;
	while(scanf("%d", &k) != EOF)
	{
		init();
		k++;
		Matrix_mod(2*k+1);
	}
	return 0;
}
