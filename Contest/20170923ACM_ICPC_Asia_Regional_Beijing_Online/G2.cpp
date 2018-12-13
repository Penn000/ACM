#include <stdio.h>
#define ll long long
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main(){
	ll a,b,n,m,tmp;
	while(~scanf("%lld%lld",&n,&m)){
		if(n>m){
			ll t=n;
			n=m;
			m=t;
		}
		a=n-1,b=m-1;
		if(b%a==0){
			printf("%lld\n",m);
			continue ;
		}
		tmp=gcd(a,b);
		if(tmp==1)
		  printf("%lld\n",n+m-2);
		else
		  printf("%lld\n",(a/tmp)*(b/tmp)*(tmp-1)+(a/tmp)+(b/tmp));
	}
	return 0;

}

