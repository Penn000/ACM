#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;
int dp[N][20],mm[N],n,t,q;
map<int,LL>mp;
void initrmq()
{
	    mm[0]=-1;
		    for(int i=1; i<=n; i++)
			          mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
			    for(int j=1; j<=mm[n]; j++)
				          for(int i=1; i+(1<<j)-1<=n; i++)
							            dp[i][j]=__gcd(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);

}
int rmq(int x,int y)
{
	    int k=mm[y-x+1];
		    return __gcd(dp[x][k],dp[y-(1<<k)+1][k]);

}
int main()
{
	    //freopen("in.txt","r",stdin);
		    scanf("%d",&t);
		        for(int cas=1; cas<=t; cas++)
		            {
		                    scanf("%d",&n);
		                            for(int i=1; i<=n; i++)
		                                        scanf("%d",&dp[i][0]);
		                                                initrmq();
		                                                        mp.clear();
		                                                                for(int i=1; i<=n; i++)
		                                                                        {
	            int l=i,r=n,mid,vs,tmp;
				            while(1)
							{
								                tmp=l;
												                vs=rmq(i,l);
																                while(l<=r)
																				{
																					                    mid=(l+r)>>1;
																										                    if(rmq(i,mid)<vs) r=mid-1;
																															                    else l=mid+1;
																																				                
																				}
																				                mp[vs]+=1ll*(r-tmp+1);
																								                r=n;
																												                if(l>r) break;
																																            
							}
							        }
        int l,r;
		        printf("Case #%d:\n",cas);
				        scanf("%d",&q);
						        while(q--)
								{
									            scanf("%d%d",&l,&r);
												            int vs=rmq(l,r);
															            printf("%d %lld\n",vs,mp[vs]);
																		        
								}
								    }
    system("pause");
	    return 0;
}

