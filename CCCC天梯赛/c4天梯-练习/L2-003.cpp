//2017-03-18
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1005;
struct node{
	double a, b;
	double c;
	bool operator < (const node& x){
		return c > x.c;
	}
}moom[N];

int main()
{
	int n, need;
	while(cin>>n>>need)
	{
		for(int i = 0; i < n; i++)
			cin>>moom[i].a;
		for(int i = 0; i < n; i++)
		  	cin>>moom[i].b;
		for(int i = 0; i < n; i++)
			moom[i].c = moom[i].b*1.0/moom[i].a;
		sort(moom, moom+n);
		double ans = 0;
		for(int i = 0; i < n; i++)
		{
			if(need < moom[i].a){
				ans += moom[i].c*need;
				break;
			}else{
				ans += moom[i].b;
				need -= moom[i].a;
			}
		}
		printf("%.2lf\n", ans);
	}

    return 0;
}
