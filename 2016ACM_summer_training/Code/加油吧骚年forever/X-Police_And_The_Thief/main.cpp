#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	int T, xp, yp, xt, yt, n, m;
	string fir;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>xp>>yp>>xt>>yt;
		cin>>fir;
		if(n==1||m==1)cout<<"YES"<<endl;
		else if(xp==xt&&yp==yt)cout<<"YES"<<endl;
		else
		{
			int dis = abs(xt-xp)+abs(yt-yp);
			if(dis%2==0)
			{
				if(fir[0] == 't')cout<<"YES"<<endl;
				else cout<<"NO"<<endl;
			}else
			{
				if(fir[0] == 't')cout<<"NO"<<endl;
				else cout<<"YES"<<endl;
			}
		}
	}

	return 0;
}
