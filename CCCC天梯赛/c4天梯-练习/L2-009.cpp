//2017-03-19
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;
struct node{
	int id, cnt;
	double out, in;
	double fin;
	bool operator <(node x)
	{
		if(fin == x.fin)return cnt > x.cnt;
		return fin > x.fin;
	}
}man[N];

int main()
{
	int n, k;
	while(cin>>n)
	{
		for(int i = 1; i <= n; i++)
		{
			man[i].in = 0;
			man[i].out = 0;
			man[i].cnt = 0;
		}
		for(int i = 1; i <= n; i++)
		{
			man[i].id = i;
			cin>>k;
			int id, monky;
			while(k--)
			{
				cin>>id>>monky;
				man[id].in += monky;
				man[i].out += monky;
				man[id].cnt++;
			}
		}
		for(int i = 1; i <= n; i++)
		  	man[i].fin = (man[i].in-man[i].out)/100;
		sort(man+1, man+n+1);
		for(int i = 1; i <= n; i++)
		  	printf("%d %.2lf\n", man[i].id, man[i].fin);
	}

    return 0;
}
