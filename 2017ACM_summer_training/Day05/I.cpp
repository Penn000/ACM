//2017-08-05
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 15;
const double eps = 1e-9;
int n, m, d;
double G[N][N], A[N*N][N*N], x[N*N];
int equ, var;

int Gauss(){
	int i, j, k, col, max_r;
	for(k = 0, col = 0; k < equ && col < var; k++, col++){
		max_r = k;
		for(i = k+1; i < equ; i++)
		  	if(fabs(A[i][col]) > fabs(A[max_r][col]))
			  	max_r = i;
		if(fabs(A[max_r][col]) < eps)return 0;
		if(k != max_r){
			for(j = col; j < var; j++)
			  	swap(A[k][j], A[max_r][j]);
			swap(x[k], x[max_r]);
		}
		x[k] /= A[k][col];
		for(j = col+1; j < var; j++)
		  	A[k][j] /= A[k][col];
		A[k][col] = 1;
		for(i = 0; i < equ; i++)
		  	if(i != k){
			  	x[i] -= x[k]*A[i][k];
			  	for(j = col+1; j < var; j++)
					A[i][j] -= A[k][j]*A[i][col];
				A[i][col] = 0;
		  	}
	}
	return 1;
}

int main()
{
	bool fg = true;
	while(scanf("%d%d%d", &m, &n, &d)!=EOF){
		if(!n && !m)break;
		if(!fg)printf("\n");
		fg = false;
		memset(A, 0, sizeof(A));
		for(int i = 0; i < n; i++)
		  	for(int j = 0; j < m; j++){
			  	scanf("%lf", &G[i][j]);
				x[i*m+j] = G[i][j];
			}
		for(int i = 0; i < n*m; i++){
			int cnt = 0;
			for(int j = 0; j < n*m; j++){
				int x = i/m;
				int y = i%m;
				int dx = j/m;
				int dy = j%m;
				if(abs(x-dx)+abs(y-dy) <= d){
					A[i][j] = 1.0;
					cnt++;
				}else A[i][j] = 0.0;
			}
			x[i] *= cnt;
		}
		equ = n*m;
		var = n*m;
		Gauss();
		for(int i = 0; i < n*m; i++){
			if(i % m == m-1)printf("%8.2lf\n", x[i]);
			else printf("%8.2lf", x[i]);
		}
	}

	return 0;
}
