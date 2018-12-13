#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

char s[1000010];
char s1[1000010];
int kkke[3];
int x,ans;

int main()
{
	scanf("%s",s);
	int len=strlen(s);
	int n=len;
	while(n&&s[n-1]%2)
	{
		ans++;
		n--;
	}
	for(int i=0;i<n;i++)x=(x+s[i])%3;
	if(x)
	{
		int ans1=0;
		strcpy(s1,s);
		bool flag=false;
		for(int i=n-1;i>=0;i--)
		{
			if(s1[i]%3==x)
			{
				flag=true;
				ans1++;
				s1[i]='0';
				break;
			}
		}
		if(flag)
		{
			for(int i=0;i<n;i++)
			{
				if(s1[i]=='0')ans1++;
				else break;
			}
		}
		else ans1=n;

		x=3-x;
		int ans2=0;
		flag=false;
		for(int i=n-1;i>=0;i--)
		{
			if(s[i]%3==x)
			{
				flag=true;
				ans2++;
				s[i]='0';
				break;
			}
		}
		if(flag)
		{
			flag=false;
			for(int i=n-1;i>=0;i--)
			{
				if(s[i]%3==x)
				{
					flag=true;
					ans2++;
					s[i]='0';
					break;
				}
			}
		}
		if(flag)
		{
			for(int i=0;i<n;i++)
			{
				if(s[i]=='0')ans2++;
				else break;
			}
		}
		else ans2=n;
		ans+=min(ans1,ans2);
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0')ans++;
			else break;
		}
	}
	if(ans==len)printf("-1s\n");
	else printf("%d\n",len-ans);
	return 0;
}
