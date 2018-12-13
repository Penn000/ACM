#include<cstdio>  
#include<cstring>  
#define N 100005  
int t,n;  
int a[N],next[N],mark[N],last[N];  
int que[N],top;  
int main(){  
    scanf("%d",&t);  
    while(t--){  
        memset(mark,0,sizeof(mark));  
        scanf("%d",&n);  
        int ans=n;  
        a[0]=0;  
        next[0]=1;  
        last[n+1]=n;  
        for(int i=1;i<=n;i++)  
        {  
            next[i]=i+1;  
            last[i]=i-1;  
            scanf("%d",&a[i]);  
            que[top++]=i;  
        }  
        int flag=1;  
        while(flag)  
        {  
            int s=0;  
            flag=0;  
            int now=0;  
            while(now<top)  
            {  
                int i=que[now],ff=0;  
                while(next[i]<=n)  
                {  
                    if(a[i]>a[next[i]])ff++,i=next[i],flag=1;  
                    else break;  
                }  
                if(ff)ans-=(ff+1);  
                if(ff)  
                {  
                    next[last[que[now]]]=next[i];  
                    last[next[i]]=last[que[now]];  
                    que[s++]=last[que[now]];  
                }  
                while(que[now]<=i&&now<top)now++;  
            }  
            top=s;  
        }  
        printf("%d\n",ans);  
        int now=0;  
        while(now<=n)  
        {  
            if(now!=0)printf("%d ",a[now]);  
            now=next[now];  
        }  
        printf("\n");  
    }  
    return 0;  
}  
