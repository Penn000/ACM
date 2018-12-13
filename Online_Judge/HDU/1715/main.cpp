#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const int N = 10;

struct Matrix{  
	ll a[N][N];  
	int r, c; 
}ori, res;  

void init(){  
	memset(res.a, 0, sizeof(res.a));  
	res.r = 2; res.c = 2;
	for(int i = 1; i <= 2; i++)
	  	res.a[i][i] = 1;
	ori.r = 2; ori.c = 2;//构造矩阵
	ori.a[1][1] = 1;
	ori.a[1][2] = 1;
	ori.a[2][1] = 1;  
	ori.a[2][2] = 0;  
}

Matrix multi(Matrix x, Matrix y)//矩阵乘法
{
	Matrix z;
	memset(z.a, 0, sizeof(z.a));  
	z.r = x.r, z.c = y.c;
	for(int i = 1; i <= x.r; i++){
		for(int k = 1; k <= x.c; k++)//加速优化
		{
			if(x.a[i][k] == 0) continue;
			for(int j = 1; j<= y.c; j++)
			  z.a[i][j] = (z.a[i][j] + (x.a[i][k] * y.a[k][j]));

		}

	}
	return z;

}

void Matrix_pow(int n)//矩阵快速幂
{  
	while(n){  
		if(n & 1)  
		  res = multi(res, ori);  
		ori = multi(ori, ori);  
		n >>= 1;  
	}  
	printf("%llu\n", res.a[1][1]);  
}  

int main()
{
	int T, n;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		init();
		Matrix_pow(n-1);
	}

	return 0;
}
