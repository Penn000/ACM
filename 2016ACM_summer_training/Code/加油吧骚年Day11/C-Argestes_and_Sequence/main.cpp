//2016.8.13 
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N = 100005;
int a[N], len = 400, n, mi[15] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

struct node
{
	int cnt[12][12];//cnt[d][p]表示每个块内第d位是p的个数
}block[400];

bool judge(int x, int d, int p)//判断x的第d位是否为p
{
	return x/mi[d]%10==p;
}

int query(int l, int r, int d, int p)
{
	int id1 = l/len, id2 = r/len, ans = 0;
	if(id1==id2)//如果l,r在同一个块内，暴力枚举
	{
		for(int i = l; i <= r; i++)
		  	if(judge(a[i], d, p))
			  	ans++;
	}else
	{
		for(int i = id1+1; i <= id2-1; i++)//把中间的块加起来
		  ans+=block[i].cnt[d][p];
		for(int i = l; i <= (id1+1)*len && i <= n; i++)//暴力最左边的块
		  if(judge(a[i], d, p))
			ans++;
		for(int i = id2*len+1; i <= r; i++)//暴力最右边的块
		  if(judge(a[i], d, p))
			ans++;
	}
	return ans;
}

void update(int x, int y)
{
	int tmp = a[x], id = (x-1)/len;//这里起初x少减了个1，WA了好多次忧伤。。。
	a[x] = y;
	for(int i = 1; i <= 10; i++)
	{
		block[id].cnt[i][tmp%10]--;
		tmp/=10;
	}
	tmp = a[x];
	for(int i = 1; i <= 10; i++)
	{
		block[id].cnt[i][tmp%10]++;
		tmp/=10;
	}
}

int main()
{
	int T, d, p, m, x, y, l, r, id;
	char cmd;
//	for(int i = 1; i <= 10; i++)
//	  cout<<mi[i]<<endl;
	cin>>T;
	while(T--)
	{
		scanf("%d%d", &n, &m);
		memset(block, 0, sizeof(block));
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; i++)
		{
		    scanf("%d", &a[i]);
			id = (i-1)/len;
			int tmp = a[i];
			for(int j = 1; j <= 10; j++)//初始化块
			{
				block[id].cnt[j][tmp%10]++;
				tmp/=10;
			}
		}
		while(m--)
		{
			getchar();
			scanf("%c", &cmd);
			if(cmd == 'Q')
			{
				int ans = 0;
				scanf("%d%d%d%d", &l, &r, &d, &p);
				ans = query(l, r, d, p);
				printf("%d\n", ans);
			}else
			{
				scanf("%d%d", &x, &y);
				update(x, y);
			}
		}
	}

	return 0;
}
