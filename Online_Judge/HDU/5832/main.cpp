//2016.8.16
#include<cstdio>
#include<cstring>

using namespace std;

char s[10000005];

int main()
{
	long long n, m, pos;
	int kase = 0, len;
	while(scanf("%s", s)!=EOF)
	{
		pos = n = m = 0;
		len = strlen(s);
		while(pos < len)
		{
			for(int i = 0; i < 15 && pos<len; i++, pos++)
			{
				n = n*10+(s[pos]-'0');
				m = m*10+(s[pos]-'0');
			}
			n %= 73;
			m %= 137;
		}
		if(!n&&!m)printf("Case #%d: YES\n", ++kase);
		else printf("Case #%d: NO\n", ++kase);
	}

	return 0;
}
