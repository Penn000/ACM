//2017-08-10
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;
const int inf = 0x3f3f3f3f;
char str[N*2], tmpstr[N];
int n, m, r[N];
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

int k;
int sk[N][2];
long long solve(){
    int top=0;
    long long ans=0,tot=0;
    for(int i=1;i<=n;i++) {
        if(Height[i]<k) 
            top=0,tot=0;
        else {
            int cnt=0;
            if(SA[i-1]<n) {
                cnt++; tot+=Height[i]-k+1;
            }
            while(top && Height[i]<=sk[top-1][0]) {
                top--;
                tot+=(Height[i]-sk[top][0])*sk[top][1];         
				cnt+=sk[top][1];
            }
            sk[top][0]=Height[i];
            sk[top++][1]=cnt;
            if(SA[i]>n) ans+=tot;
        }
    }
    top=tot=0;
    for(int i=1;i<=n;i++) {
        if(Height[i]<k) top=0,tot=0;
        else {
            int cnt=0;
            if(SA[i-1]>n) {
                cnt++; tot+=Height[i]-k+1;
            }
            while(top && Height[i]<=sk[top-1][0]) {
                top--;
                tot+=(Height[i]-sk[top][0])*sk[top][1];
                cnt+=sk[top][1];
            }
            sk[top][0]=Height[i];
            sk[top++][1]=cnt;
            if(SA[i]<n) ans+=tot;
        }
    }
    return ans;
}

int main()
{
    while(scanf("%d", &k)!=EOF && k)
    {
        scanf("%s%s", str, tmpstr);
        n = strlen(str);
        m = strlen(tmpstr);
        for(int i = n; i < n+m; i++){
            str[i] = tmpstr[i-n];
        }
        str[n+m] = '\0';
        n += m;
		for(int i = 0; i < n; i++)
		  	r[i] = str[i]-'a'+1;
        da(r, SA, n+1, 200);
        cal_Height(r, SA, n);
		init_rmq(n);
        long long ans = 0;
        // for(int i = 0; i < n-m; i++){
        //     for(int j = n-m; j < n; j++)
        //         ans += lcp(i, j)-k+1;
        // }
        printf("%lld\n", ans);
    }

    return 0;
}


