//2016.8.2
//acm.hust.edu.cn/vjudge/contest/125415#problem/B
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct laptop
{
	int a, b;
}lap[100005];

bool cmp(laptop x, laptop y)
{
	if(x.a == y.a)return x.b < y.b;
	return x.a < y.a;
}

int main()
{
	int n;
	bool fg;
	while(scanf("%d", &n)!=EOF)
	{
		fg = false;
		for(int i = 0; i < n; i++)
		{
			scanf("%d %d", &lap[i].a, &lap[i].b);
		}
		sort(lap, lap+n, cmp);

	//	for(int i = 0; i < n; i++)
	//	  cout<<lap[i].a<<" "<<lap[i].b<<endl;
		for(int i = 1; i < n; i++)
			if(lap[i].b < lap[i-1].b)
			{
				fg = true;
				break;
			}
		if(fg)cout << "Happy Alex\n";
		else cout << "Poor Alex\n";
	}

	return 0;
}
