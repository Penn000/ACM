//2016.8.2
//http://acm.hust.edu.cn/vjudge/contest/125415#problem/C
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int S(int x)
{
	int ans = 0;
	while(x)
	{
		ans += x%10;
		x /= 10;
	}
	return ans;
}

long long pow(int a, int b)
{
	long long ans = 1;
	while(b--)
	{
		ans *= a;
	}
	return ans;
}

int main()
{
	int a, b, c;
	long long x;
	while(scanf("%d%d%d", &a, &b, &c)!=EOF)
	{
		vector<long long> v;
		for(int i = 1; i <= 81; i++)
		{
			x = b*pow(i, a)+c;
			if(x >= 1000000000 || x < 0)continue;
			if(S(x)==i)v.push_back(x);
		}
		cout << v.size()<<endl;
		if(!v.empty())
			for(vector<long long>::iterator it = v.begin(); it != v.end(); it++)
				if(it == v.begin())cout<<*it;
				else cout << " " << *it;
  	    cout << endl;
	}
	return 0;
}
