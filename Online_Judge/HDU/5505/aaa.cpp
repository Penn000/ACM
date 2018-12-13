#include<iostream>
#include<cstdio>
#define ll unsigned long long
using namespace std;

ll gcd(ll a, ll b)
{
	    return b==0?a:gcd(b, a%b);

}

int main()
{
	    int T, cnt;
		    bool fg;
			    ll n, m;
				    cin>>T;
					    while(T--)
						{
							        scanf("%I64d%I64d", &n, &m);
									if(n==m){
										            puts("0");
													            continue;
																        
									}
									        if(n==0||m<n||m%n!=0)
											{
												            puts("-1");
															            continue;
																		        
											}
											        fg = true; cnt = 0;
													        m /= n;
															        while(m != 1)
																	{
																		            ll tmp = gcd(n, m);
																					if(tmp == 1){
																						                fg = false;
																										                break;
																														            
																					}
																					            m /= tmp;
																								            cnt++;
																											        
																	}
																	        if(fg)
																			              printf("%d\n", cnt);
																			        else 
																					                printf("-1\n");
																					    
						}

						    return 0;

}
