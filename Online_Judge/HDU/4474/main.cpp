//2016.9.5
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#define N 10005

using namespace std;

bool vis[N], del[10];//vis表示是否访问过，del表示不能出现的数字
int n, m, pre[N];
char text[N];//最后输出的数组

bool bfs()
{
	queue<int> q;
	q.push(0);
	int cur;
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		for(int i = 0; i < 10; i++)
		{
			if(del[i]==true||cur==0&&i==0)continue;//不符合要求
			int mod = (cur*10+i)%n;
			if(vis[mod])continue;//剪枝
			text[mod] = '0'+i;
			vis[mod] = true;
			pre[mod] = cur;//记录上一个节点
			q.push(mod);
			if(mod == 0)return true;
		}
	}
	return false;
}

void print()//打印路径
{
	string ans;
	int pos = 0;
	while(pos!=0 || ans.empty())
	{
		ans += text[pos];
		pos = pre[pos];
	}
	reverse(ans.begin(), ans.end());//翻转，输出
	puts(ans.c_str());
}

int main()
{
	int kase = 0, x;
	while(scanf("%d%d", &n, &m)!=EOF)
	{
		memset(vis, 0, sizeof(vis));
		memset(del, 0, sizeof(del));
		for(int i = 0; i < m; i++)
		{
			scanf("%d", &x);
			del[x] = true;
		}
		printf("Case %d: ", ++kase);
		if(!bfs())printf("-1\n");
		else print();
	}

    return 0;
}
