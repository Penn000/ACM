#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 666666//大于字符串长度二倍

using namespace std;

int krank[MAXN];//第i个元素是第几大 1~n
int SA[MAXN];//第i大的元素在原数组中位置 1~n
int height[MAXN];//height[i]表示Suffix[SA[i]]和Suffix[SA[i-1]]的最长公共前缀，也就是排名相邻的两个后缀的最长公共前缀
int *const tmp=height;//一开始height没用,使用它当tmp
int cnt[MAXN];//用于基数排序,统计
int st[MAXN][30];//st表
int LOG[MAXN];//log表

void initHeight(char *s,int n)//计算height数组
{
	int j,k=0;
	for(int i=1;i<=n;height[krank[i++]]=k)
	  for(k=max(k-1,0),j=SA[krank[i]-1];krank[i]>1&&s[i+k-1]==s[j+k-1];k++)
		;
}

void initLOG()
{
	if(LOG[0]==-1)return;
	LOG[0]=-1;
	for(int i=1;i<MAXN;i++)
	  LOG[i]=(i&(i-1))?LOG[i-1]:LOG[i-1]+1;
}

void initSt(int n)
{
	initLOG();
	for(int i=0;i<n;i++)st[i][0]=height[i+1];
	for(int j=1;(1<<j)<=n;j++)
	  for(int i=0;i+(1<<j)<=n;i++)
		st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}

bool comp(int n,int a,int b,int w)
{
	//判断a和b,a+w和b+w的第一关键字是否对应相等
	if(tmp[a]==tmp[b])
	{
		if(a+w>n||b+w>n)
		{
			if(a+w>n&&b+w>n)return true;
			return false;
		}
		if(tmp[a+w]==tmp[b+w])return true;
	}
	return false;
}

bool rSort(int n,int &m,int w)
{
	//krank当作第一关键字，tmp相当于第二关键字的SA
	//此时第二关键字已有序,顺序是tmp
	memset(cnt+1,0,m*sizeof(cnt[0]));
	for(int i=1;i<=n;i++)cnt[krank[i]]++;//统计
	for(int i=2;i<=m;i++)cnt[i]+=cnt[i-1];
	for(int i=n;i;i--)//比其第一关键字小的数量就是其新位置
	  SA[cnt[krank[tmp[i]]]--]=tmp[i];

	//用tmp的空间暂存rank
	memcpy(tmp+1,krank+1,n*sizeof(krank[0]));
	krank[SA[1]]=m=1;
	for(int i=2;i<=n;i++)//生成新的rank
	  krank[SA[i]]=comp(n,SA[i],SA[i-1],w)?m:++m;
	return m>=n;//分为n类,排序完成
}

void initSA(char *s,int n)//初始化后缀数组
{
	int m=0;
	for(int i=1;i<=n;i++)
	{
		krank[i]=s[i-1];
		m=max(m,krank[i]);
		tmp[i]=i;
	}
	int w=0;
	while(!rSort(n,m,w))
	{
		if(w)w<<=1;
		else w=1;
		//重新计算tmp
		int top=0;
		for(int i=n-w+1;i<=n;i++)tmp[++top]=i;//越界的最小
		for(int i=1;i<=n;i++)
		  if(SA[i]>w)//不越界的从小到大排
			tmp[++top]=SA[i]-w;
	}
	initHeight(s,n);
	initSt(n);
}

int calcLCP(int l,int r)//后缀l到后缀r的最长公共前缀
{
	l=krank[l];r=krank[r];
	if(l>r)swap(l,r);
	int k=LOG[r-l];
	return min(st[l][k],st[r-(1<<k)][k]);
}

int T, k;
char str[MAXN];
int times[MAXN];
int sta[MAXN], top;
int minh[MAXN];

int main(){ 
	scanf("%d", &T);
	while(T--){
		scanf("%d%s", &k, str);
		int len = strlen(str);
		initSA(str, len);
		top = 0;
		for(int i=1; i<=len; i++){
			int h = height[i];
			while(top != 0 && h < height[sta[top-1]]){
				top--;
				times[sta[top]] += i - sta[top];
				minh[sta[top]] = max(minh[sta[top]], h);
			}
			times[i] = i;
			minh[i] = 0;
			if(top != 0){ 
				times[i] -= sta[top-1];
				minh[i] += height[sta[top-1]];
			}
			sta[top++] = i;
		}

		while(top != 0){
			top--;
			times[sta[top]] += len + 1 - sta[top];
		}
		long long ans = 0;
		if (k!= 1)
		  for(int i=1; i<=len; i++){
			  if(times[i] == k){
				  ans += height[i] - minh[i];
			  }
		  }
		else{
			ans = len * (len+1) / 2;
			for(int i=1; i<=len; i++){
				if(times[i] > 1 && times[i] <= len){
					ans -= 1LL * (height[i] - minh[i])*times[i];
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
