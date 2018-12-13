#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cctype>

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

long long n;
long long x[11111];
long long y[11111];

long long xmult(long long p1,long long p2,long long p0)
{
	return (x[p1]-x[p0])*(y[p2]-y[p0])-(x[p2]-x[p0])*(y[p1]-y[p0]);
}

bool isIntersected(long long s1,long long e1, long long s2,long long e2)
{
	return (max(x[s1],x[e1]) >= min(x[s2],x[e2])) &&
		(max(x[s2],x[e2]) >= min(x[s1],x[e1])) &&
		(max(y[s1],y[e1]) >= min(y[s2],y[e2])) &&
		(max(y[s2],y[e2]) >= min(y[s1],y[e1])) &&
		(xmult(s1,s2,e1)*xmult(s1,e1,e2)>0) &&
		(xmult(s2,s1,e2)*xmult(s2,e2,e1)>0);
}

bool lessthan(long long p1,long long p2)
{
	if(x[p1]!=x[p2])return x[p1]<x[p2];
	return y[p1]<y[p2];
}

void print(long long a,long long b)
{
	puts("YES");
	for(long long i=0;i<n;i++)
	{
		if(i==a||i==b)putchar('A');
		else putchar('B');
	}
	putchar('\n');
}

void print(long long a,long long b,long long c)
{
	long long minx=a,maxx=a;

	if(lessthan(b,minx))minx=b;
	if(lessthan(maxx,b))maxx=b;

	if(lessthan(c,minx))minx=c;
	if(lessthan(maxx,c))maxx=c;
	print(minx,maxx);
}

void solve()
{
	long long m=min(5LL,n);
	for(long long a=0;a<m;a++)
		for(long long b=a+1;b<m;b++)
			for(long long c=b+1;c<m;c++)
				if(xmult(a,b,c)==0)
				{
					print(a,b,c);
					return;
				}
	for(long long a=0;a<m;a++)
		for(long long b=0;b<m;b++)
		{
			if(b==a)continue;
			for(long long c=0;c<m;c++)
			{
				if(a==c||b==c)continue;
				for(long long d=0;d<m;d++)
				{
					if(a==d||b==d||c==d)continue;
					if(isIntersected(a,b,c,d))
					{
						print(a,b);
						return;
					}
				}
			}
		}
	puts("NO");
}

int main()
{
	long long t;
	kread(t);
	while(t--)
	{
		kread(n);
		for(long long i=0;i<n;i++)
			kread(x[i],y[i]);
		if(n<3)puts("NO");
		else if(n==3)
		{
			if(xmult(0,1,2)==0)print(0,1,2);
			else puts("NO");
		}
		else solve();
	}
	return 0;
}


