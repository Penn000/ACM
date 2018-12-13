#pragma comment(linker, "/STACK:102400000,102400000")  
#include <stdio.h>  
#include <string.h>  
#include <iostream>  
#include <algorithm>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <string>  
#include <math.h>  
#include <stdlib.h>  
#include <time.h>  
using namespace std;  
const __int64 inf=10000000000000LL;  
const int maxn=100010;  
int head[maxn],tol,dep[maxn],n;  
struct node   
{  
	int from,to,next;  
	__int64 cap;  
}edge[1000000];  
void add(int u,int v,__int64 cap)  
{  
	edge[tol]=(node){  
		u,v,head[u],cap  
	};  
	head[u]=tol++;  
	edge[tol]=(node){  
		v,u,head[v],0  
	};  
	head[v]=tol++;  
}  
int bfs(int s,int t)  
{  
	int que[maxn],front=0,rear=0;  
	memset(dep,-1,sizeof(dep));  
	dep[s]=0;que[rear++]=s;  
	while(front!=rear)  
	{  
		int u=que[front++];front%=maxn;  
		for(int i=head[u];i!=-1;i=edge[i].next)  
		{  
			int v=edge[i].to;  
			if(edge[i].cap>0&&dep[v]==-1)  
			{  
				dep[v]=dep[u]+1;  
				que[rear++]=v;  
				rear%=maxn;  
				if(v==t)return 1;  
			}  
		}  
	}  
	return 0;  
}  

__int64 dinic(int s,int t)  
{  
	__int64 res=0;  
	while(bfs(s,t))  
	{  
		int Stack[maxn],top,cur[maxn];  
		memcpy(cur,head,sizeof(head));  
		top=0;  
		int u=s;  
		while(1)  
		{  
			if(t==u)  
			{  
				__int64 min=inf;  
				int loc;  
				for(int i=0;i<top;i++)  
				  if(min>edge[Stack[i]].cap)  
				  {  
					  min=edge[Stack[i]].cap;  
					  loc=i;  
				  }  
				for(int i=0;i<top;i++)  
				{  
					edge[Stack[i]].cap-=min;  
					edge[Stack[i]^1].cap+=min;  
				}  
				res+=min;  
				top=loc;  
				u=edge[Stack[top]].from;  
			}  
			for(int i=cur[u];i!=-1;cur[u]=i=edge[i].next)  
			  if(dep[edge[i].to]==dep[u]+1&&edge[i].cap>0)break;  
			if(cur[u]!=-1)  
			{  
				Stack[top++]=cur[u];  
				u=edge[cur[u]].to;  
			}  
			else   
			{  
				if(top==0)break;  
				dep[u]=-1;  
				u=edge[Stack[--top]].from;  
			}  
		}  
	}  
	return res;  
}  
int main()  
{  
	int i,j,m,T,t,p;  
	__int64 k;  
	scanf("%d",&T);  
	for(t=1;t<=T;t++)  
	{  
		int source, target;
		scanf("%d%d",&n,&m);  
		scanf("%d%d", &source, &target);
		memset(head,-1,sizeof(head));tol=0;  
		while(m--)  
		{  
			scanf("%d%d%I64d",&i,&j,&k);  
			add(i,j,k*200001+1);  
		}  
		__int64 ans=dinic(source, target);  
		cout<<ans%200001<<endl;  
	}  
	return 0;  
}  
