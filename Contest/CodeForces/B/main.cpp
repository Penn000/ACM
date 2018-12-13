//2016.10.1
#include <iostream>
#include <cstdio>
#include <cstring>
#define N 105

using namespace std;

int p[N];

int main()
{
	int n;
	string str;
	while(scanf("%d", &n)!=EOF)
	{
		bool fg = true;
		for(int i = 0; i < n; i++)
		  	scanf("%d", &p[i]);
		getchar();
		for(int j = 0; j < n; j++)
		{
			getline(cin, str);
			if(!fg)continue;
			int cnt = 0;
			for(int i = 0; i < str.length(); i++)
			  	if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u' || str[i]=='y')cnt++;
			if(cnt<p[j])fg = false;
		}
		if(fg)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

    return 0;
}
