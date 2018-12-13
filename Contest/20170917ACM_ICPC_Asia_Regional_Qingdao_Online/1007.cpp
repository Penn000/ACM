#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
#define M 510  
using namespace std;  
int n;  
pair<int,int>a[M];  
int f[M][M];  
int main()  
{  
	int i,j,k,x;  
	cin>>n;  
	a[0].first=19980402;  
	for(i=1,j=0;i<=n;i++)  
	{  
		scanf("%d",&x);  
		if(x!=a[j].first)  
		  a[++j].first=x;  
		a[j].second++;  
	}  
	n=j;  
	memset(f,0x3f,sizeof f);  
	for(i=1;i<=n;i++)  
	  f[i][1]=a[i].second==1?2:1;  
	for(j=2;j<=n;j++)  
	  for(i=1;i+j-1<=n;i++)  
	  {  
		  if(a[i].first==a[i+j-1].first)  
		  {  
			  if(a[i].second+a[i+j-1].second==2)  
			  {  
				  f[i][j]=f[i+1][j-2]+1;  
				  for(k=2;k<j;k++)  
					if(a[i+k-1].first==a[i].first&&a[i+k-1].second==1)  
					  f[i][j]=min(f[i][j],f[i+1][k-2]+f[i+k][j-k-1]);  

			  }  
			  else  
				f[i][j]=f[i+1][j-2];  
		  }  
		  for(k=1;k<j;k++)  
			f[i][j]=min(f[i][j],f[i][k]+f[i+k][j-k]);  
	  }  
	cout<<f[1][n]<<endl;  
}  
