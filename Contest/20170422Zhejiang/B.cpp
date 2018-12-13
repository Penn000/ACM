#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int sc[110];

int main()
{
	int T, n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		int cnt1 = 0, mx = 0;
		bool fg = true;
		for(int i = 0; i < n; i++)
		{
			cin>>sc[i];
			if(sc[i] == 1)cnt1++;
			if(sc[i] < 1)fg = false;
			if(mx < sc[i])mx = sc[i];
		}
		if(n < 10 || n > 13)fg = false;
		sort(sc, sc+n);
		sc[n] = sc[n-1];
		if(cnt1 < 2)fg = false;
		if(fg){
			for(int i = 0; i < n; i++)
			{
				if(sc[i+1]-sc[i] > 2){
					if(sc[i+1] == mx || sc[i] == mx)continue;
					else{
						fg = false;
						break;
					}
				}
			}
		}
		if(fg)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
