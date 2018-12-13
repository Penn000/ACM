//2017-03-19
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int se[55][1005], cnt[55];

double merge(int a, int b)
{
	int nt = 0, nc = 0;
	int cnt1 = 0, cnt2 = 0;
	while(cnt1 < cnt[a] && cnt2 < cnt[b])
	{
		if(se[a][cnt1] < se[b][cnt2]){
			nt++;
			cnt1++;
		}else if(se[a][cnt1] > se[b][cnt2]){
			nt++;
			cnt2++;
		}else{
			nt++;
			nc++;
			cnt1++;
			cnt2++;
		}
	}
	if(cnt1<cnt[a])nt += cnt[a]-cnt1;
	if(cnt2<cnt[b])nt += cnt[b]-cnt2;
	return nc*1.0/nt;
}

int main()
{
	int n, m, a;
	while(cin>>n)
	{
		memset(cnt, 0, sizeof(cnt));
		for(int i = 1; i <= n; i++)
		{
			cin>>m;
			set<int> S;
			set<int>::iterator it;
			for(int j = 0; j < m; j++)
			{
				cin>>a;
				it = S.find(a);
				if(it == S.end()){
					S.insert(a);
					se[i][cnt[i]] = a;
					cnt[i]++;
				}
			}
			sort(se[i], se[i]+cnt[i]);
		}
		cin>>m;
		int s1, s2;
		while(m--)
		{
			cin>>s1>>s2;
			double ans = merge(s1, s2)*100;
			printf("%.2lf%\n", ans);
		}
	}

    return 0;
}
