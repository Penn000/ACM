//2016.8.9
#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;

int fa[10005], arr[100005][2], cnt;

int getf(int i)
{
	if(fa[i]==i)return i;
	return fa[i] = getf(fa[i]);
}

int init(int n)
{
	for(int i = 0; i < n; i++)
	  fa[i] = i;
}

int Merge(int a, int b)
{
	int af = getf(a);
	int bf = getf(b);
	if(af!=bf){
	  fa[bf] = af;
	  cnt--;
	}
}

int main()
{
	int n, m, u, v;
	while(cin>>n>>m)
	{
		init(n);
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d", &arr[i][0], &arr[i][1]);
		}
		stack<int> s;
		cnt = n;
		for(int i = m-1; i >= 0; i--)
		{
			s.push(cnt);
			Merge(arr[i][0], arr[i][1]);
		}
		while(!s.empty())
		{
			int ans = s.top();
			cout<<ans<<endl;
			s.pop();
		}
	}

	return 0;
}
