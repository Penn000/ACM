//2016.8.12
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 100005;
const int inf = 0x3f3f3f3f;
int root , tot, pre[N], key[N], child[N][2];//分别表示根节点、节点总数、父节点、键值、孩子(左0右1)

void NewNode(int &r, int father, int k)//创建新节点
{
	r = ++tot;
	pre[r] = father;
	key[r] = k;
	child[r][0] = child[r][1] = 0;//叶子节点，孩子为空
}

void Rotato(int x, int kind)//旋转，kind为1则右旋，为0则左旋
{
	int y = pre[x];
	child[y][!kind] = child[x][kind];
	pre[child[x][kind]] = y;
	if(pre[y])
	  child[pre[y]][child[pre[y]][1]==y] = x;
	pre[x] = pre[y];
	child[x][kind] = y;
	pre[y] = x;
}

void Splay(int r, int goal)//Splay调整，将r节点调到goal节点下面
{
	while(pre[r] != goal)
	{
		if(pre[pre[r]]==goal)
		  Rotato(r, child[pre[r]][0]==r);
		else
		{
			int y = pre[r];
			int kind = child[pre[y]][0]==y;
			if(child[y][kind] == r)
			{
				Rotato(r, !kind);
				Rotato(r, kind);
			}else
			{
				Rotato(y, kind);
				Rotato(r, kind);
			}
		}
	}
	if(goal == 0)root = r;//更新根节点
}

int ins(int k)//插入
{
	int r = root;
	while(child[r][key[r]<k])
	{
		if(key[r] == k)//不重复插入
		{
			Splay(r, 0);
			return 0;
		}
		r = child[r][key[r]<k];
	}
	NewNode(child[r][key[r]<k], r, k);
	Splay(child[r][key[r]<k], 0);
	return 1;
}

int get_pre(int x)//找前驱
{
	int tmp = child[x][0];
	if(tmp==0)return inf;
	while(child[tmp][1])
	{
		tmp = child[tmp][1];
	}
	return key[x]-key[tmp];
}

int get_next(int x)//找后继
{
	int tmp = child[x][1];
	if(tmp==0)return inf;
	while(child[tmp][0])
	{
		tmp = child[tmp][0];
	}
	return key[tmp]- key[x];
}

int main()
{
	int n, ans, num;
	while(cin>>n)
	{
		root = tot = ans = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &num);
		//	if(scanf("%d", &num)==EOF)num = 0;
			if(i==0)
			{
				ans+=num;
				NewNode(root, 0, num);
				continue;
			}
			if(ins(num)==0)continue;
			int l = get_pre(root);
			int r = get_next(root);
			ans+=min(l, r);
		}
		printf("%d\n", ans);
	}

	return 0;
}
