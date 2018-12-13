#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <unordered_map>
#include <math.h>

template<class TN>
inline bool kread(TN &x)
{
	x=0;
	char c;
	bool flag=false;
	while(!isdigit(c=getchar()))
	{
		if(c=='-')
			flag=true;
		if(c==EOF)return false;
	}
	do{
		x=x*10+c-48;
	}while(isdigit(c=getchar()));
	if(flag)x=-x;
	return c!='\n';
}

template<class TN,class... ARGS>
inline void kread(TN &first,ARGS& ... args)
{
	kread(first);
	kread(args...);
}

using namespace std;

const int MAXN=1<<20;
int n,m,mm;
double alpha;
long long kkke[66];
long long zt[MAXN];
bool ff[MAXN];
unordered_map<int,int>mp;

template<class TN>
inline TN lowbit(const TN &x)
{
	return x&-x;
}

int main()
{
	scanf("%d%lf",&n,&alpha);
	long long x,y;
	for(m=0;kread(x);m++)
	{
		do{
			kkke[x]|=1LL<<m;
		}while(kread(x));
		kkke[x]|=1LL<<m;
	}
	mm=1<<n;
	m=ceil(m*alpha);
	if(m==0)
	{
		cout<<mm-1<<endl;
		return 0;
	}
	int ans=0,cnt;
	for(int i=1,j=1;j<=n;i<<=1,j++)mp.emplace(i,j);
	for(int i=1;i<mm;i++)
	{
		y=lowbit(i);
		x=i^y;
		if(x)
		{
			if(ff[x])ff[i]=true;
			else
			{
				zt[i]=zt[x]&kkke[mp[y]];
				if(zt[i]==zt[x])ans++;
				else
				{
					cnt=0;
					for(long long j=zt[i];cnt<m&&j;j^=lowbit(j))cnt++;
					if(cnt<m)ff[i]=true;
					else
					{
						ans++;
					}
				}
			}
		}
		else
		{
			zt[i]=kkke[mp[i]];
			cnt=0;
			for(long long j=zt[i];cnt<m&&j;j^=lowbit(j))cnt++;
			if(cnt<m)ff[i]=true;
			else
			{
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
