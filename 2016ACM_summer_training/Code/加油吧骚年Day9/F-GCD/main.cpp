//2016.8.9
#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;
const int N = 100005;
int dp[N][20];//d[i][j]表示从第i个数字开始向后2^j个数字这段区间内的gcd,具有递减性
map<int, ll> mp;

void init_rmq(int n)//初始化dp,求出每段区间的gcd
{
	for(int j = 1; j < (int)log2(n)+1; j++)
	  for(int i = 1; i <= n; i++)
	  {
		  if(i+(1<<j)-1 <= n)
			dp[i][j] = __gcd(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
	  }
}

int rmq(int l, int r)//查询
{
	int k = (int)log2(r-l+1);
	return __gcd(dp[l][k], dp[r-(1<<k)+1][k]);
}

int main()
{
	int n, q, l, r, T, kase = 0;
	cin>>T;
	while(T--)
	{
		printf("Case #%d:\n", ++kase);
		cin>>n;
		mp.clear();
		for(int i = 1; i <= n; i++)
		  scanf("%d", &dp[i][0]);
		init_rmq(n);

//利用二分求具有相同gcd区间的数目
//-----------------------------------------------------------------------------------
		for(int i = 1; i <= n; i++)
		{
			int a = i, b = n, mid, tmp, vs;
			while(1)
			{
				tmp = a; 
				vs = rmq(i, a);
				while(a <= b)
				{
					mid = (a+b)>>1;
					if(rmq(i, mid)<vs) b = mid-1;
					else a = mid+1;
				}
				mp[vs]+=1ll*(b-tmp+1);
				b = n;
				if(a>b)break;
			}
		}
//------------------------------------------------------------------------------------

		cin>>q;
		while(q--)
		{
			scanf("%d%d", &l, &r);
			int ans = rmq(l, r);
			cout<<ans<<" "<<mp[ans]<<endl;
		}
	}

	return 0;
}
