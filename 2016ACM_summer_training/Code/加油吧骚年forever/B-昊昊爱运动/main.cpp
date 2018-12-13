#include<iostream>
#include<cstdio>
#include<csstring>
#include<set>

using namespace std;

const int N = 2005, len = 50;
int dp[N][N], a[N], block[N];
set<int> st[50];

int main()
{
	int n, m, q, l, r, ans;
	while(scanf("%d%d", &n, &m)!=EOF)
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		int tot = (n-1)/len;
		fot(int i = 0; i <= tot; i++)
		{
			st[i].clear();
			for(int j = i*len+1; j <= (i+1)*len && j <= n; j++)
			{
				st[i].insert(a[j]);
			}
			block[i] = st[i].size();
		}
		scanf("%d", &q);
		while(q--)
		{
			scanf("%d%d", &l, &r);
			int id1 = l/len;
			int id2 = r/len;
			if(id1==id2)
			{
				set<int> s;
				for(int i = l; i <= r; i++)
				{
					s.insert(a[i]);
				}
				printf("%d\n", st.size());
			}else
			{
				ans = 0;
				for(int i = id1+1; i <= id2-1; i++)
					ans+=block[i];
				for(int i)
			}
		}

	}

	return 0;
}
