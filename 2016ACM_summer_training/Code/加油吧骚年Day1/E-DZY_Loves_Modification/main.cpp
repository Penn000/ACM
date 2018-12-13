//2016.8.19
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll __int64   
#define inf 999999999

using namespace std;

ll rsum[1005], csum[1005], rres[1000005], cres[1000005];
priority_queue<ll> pq1;
priority_queue<ll> pq2;

int main()
{
	ll n, m, k, p;//被数据恶心到了，这行类型改成ll才过, int居然一直ＷＡ在第四个测试点
	ll tmp, val;
	while(cin>>n>>m>>k>>p)
	{
		memset(rsum, 0, sizeof(rsum));
		memset(csum, 0, sizeof(csum));
		memset(rres, 0, sizeof(rres));
		memset(cres, 0, sizeof(cres));
		for(int i =0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				scanf("%I64d", &val);
				rsum[i] += val;//rsum[i]表示第i行之和
				csum[j] += val;//csum[i]表示第i列之和
			}
		}
		while(!pq1.empty())pq1.pop();
		for(int i = 0; i < n; i++)
		{
			pq1.push(rsum[i]);
		}
  		for(int i = 1; i <= k; i++)
		{
			tmp = pq1.top();
			pq1.pop();
			rres[i] = rres[i-1]+tmp;//rres[i]表示选了i行的值
			tmp-=p*m;
			pq1.push(tmp);
		}
		while(!pq2.empty())pq2.pop();
		for(int i = 0; i < m; i++)
		{
			pq2.push(csum[i]);
		}
		for(int i = 1; i <= k; i++)
		{
			tmp = pq2.top();
			pq2.pop();
			cres[i] = cres[i-1]+tmp;//cres[i]表示选了i列的值
			tmp-=p*n;
			pq2.push(tmp);
		}
		ll happy = inf;
		happy = -happy*happy;
		for(int i = 0; i <= k; i++)
		  	happy = max(happy, rres[i]+cres[k-i]-p*i*(k-i));
		cout<<happy<<endl;	
	}

	return 0;
}
