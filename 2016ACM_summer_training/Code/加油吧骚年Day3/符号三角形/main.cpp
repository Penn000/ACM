#include<iostream>

using namespace std;

int a[26][26];int n, half;
long long sum = 0;
int cnt;

void Backtrace(int t)
{
	if(t > n)sum++;
	else 
	{
		for(int i = 0; i < 2; i++)//"-"为1，“+”为0
		{
			a[1][t] = i;
			cnt += i;
			for(int j = 2; j <= t; j++)
			{
				a[j][t-j+1] = a[j-1][t-j+1]^a[j-1][t-j+2];
				cnt += a[j][t-j+1];
			}
			if(cnt <= half && (t*(t+1)/2-cnt) <= half)
			{
				Backtrace(t+1);
			}
			for(int j = 2; j <= t; j++)
			  cnt -= a[j][t-j+1];
			cnt-=i;
		}
	}
}

int main()
{
	while(cin>>n)
	{
		sum = 0;
		cnt = 0;
		half = n*(n+1)/2;
		if(half%2 == 0)
		{
			half /= 2;
			Backtrace(1);
		}
		cout << sum <<endl;
	}

	return 0;
}
