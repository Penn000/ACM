#include <iostream>
#include <cstdio>
#include <queue>
#define N 100005
#define ll long long

using namespace std;
priority_queue<ll, vector<ll>, greater<ll> > pq, pqa;
int a, n;
int tot, sum;

bool mer(int k)
{
	ll tmp, cost = 0;
	while(pq.size()!=1)
	{
		tmp = 0;
		for(int i = 0; i < k && !pq.empty(); i++)
		{
			tmp += pq.top();
			pq.pop();
		}
		cost += tmp;
		if(cost>tot || cost-tmp+sum>tot)return false;
		pq.push(tmp);
	}
	return true;
}

int main()
{
	int T, l, r;
	scanf("%d", &T);
	while(T--)
	{
		while(!pqa.empty())pqa.pop();
		sum = 0;
		scanf("%d%d", &n, &tot);
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &a);
			pqa.push(a);
			sum += a;
		}
		int k;
		pq = pqa;
		if(!mer(n/2+1))k = n;
		else
		{
			l = 2, r = n;
			while(l < r)
			{
				int mid = (r+l)>>1;
				pq = pqa;
				if(mer(mid))r = mid;
				else l = mid+1;
			}
//			for(int i = 2; i <= n/2+1; i++)
//			{   
//				pq = pqa;
//				if(mer(i))
//				{
//					k = i;break;
//				}
//			}
		}
		printf("%d\n", r);
	}

    return 0;
}
