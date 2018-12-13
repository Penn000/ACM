//2016.8.17
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N = 400005;
char s[N];
int tot, ans[N], nex[N];

void getNext(int n)
{
	nex[0] = -1;
	for(int i = 0, fail = -1; i < n;)
	{
		if(fail==-1||s[i]==s[fail])
		{
			i++, fail++;
			nex[i] = fail;
		}else fail = nex[fail];
	}
}

int main()
{
	while(scanf("%s", s)!=EOF)
	{
		int n = strlen(s);
		getNext(n);
		cout<<" ";
		for(int i = 1; i <= n; i++)
		  	cout<<nex[i];
		cout<<endl;
		tot = 0;
		int p = nex[n-1];
		while(p!=-1)
		{
			if(s[p] == s[n-1])
			  ans[tot++] = p+1;
			p = nex[p];
		}
		for(int i = tot-1; i >= 0; i--)
		  	printf("%d ", ans[i]);
		printf("%d\n", n);
	}

	return 0;
}
