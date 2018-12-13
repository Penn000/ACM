//2017-03-15
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	long long n;
	while(cin>>n)
	{
		long long l = 2, r = 2, L = 2, R = 2, tmp = 1;
		bool fg = true;
		for(;r<=n;r++)
		{
			if(n%(tmp*r)==0){
				tmp *= r;
			}else{
				if(r-l > R-L){
					L = l;
					R = r;
				}
				for(;r<=n;r++){
					if(r*r>n){
						fg = false;
						break;
					}
					if(n%r==0){
						l = r;
						tmp = 1;
						break;
					}
				}
			}
			if(tmp>n)break;
			if(!fg)break;
		}
		if(R==L){cout<<1<<endl<<n<<endl;continue;}
		cout<<R-L<<endl;
		for(long long i = L; i < R; i++)
		  	if(i == R-1)cout<<i<<endl;
			else cout<<i<<"*";
	}

    return 0;
}
