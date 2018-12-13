//2016.8.30
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int a[4], vis[4], ans[4];
set<int> s;

void dfs(int step)
{
	if(step == 4)
	{
		int tmp = 1000*ans[0]+100*ans[1]+10*ans[2]+ans[3];
		s.insert(tmp);
		return ;
	}
	for(int i = 0; i < 4; i++)
	{
		if(step == 0 && a[i] == 0)continue;
		if(vis[i])continue;
		vis[i] = 1;
		ans[step] = a[i];
		dfs(step+1);
		vis[i] = 0;
	}
}

int main()
{
	int pre, cnt = 0;
	while(scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]))
	{
		if(!a[0]&&!a[1]&&!a[2]&&!a[3])break;
		if(cnt)cout<<endl;
		cnt = 1;
		s.clear();
		sort(a, a+4);
		memset(vis, 0, sizeof(vis));
		dfs(0);
		for(set<int>::iterator it = s.begin(); it != s.end(); it++)
		{
			int tmp = *it;
			if(it==s.begin()){
				cout<<tmp;
				pre = tmp/1000;
			}else
			{
				if(tmp/1000 == pre)cout<<" "<<tmp;
				else {
					cout<<endl<<tmp;
					pre = tmp/1000;
				}
			}
		}
		cout<<endl;
	}

    return 0;
}
