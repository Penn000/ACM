//2016.8.12
#include<iostream>
#include<cstdio>
#include<set>

using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		set<int> seta;
		set<int> setb;
		int a, b;
		bool fg = true;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &a);
			seta.insert(a);
		}
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &b);
			setb.insert(b);
		}
		if(seta.size()!=setb.size())
		  fg = false;
		else{
			set<int>::iterator it;
			for(it = seta.begin(); it != seta.end(); it++)
			{
				if(setb.count(*it)==0)
				  fg = false;
			}
		}
		if(fg)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	return 0;
}
