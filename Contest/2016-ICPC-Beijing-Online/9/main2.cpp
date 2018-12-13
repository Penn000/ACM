#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 10005
#define ll long long 

using namespace std;

const int inf = 0x3f3f3f3f;

struct node
{
	ll t, d, c;
	bool operator<(const node& x)const
	{
		return t < x.t;
	}
}arr[2*N];
int Ta, Tb, x, cnt;

bool check(int t, int tc, int TA, int TB)
{
	int a = (TA-t)/tc;
	int b = (TB-t)/tc;
	if(a > b)return true;
	else if(a < b) return false;
	else if(b&1)return false;
	else return true;
}

int main()
{
	int n, m, t, tc, d, tr;
	ll ans, sum;
	while(scanf("%d%d", &Ta, &Tb)!=EOF)
	{
		sum = cnt = 0;
		ans = inf;
		scanf("%d", &x);
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d%d", &t, &tc, &d);
			tr = t+tc;
			if(tr>=x && tr<=x+Tb)
			{
				arr[cnt].t = tr+tc;
				arr[cnt].d = d;
				arr[cnt].c = tc;
				sum += d;
				cnt++;
			}
		}
		for(int i = 0; i < m; i++)
		{
		  	scanf("%d%d%d", &t, &tc, &d);
			arr[cnt].t = t+tc;
			arr[cnt].d = d;
			arr[cnt].c = tc;
			sum += d;
			cnt++;
		}
		sort(arr, arr+cnt);
		for(int i = 0; i < cnt; i++)
		{
			int Time = arr[i].t+Ta;
			ll da = 0;
			if(i >0 && arr[i].t==arr[i-1].t)continue;
			for(int j = i; arr[j].t<=Time && j<cnt; j++)
			{
				if(check(arr[j].t, arr[j].c, Time, x+Tb))da += arr[j].d;
			}
			ll temp = sum-da;
			if(temp < ans)ans = temp;
			if(Time >= arr[cnt-1].t)break;
		}
		printf("%lld\n", ans);
	}

    return 0;
}

