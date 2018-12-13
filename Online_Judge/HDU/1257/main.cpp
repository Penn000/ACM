#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int h1 = 0, h2 = 0, cnt = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &h2);
			if(h2 > h1)cnt++;
			h1 = h2;
		}
		cout << cnt << endl;
	}

	return 0;
}
