//2016.8.10
#include<iostream>
#include<cstdio>
#include<cmath>
//#include<algorithm>
#include<cstring>

using namespace std;

char s[1005];
int arr[1005], ans[1005];
int dp[1005][20];

int min1(int a, int b)
{
	return s[a]<=s[b]?a:b;
}

void rmq_init(int n)
{
	for(int i = 0; i < n; i++)
	  dp[i][0] = i;
	for(int j = 1; (1<<j) < n; j++)
	  for(int i = 0; i+(1<<j)-1 < n; i++)
		dp[i][j] = min1(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
}

int rmq(int l, int r)
{
	int k = (int)log2(r-l+1);
	return min1(dp[l][k], dp[r-(1<<k)+1][k]);
}

int main()
{
	int m, n;
	while(scanf("%s%d", s, &m)!=EOF)
	{
		n = strlen(s);
		for(int i = 0; i <  n; i++)
			arr[i] = s[i]-'0';
		rmq_init(n);
		int len = n-m, pos = 0, cnt = 0;
		while(len--)
		{
			pos = rmq(pos, n-len-1);
			ans[cnt++] = arr[pos++];
		}
		int i;
		for(i = 0; i < cnt; i++)
		  if(ans[i]!=0)break;
		if(i==cnt)cout<<0;
		for(; i < cnt; i++)cout<<ans[i];
		cout<<endl;
	}

	return 0; 
}
/*
int main()  
{  
    int len, m, i;  
    while(scanf("%s%d",s, &m)!=EOF)  
    {  
	        len = strlen(s);  
	        rmq_init(len);  
	        m = len - m;  
	        int pos = 0, num = 0;  
	        while(m--)  
	        {  
			            pos = rmq(pos, len - m - 1);  
			            ans[num++] = s[pos++];  
			        }  
	        for(i = 0; i < num; i++)  
	            if(ans[i]!='0')  
	                break;  
	        if(i == num)  
	            printf("0");  
	        else  
	        {  
			            while(i < num)  
			                printf("%c",ans[i++]);  
			        }  
	        puts("");  
	    }  
    return 0;  
}*/  
