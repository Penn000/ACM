//2016.8.3
//POJ 1011
//题意：给出n根小棒的长度stick[i]，已知这n根小棒原本由若干根长度相同的
//长木棒（原棒）分解而来。求出原棒的最小可能长度。
//
//思路：dfs+剪枝。蛮经典的题目，重点在于dfs剪枝的设计。先说先具体的实
//现：求出总长度sum和小棒最长的长度max，则原棒可能的长度必在max~sum之
//间，然后从小到大枚举max~sum之间能被sum整除的长度len，用dfs求出所有的
//小棒能否拼凑成这个长度，如果可以，第一个len就是答案。
//
//下面就是关键的了，就是这道题dfs的实现和剪枝的设计：
//1.以一个小棒为开头，用dfs看看能否把这个小棒拼凑成len长，如果可以，用
//vis[i]记录下用过的小棒，然后继续以另外一个小棒为开头，以此类推。
//2.小棒的长度从大到小排序，这个就不解释了。
//3.如果当前最长的小棒不能拼成len长，那么就返回前一步，更改前一步的最
//长小棒的组合情况（这里不能是全部退出），不用再继续搜索下去了。
//4.最重要的，就是比如说17,9,9,9,9,8,8,5,2……如果当前最长小棒为17，它与
//第一个9组合之后dfs发现不能拼成len，那么17就不用和后面所有的9组合了，
//而直接和8开始组合。这个剪枝直接从TLE到16MS，很强大。


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int n, a[70], book[70], len;
bool fg;

bool cmp(int a, int b)
{
	return a > b;
}

void dfs(int deep, int nlen, int cur)
{
	if(fg)return ;
	if(nlen == 0)
	{
		int k=0;
		while(book[k])k++;
		book[k] = 1;
		dfs(deep+1, a[k], k+1);
		book[k] = 0;
		return ;
	}else if(nlen == len)
	{
		if(deep == n)fg = true;
		else dfs(deep, 0, 0);
		return ;
	}
	for(int i = cur; i < n; i++)
	{
		if(!book[i] && nlen+a[i] <= len)
		{
			if(!book[i-1] && a[i] == a[i-1])continue;//不重复搜索，最重要的剪枝
			book[i] = 1;
			dfs(deep+1, nlen+a[i], i+1);
			book[i] = 0;
		}
	}
}

int main()
{
	int sum;
	while(cin >> n && n)
	{
		sum = 0;
		fg = false;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			sum+=a[i];
		}
		sort(a, a+n, cmp);
		for(len = a[0]; len < sum; len++)
		{
			if(sum%len==0)
			{
				memset(book, 0, sizeof(book));
				dfs(0, 0, 0);
				if(fg)break;
			}
		}
		cout << len << endl;
	}

	return 0;
}
