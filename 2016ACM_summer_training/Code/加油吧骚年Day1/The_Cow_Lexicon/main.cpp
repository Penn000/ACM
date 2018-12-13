#include <iostream>
#include <set>
#include <cstdio>

using namespace std;

int min(int a, int b)
{
	return a > b ? b : a;
}

int main()
{
	int w, l, dp[305], len[305];
	char a[305];

	while(cin>>w>>l)
	{
		set<string> s;
		scanf("%s", a+1);
		string tmp;
		for(int i = 0; i < w; i++)
		{
			cin >> tmp;
			s.insert(tmp);
		}
		dp[l] = 0;
		for(int i = l-1; i >= 0; i--)
		{
			f[i] = f[i+1] + 1;
			
		}
	}
	return 0;
}
