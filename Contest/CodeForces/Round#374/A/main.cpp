//2016.9.30
#include <iostream>
#include <cstdio>
#include <cstring>
#define N 105

using namespace std;

string str;
int ans[N];

int main()
{
	int n, cnt, tmp;
	while(scanf("%d", &n)!=EOF)
	{
		tmp = cnt = 0;
		cin>>str;
		int len = str.length();
		for(int i = 0; i < len; i++)
		{
			if(str[i]=='B')
			{
				tmp = 0;
				while(str[i]=='B'&&i<n)
				{
					i++;
					tmp++;
				}
				ans[cnt++] = tmp;
			}
		}
		cout<<cnt<<endl;
		for(int i = 0; i < cnt; i++)
		{
			if(i==0)cout<<ans[i];
			else cout<<" "<<ans[i];
		}
		if(!cnt)
		cout<<endl;
	}
    return 0;
}
