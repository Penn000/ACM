//2016.8.9
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

struct node
{
	int fa, relation;
}a[50005];

int getfa(int i)
{
	if(a[i].fa==i)return i;
	int tmp = a[i].fa;
	a[i].fa = getfa(tmp);
	a[i].relation = (a[i].relation+a[tmp].relation)%3;
	return a[i].fa;
}

int main()
{
	int n, k, d, x, y, ans, root1, root2;
	cin>>n>>k;
	{
		ans = 0;
		for(int i = 1; i <= n; i++)
		{
			a[i].fa = i;
			a[i].relation = 0;
		}
		while(k--)
		{
			scanf("%d%d%d", &d, &x, &y);
			if(x>n||y>n){
				ans++; continue;
			}
			if(d==2&&x==y){
				ans++; continue;
			}
			root1 = getfa(x);
			root2 = getfa(y);
			if(root1!=root2)
			{
				a[root2].fa = root1;
				a[root2].relation = (3+d-1+a[x].relation-a[y].relation)%3;
			}
			else
			{
				if((d==1&&a[x].relation!=a[y].relation)||(d==2&&((3-a[x].relation+a[y].relation)%3!=d-1)))
				{
					ans++; continue;
				}
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
