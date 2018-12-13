#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int f[100005], g[1000005], h[1000005];
set<int> SET;
int main()
{
	int n, m;
	while(cin>>n)
	{
		SET.clear();
		for(int i = 1; i <= n; i++)
		{
			cin>>f[i];
			SET.insert(f[i]);
		}
		m = SET.size();
		cout<<m<<endl;

	}

    return 0;
}
