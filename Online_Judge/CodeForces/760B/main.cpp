//2017.01.31
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int n, m, k;
	while(cin>>n>>m>>k)
	{
		m -= n;
		long long lp = k-1, rp = n-k;
		long long l = 0, r = m, mid, ans;
		while(l<=r)
		{
			mid = (l+r)>>1;
			long long tmp = mid;
			if(mid>=lp)tmp += (mid*2-lp-1)*lp/2;
			else tmp += (mid-1)*mid/2;
			if(tmp > m){r = mid-1;continue;}
			if(mid>=rp)tmp += (mid*2-rp-1)*rp/2;
			else tmp += (mid-1)*mid/2;
			if(tmp < m){
				ans = mid+1;
				l = mid+1;
			}
			else if(tmp > m)r = mid-1;
			else{
				ans = mid+1;
				break;
			}
		}
		cout<<ans<<endl;
	}

    return 0;
}
