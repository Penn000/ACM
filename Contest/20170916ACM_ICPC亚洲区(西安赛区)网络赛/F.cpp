#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <complex>
#include <cmath>
#include <math.h>

template<class TN>
inline void kread(TN &x)
{
	x=0;
	char c;
	bool flag=false;
	while(!isdigit(c=getchar()))
		if(c=='-')
			flag=true;
	do{
		x=x*10+c-48;
	}while(isdigit(c=getchar()));
	if(flag)x=-x;
}

template<class TN,class... ARGS>
inline void kread(TN &first,ARGS& ... args)
{
	kread(first);
	kread(args...);
}

using namespace std;

long long MOD=998244353;

inline long long mod(long long x)
{
	return x%MOD;
	if(x<0)x+=MOD;
}

typedef complex<double> Complex;
const double PI=acos(-1.0);

int lowbit(int x)
{
	return x&-x;
}

int getN(int n)//返回大于等于n的最小的2^t的值
{
	int nn=1;
	while(nn<n)nn<<=1;
	return nn;
}

//规则化数组,使长度n变为2^t的形式,并在多余部分填充0
void normalize(Complex x[],int &n)
{
	int nn=getN(n);
	fill(x+n,x+nn,0);
	n=nn;
}

//n必须为2^t,若不是,用normalize转换
//on==1为DFT,on==-1为IDFT
void fft(Complex x[],int n,int on=1)
{
	//循环模拟递归向下数组最终样子,位置i和(i二进制对称的数)互换就行了
	for(int i=1;i<n;i++)
	{
		int j=0;
		for(int k=i;k;k^=lowbit(k))
			j|=n/lowbit(k);
		j>>=1;
		if(i<j)swap(x[i],x[j]);
	}

	//循环模拟递归回溯
	double ww=-2.0*PI*on;//中间变量,字面上意思
	for(int i=1,j=2;j<=n;i<<=1,j<<=1)
	{
		Complex wn(cos(ww/j),sin(ww/j));
		for(int k=0;k<n;k+=j)
		{
			Complex w(1.0);
			for(int t=k;t<k+i;t++)
			{
				Complex a(x[t]);
				Complex b(x[t+i]*w);
				x[t]=a+b;
				x[t+i]=a-b;
				w*=wn;
			}
		}
	}

	if(on==-1)
		for(int i=0;i<n;i++)
			x[i]/=n;
}

const int MAXM=666666;
int n;
int m;
int M;
Complex xc[MAXM],yc[MAXM];

struct Poly{
	vector<int> q;

	Poly():q(m+10)
	{
	}

	Poly(const Poly &o):q(o.q)
	{
	}

	Poly(Poly &&o):q(move(o.q))
	{
	}

	const Poly& operator=(const Poly &o)
	{
		if(&o==this)return *this;
		q=o.q;
		return *this;
	}

	const Poly& operator=(Poly&& o)
	{
		if(&o==this)return *this;
		q=move(o.q);
		return *this;
	}

	inline int& operator[](int i)
	{
		return q[i];
	}

	inline int operator[](int i)const
	{
		return q[i];
	}

	void clear()
	{
		for(int i=0;i<=m;i++)q[i]=0;
	}

	Poly operator*(const Poly &o)const
	{
		for(int i=0;i<=m;i++)
		{
			xc[i]=q[i];
			yc[i]=o[i];
		}
		for(int i=m+1;i<M;i++)
			xc[i]=yc[i]=0;
		fft(xc,M);
		fft(yc,M);
		for(int i=0;i<M;i++)xc[i]*=yc[i];
		fft(xc,M,-1);
		Poly ans;
		for(int i=0;i<=m;i++)ans[i]=mod((long long)floor(xc[i].real()+0.5));
		return ans;
	}

	Poly operator+(const Poly &o)const
	{
		Poly ans;
		for(int i=0;i<=m;i++)
		{
			ans[i]=mod(o[i]+q[i]);
		}
		return ans;
	}
};

struct Matrix{
	Poly a[2][2];
	int r, c;
	Matrix()
	{
	}
	Matrix(int r,int c):r(r),c(c)
	{
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				a[i][j].clear();
	}
	Matrix(Matrix&& o)
	{
		r=o.r;c=o.c;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				a[i][j]=move(o.a[i][j]);
	}

	Matrix(const Matrix &o)
	{
		r=o.r;c=o.c;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				a[i][j]=o.a[i][j];
	}

	const Matrix& operator=(Matrix&& o)
	{
		if(&o==this)return *this;
		r=o.r;c=o.c;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				a[i][j]=move(o.a[i][j]);
		return *this;
	}

	const Matrix& operator=(const Matrix &o)
	{
		if(&o==this)return *this;
		r=o.r;c=o.c;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				a[i][j]=o.a[i][j];
		return *this;
	}
};

Matrix multi(const Matrix &x, const Matrix &y)//矩阵乘法
{
	Matrix z;
	z.r = x.r, z.c = y.c;
	for(int i=0;i<z.r;i++)
		for(int j=0;j<z.c;j++)
			z.a[i][j].clear();
	for(int i = 0; i < x.r; i++){
		for(int k = 0; k < x.c; k++)//加速优化
		{
			for(int j = 0; j< y.c; j++)
				z.a[i][j] =(
					z.a[i][j] + (x.a[i][k] * y.a[k][j])
					);
		}
	}
	return z;
}

Matrix kpow(Matrix a,Matrix b,int n)//a*b^n
{
	while(n){
		if(n & 1)
			a = multi(a, b);
		b = multi(b, b);
		n >>= 1;
	}
	return a;
}

int kpow(long long a,int k)
{
	long long b=1;
	while(k)
	{
		if(k&1)b=mod(a*b);
		a=mod(a*a);
		k>>=1;
	}
	return b;
}

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		if(((n^m)&1)||m>n)
		{
			puts("0");
			continue;
		}
		if(n==m)
		{
			printf("%d\n",kpow(2,m-1));
			continue;
		}
		if((n&1)==0)
		{
			if(m==0)
			{
				if((n&2)==0)
				{
					puts("1");
					continue;
				}
				else
				{
					printf("%lld\n",MOD-1);
					continue;
				}
			}
		}
		M=getN(m+1)<<1;

		Matrix a(1,2),b(2,2);

		a.a[0][0][1]=1;a.a[0][1][0]=1;

		b.a[0][0][1]=2;b.a[0][1][0]=1;
		b.a[1][0][0]=MOD-1;

		a=kpow(move(a),move(b),n);
		printf("%d\n",a.a[0][1][m]);
	}
	return 0;
}


