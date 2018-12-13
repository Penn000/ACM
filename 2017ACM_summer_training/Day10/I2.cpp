#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define MAXN 6666666

using namespace std;

int nextn[MAXN];

void initNext(const char *pattern)
{
	nextn[0]=-1;
	int i=0,j=-1;
	while(pattern[i])
	{
		while(j!=-1&&pattern[i]!=pattern[j])j=nextn[j];
		i++;
		j++;
		nextn[i]=j;
	}
}

int kmp(const char *s,const char *pattern,bool flag=true)
{
	if(flag)initNext(pattern);
	int i=0,j=0,cnt=0;
	while(s[i])
	{
		while(j!=-1&&s[i]!=pattern[j])j=nextn[j];
		i++;
		j++;
		if(!pattern[j])cnt++;
	} 
	return cnt;
}

int n;
char kkke[MAXN];

int work()
{
	n=0;
	while(kkke[n])n++;
	initNext(kkke);
	for(int i=1;(i=n/(n/i))<n;i++)
	{
		if(n%i)continue;
		cout<<i<<' '<<n<<endl;
		while(nextn[n]>n-i)nextn[n]=nextn[nextn[n]];
		if(nextn[n]==n-i)
			return n/i;
	}
	return 1;
}

int main()
{
	while(scanf("%s",kkke),strcmp(kkke,".")!=0)
	{
		printf("%d\n",work());
	}
	return 0;
}
