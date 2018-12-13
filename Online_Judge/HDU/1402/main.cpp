//2017-09-07
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <complex>
#include <cmath>
#define Complex complex<double>

using namespace std;

const double PI = acos(-1.0);
const int N = 110000;

void fft(Complex y[], int n, int op){
	for(int i = 1, j = n/2; i < n-1; i++){
		if(i<j)swap(y[i], y[j]);
		int k = n/2;
		while(j >= k){
			j -= k;
			k /= 2;
		}
		if(j<k)j += k;
	}
	for(int h = 2; h <= n; h <<= 1){
		Complex wn(cos(-op*2*PI/h), sin(-op*2*PI/h));
		for(int j = 0; j < n; j += h){
			Complex w(1, 0);
			for(int k = j; k < j+h/2; k++){
				Complex u = y[k];
				Complex t = w*y[k+h/2];
				y[k] = u+t;
				y[k+h/2] = u-t;
				w = w*wn;
			}
		}
	}
}

char a[N], b[N];
Complex A[N<<1], B[N<<1];
int ans[N<<1];
void poly_muilt(){
	int n = 1, len1 = strlen(a), len2 = strlen(b);
	while(n<len1*2 || n<len2*2)n<<=1;
	for(int i = 0; i < len1; i++)A[i] = a[len1-i-1]-'0';
	for(int i = len1; i < n; i++)A[i] = 0;
	for(int i = 0; i < len2; i++)B[i] = b[len2-i-1]-'0';
	for(int i = len2; i < n; i++)B[i] = 0;
	fft(A, n, 1);
	fft(B, n, 1);
	for(int i = 0; i < n; i++)
	  	A[i] *= B[i];
	fft(A, n, -1);
	for(int i = 0; i < n; i++)
	  	ans[i] = (int)(A[i].real()/n+0.5);
	for(int i = 0; i < n; i++){
		ans[i+1] += ans[i]/10;
		ans[i] %= 10;
	}
	n = len1+len2-1;
	while(ans[n] <= 0 && n > 0)n--;
	for(int i = n; i >= 0; i--)
	  printf("%c", ans[i]+'0');
	printf("\n");
}

int main()
{
	while(scanf("%s%s", a, b) != EOF){
		poly_muilt();
	}

	return 0;
}
