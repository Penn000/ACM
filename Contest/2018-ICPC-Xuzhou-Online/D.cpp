#include <cstdio>
#include <map>
#include <iostream>
#define N 20000000
using namespace std;
long long a,b,n;
int mu[N+10],pri[1300010],top;
bool mark[N+10];
map<long long,long long>V;
void shake()
{
    mu[1]=1;
    for(int i=2;i<=N;i++)
    {
        if(!mark[i])
        {
            pri[++top]=i;
            mu[i]=-1;
        }
        for(int j=1;j<=top && i*pri[j]<=N;j++)
        {
            mark[i*pri[j]]=true;
            if(i%pri[j]==0) break;
            mu[i*pri[j]]=-mu[i];
        }
    }
    for(int i=2;i<=N;i++) mu[i]+=mu[i-1];
}
long long calc(long long x)
{
    if(x<=N) return mu[x];
    if(V[x]) return V[x];
    long long ans=1;
    for(long long i=2,r;i<=x;i=r+1)
    {
        r=x/(x/i);
        ans-=calc(x/i)*(r-i+1);
    }
    V[x]=ans;
    return ans;
}
int main()
{
    shake();
	long long m, n;
    cin>>m>>n;
    cout<<calc(m)<<endl;
    return 0;
}
