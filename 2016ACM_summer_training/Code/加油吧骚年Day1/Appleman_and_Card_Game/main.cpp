//2016.8.2
//http://acm.hust.edu.cn/vjudge/contest/125415#problem/D
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int ch[30];

bool cmp(int a, int b)
{
	return a>b;
}

int min(int a, int b)
{
	return a > b ? b : a;
}

int main()
{
	int n, k;
	long long ans, x;
	char c;
	while(cin >> n >> k)
	{
		memset(ch, 0, sizeof(ch));
		getchar();
		ans = 0;
		for(int i = 0; i < n; i++)
		{
			c = getchar();
			ch[c-'A']++;
		}
		sort(ch, ch+26, cmp);

		for(int i = 0; k > 0;i++)
		{
			x = min(k, ch[i]);
			ans += x*x;
			k -= x;
		}
		cout << ans << endl;
	}
	return 0;
}
