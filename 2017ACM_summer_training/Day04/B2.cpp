#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
#define mod 10000000007
using namespace std;
char a[1000006];
ll x,z;
ll quickpow(ll x,ll y,ll z)
{
    ll ans=1;
    while(y)
    {
        if(y&1)
            ans=ans*x%z;
        x=x*x%z;
        y>>=1;
    }
    return ans;
}
ll phi(ll n)
{
    ll i,rea=n;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            rea=rea-rea/i;
            while(n%i==0)
                n/=i;
         }
    }
    if(n>1)
        rea=rea-rea/n;
    return rea;
}
int main()
{
    while(scanf("%lld %s %lld",&x,a,&z)!=EOF)
    {
        ll len=strlen(a);
        ll p=phi(z);
        ll ans=0;
        for(ll i=0;i<len;i++)
            ans=(ans*10+a[i]-'0')%p;
        ans+=p;
        printf("%lld\n",quickpow(x,ans,z));
    }
    return 0;
}
