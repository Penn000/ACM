//2017-08-11
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000010;
const int inf = 0x3f3f3f3f;
char str[N];
int n, r[N], k;
int wa[N], wb[N], wv[N], wss[N];
int Suffix[N];//Str下标为i ~ Len的连续子串(即后缀) 
int SA[N];//满足Suffix[SA[1]] < Suffix[SA[2]] …… < Suffix[SA[Len]],即排名为i的后缀为Suffix[SA[i]](与Rank是互逆运算) 
int Rank[N];//Suffix[i]在所有后缀中的排名 
int Height[N];//height[i]表示Suffix[SA[i]]和Suffix[SA[i-1]]的最长公共前缀，也就是排名相邻的两个后缀的最长公共前缀
int H[N];//等于Height[Rank[i]]，也就是后缀Suffix[i]和它前一名的后缀的最长公共前缀 

//比较母串r中起始位置为a和b，长度都为len的子串是否相等
int cmp(int *r, int a, int b, int len)
{
    return r[a]==r[b] && r[a+len]==r[b+len];
}

//倍增算法求SA数组。
void da(int *r, int *SA, int n, int m)
{
    int i, j, p, *x = wa, *y = wb, *t;
    for(i = 0; i < m; i++)wss[i] = 0;
    for(i = 0; i < n; i++)wss[x[i]=r[i]]++;
    for(i = 0; i < m; i++)wss[i]+=wss[i-1];
    for(i = n-1; i >= 0; i--)SA[--wss[x[i]]]=i;
    for(j = 1, p = 1; p < n; j *= 2, m = p){
        for(p = 0, i = n-j; i < n; i++)
              y[p++] = i;
        for(i = 0; i < n; i++)
              if(SA[i] >= j)
                  y[p++] = SA[i]-j;
        for(i = 0; i < n; i++)
              wv[i] = x[y[i]];
        for(i = 0; i < m; i++)
              wss[i] = 0;
        for(i = 0; i < n; i++)
              wss[wv[i]]++;
        for(i = 1; i < m; i++)
              wss[i] += wss[i-1];
        for(i = n-1; i >= 0; i--)
              SA[--wss[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[SA[0]]=0, i = 1; i < n; i++)
              x[SA[i]] = cmp(y, SA[i-1], SA[i], j)?p-1:p++;
    }
}

//计算height数组
void cal_Height(int *r, int *SA, int n)
{
    int i, j, k = 0;
    for(i = 1; i <= n; i++)Rank[SA[i]] = i;
    for(i = 0; i < n; Height[Rank[i++]] = k)
          for(k?k--:0, j=SA[Rank[i]-1]; r[i+k]==r[j+k]; k++)
          ;
}

int st[N][30];

void init_rmq(int n)
{
    for(int i=1;i<=n;i++) st[i][0]=Height[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
}

//询问后缀i和后缀j的最长公共前缀
int lcp(int i,int j)
{
	i = Rank[i];
	j = Rank[j];
    if(i>j) swap(i,j);
    i++;
    int k=0;
    while(i+(1<<(k+1)) <= j) k++;
    return min(st[i][k],st[j-(1<<k)+1][k]);
}

bool check(int len){
	int cnt = 1;
	for(int i = 1; i <= n; i++){
		if(Height[i] >= len){//将Height进行分组，每组内Height值均大于k。
			cnt++;
		}else cnt = 1;//重新分组
		if(cnt >= k)return true;//一组内元素个数不小于k，说明存在
	}
    return false;
}

int main()
{
    while(scanf("%d%d", &n, &k)!=EOF)
    {
		for(int i = 0; i < n; i++)
		  	scanf("%d", &r[i]);
        da(r, SA, n+1, 1000010);
        cal_Height(r, SA, n);
        // for(int i = 0; i < n; i++){
        //     cout<<Rank[i]<<" "<<SA[i+1]<<" "<<Height[i+1]<<endl;
        // }
		init_rmq(n);
		// int l, r;
		// while(cin>>l>>r){
		// 	cout<<lcp(l, r)<<endl;
		// }
		//二分答案，进行判定
		int l = 1, r = n, mid, ans = 0;
        while(l <= r){
            mid = (l+r)/2;
            if(check(mid)){
                ans = mid;
                l = mid+1;
            }else r = mid-1;
        }
		printf("%d\n", ans);
    }

    return 0;
}
